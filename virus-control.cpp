#include <iostream>
#include<string>

using namespace std;

string removeSubString(string str, const string& substr) {
    size_t pos = 0;
    while ((pos = str.find(substr, pos)) != string::npos)
    {// the while loop makes sure all the occurences of the substring are removed
        str.replace(pos, substr.length(), ""); // '' indicates that we don't replace the string with anything, we just remove it 
    }
    return str;
}


int main() {
    string s;
    getline(cin, s);
    // cin.ignore();
    size_t originalLenOfStr = s.length();
    int daysCount = 0;

    s = removeSubString(s, "#");

    for (int i = 0; i <= (int)s.length(); ++i)
    {
        s = removeSubString(s, "LR");
        if (s.length() < originalLenOfStr)
            ++daysCount;
    }

    if (s.length() == 0)
        cout << daysCount;
    else
        cout << "Unfortunately We are doomed!";
    return 0;
}
