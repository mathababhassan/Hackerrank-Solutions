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


    for (int i = 0; i <= (int)s.length(); ++i)
    {
        if (s.find("LR") == string::npos && s.find('#') != string::npos)
        {
            s = removeSubString(s, "#");
            ++daysCount;
        }
        else if ((s.find("LR")) != string::npos && s.find('#') != string::npos)
        {
            s = removeSubString(s, "#");
            s = removeSubString(s, "LR");
            ++daysCount;

        }
        else
        {
            s = removeSubString(s, "#");
            s = removeSubString(s, "LR");
            if (s.length() < originalLenOfStr)
                ++daysCount;
        }
        // the problem with this code is that it adds days even if the string is empty from # solved 
        // and doesn't add any day if the string removes only #'s in the first day test case: ###L###R##
    }

    if (s.length() == 0)
        cout << daysCount;
    else
        cout << "Unfortunately We are doomed!";
    return 0;
}
