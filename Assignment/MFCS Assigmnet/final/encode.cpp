#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char ch = '\0';
    int freq;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(char ch, int freq) : ch(ch), freq(freq) {}
    Node(int freq, Node *left, Node *right) : freq(freq), left(left), right(right) {}
};

Node *BuildHuffmanTree(const unordered_map<char, int> &freq)
{
    // min heap
    function<bool(Node *, Node *)> ff = [&](Node *a, Node *b)
    {
        return a->freq > b->freq;
    };
    priority_queue<Node *, vector<Node *>, decltype(ff)> mh(ff);

    for (auto it : freq)
        mh.push(new Node(it.first, it.second));

    while (mh.size() > 1)
    {
        Node *n1 = mh.top();
        mh.pop();
        Node *n2 = mh.top();
        mh.pop();

        mh.push(new Node(n1->freq + n2->freq, n1, n2));
    }
    return mh.top();
}

void assign_bit_length(Node *node, int l, vector<pair<int, char>> &a)
{
    if (node->ch != '\0')
        a.emplace_back((l == 0) ? 1 : l, node->ch);
    else
    {
        assign_bit_length(node->left, l + 1, a);
        assign_bit_length(node->right, l + 1, a);
    }
}

string add_one(string s)
{
    // no input as all one ;
    int i = s.size() - 1;
    while (s[i] == '1')
        s[i--] = '0';
    if (i >= 0)
        s[i] = '1';
    else
        s = '1' + s;
    return s;
}

int main(int argc, char *argv[])
{
    /* read the file as command line argument*/
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << endl;
        return 1;
    }

    string input_file = argv[1];
    int zz = input_file.find_last_of("/\\");
    string output_file = ((zz == -1) ? input_file : input_file.substr(zz + 1, input_file.size() - 5 - zz)) + "_compressed.bin";

    ifstream inFile(input_file); // open file for char by char reading
    if (!inFile)
    {
        cerr << "Error: Could not open the file : " << argv[1] << endl;
        return 1;
    }

    unordered_map<char, int> frequency;
    char ch;
    while (inFile.get(ch))
        frequency[ch]++; // make frequency table
    inFile.close();

    Node *root = BuildHuffmanTree(frequency); // build huffman tree

    // assign bit length to char ;
    vector<pair<int, char>> a; // bit length
    assign_bit_length(root, 0, a);
    sort(a.begin(), a.end());

    // write cannonical form
    unordered_map<char, string> code;
    string last = "";
    for (int i = 0; i < a.size(); i++)
    {
        if (i)
            last = add_one(last);
        last.resize(a[i].first, '0');
        code[a[i].second] = last;
    }

    // meta data
    int TotalChar = root->freq;
    int TotalDiffChar = a.size();
    // bit lengh

    // open optput file
    ofstream outFile(output_file, ios::binary);
    if (!outFile.is_open())
    {
        cerr << "Error: Could not open the file : " << output_file << endl;
        return 1;
    }
    inFile.open(input_file);
    if (!inFile.is_open())
    {
        cerr << "Error: Could not open the file : " << input_file << endl;
        return 1;
    }
    // write meta data
    outFile.write(reinterpret_cast<const char *>(&TotalChar), sizeof(TotalChar));
    outFile.write(reinterpret_cast<const char *>(&TotalDiffChar), sizeof(TotalDiffChar));
    for (auto it : a)
    {
        outFile.write(reinterpret_cast<const char *>(&it.first), sizeof(it.first));
        outFile.write(&it.second, sizeof(it.second));
    }

    // write content
    int ch_cnt = 0;
    string curr = "";
    while (inFile.get(ch))
    {
        ch_cnt++;
        curr += code[ch];

        while (curr.size() >= 8)
        {

            unsigned char c = 0;
            for (int i = 0; i < 8; i++)
                c = ((c << 1) | ((curr[i] == '1') ? 1 : 0));
            outFile.write(reinterpret_cast<const char *>(&c), sizeof(c));
            if (curr.size() != 8)
                curr = curr.substr(8);
            else
                curr = "";
        }
    }
    if(curr.size() != 0)
    {
        curr.resize(8, '0');
        unsigned char c = 0;
        for (int i = 0; i < 8; i++)
            c = ((c << 1) | ((curr[i] == '1') ? 1 : 0));
        outFile.write(reinterpret_cast<const char *>(&c), sizeof(c));
    }
    assert(ch_cnt == TotalChar);
    outFile.close();
    inFile.close();

    
    cout << "File Compressed Successfully.." << endl;
    cout << "Compressed File : " << output_file << endl;
    return 0;
}
