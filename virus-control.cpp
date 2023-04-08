#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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
    cin >> s;
    cin.ignore();
    size_t originalLenOfStr = s.length();
    int daysCount;
    
    for(int i = 0; i < s.length(); ++i)
    {
        removeSubString(s, "LR");
        removeSubString(s, '#');
        if(s.length() < originalLenOfStr)
            ++daysCount;
    }
    return 0;
}
