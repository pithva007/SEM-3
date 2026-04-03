#include <bits/stdc++.h>
using namespace std;

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

string CharToBinary(char c)
{
    return bitset<8>(c).to_string();
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << endl;
        return 1;
    }
    string input_file = argv[1];
    int zz = input_file.find_last_of("/\\");
    string output_file = ((zz == -1) ? input_file : input_file.substr(zz + 1, input_file.size() - 16 - zz)) + "_original.txt";

    // read metadata
    ifstream inFile(input_file, ios::binary);
    if (!inFile)
    {
        cerr << "Error: Could not open the file : " << input_file << endl;
        return 1;
    }
    int TotalChar, TotalDiffChar;
    inFile.read(reinterpret_cast<char *>(&TotalChar), sizeof(TotalChar));
    inFile.read(reinterpret_cast<char *>(&TotalDiffChar), sizeof(TotalDiffChar));

    // read and make cannonical code;
    unordered_map<string, char> code;
    string last = "";

    for (int i = 0; i < TotalDiffChar; i++)
    {
        if (i)
            last = add_one(last);
        int l;
        char c;
        inFile.read(reinterpret_cast<char *>(&l), sizeof(l));
        inFile.read(&c, sizeof(c));
        last.resize(l, '0');
        code[last] = c;
    }

    // open filr for writing
    ofstream outFile(output_file);
    if (!outFile.is_open())
    {
        cerr << "Error: Could not open the file : " << output_file << endl;
        return 1;
    }
    // read content
    int ch_cnt = 0;
    char c;
    string curr = "";
    while (inFile.read(&c, sizeof(c)))
    {
        curr += CharToBinary(c);
        int j = 0;
        string xx = "";
        while (j != curr.size())
        {
            xx += curr[j++];
            if (code.find(xx) != code.end())
            {
                outFile << code[xx];
                ch_cnt++;
                if (ch_cnt == TotalChar)
                    break;
                if (j == curr.size())
                    curr = "";
                else
                    curr = curr.substr(j);
                xx = "";
                j = 0;
            }
        }
        if (ch_cnt == TotalChar)
            break;
    }
    cout << ch_cnt << " " << TotalChar << endl;
    assert(ch_cnt == TotalChar);
    cout << "File Decoded Successfully.." << endl;
    cout << "Decoded File : " << output_file << endl;
    return 0;
}
