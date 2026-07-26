#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str, str1;
    cin >> str >> str1; // str = num  str1=string
    if (str.length() != str1.length())
    {
        cout << "NO\n";
        return 0;
    }
    map<char, char> forward_mp;
    map<char, char> backward_mp;
    bool ok = true;
    for (int i = 0; i < str.length(); i++)
    {
        char c1 = str[i];
        char c = str1[i];

        if (forward_mp.count(c1) && forward_mp[c1] != c)
        {
            ok = false;
            break;
        }
        if (backward_mp.count(c) && backward_mp[c] != c1)
        {
            ok = false;
            break;
        }
        forward_mp[c1] = c;
        backward_mp[c] = c1;
    }
    if (ok)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
