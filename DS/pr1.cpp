#include<bits/stdc++.h>
using namespace std;

bool anagram(string s1,string s2)
{
	if(s1.length()!=s2.length()) return false;

	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

int main()
{
	int n;
	cin>>n;
	string words[n];

    for (int i = 0; i < n; i++) {
        cout << "Word " << i + 1 << ": ";
        cin >> words[i];
    }
    srand(time(0));
    int random = rand() % n;

    string selected = words[random];
    cout << "\nYour word is: " << selected << endl;

    string usrword;
    cout << "Enter the anagram of the above word: ";
    cin >> usrword;
    cout<<endl;

    if (anagram(selected, usrword)) 
    
        cout << "Correct! '" << endl << usrword << "' is an anagram of '" << selected << "'." << endl;
    else 
        cout << "Wrong! '" << endl << usrword << "' is NOT an anagram of '" << selected << "'." << endl;


    return 0;
}
