#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n; // num of word to be put in a frame
    cin >> n;
    cin.ignore();
    if(n < 0)
        return 0;
    
    string sentence; // the words that'll be put in a frame
    vector<string> words;
    getline(cin, sentence);
    
    size_t pos = 0; // short for position 
    while(pos < sentence.length())
    {
        size_t spacePos = sentence.find(' ', pos);
        if(spacePos == string::npos) 
            spacePos = sentence.length(); // we have reached the end of the sentence 
            
        // extracting the words from the sentence 
        string word = sentence.substr(pos, spacePos - pos);
        // adding the word to the vector 
        words.push_back(word);
        pos = spacePos + 1; // moving the position to the start of the next word 
    }
    
    // now I have a vector with the words to put in the frame 
    size_t maxLength = 0;
    // we want the longest word in the sentence to make the width of the frame
    
    for(size_t i = 0; i < words.size(); ++i)
    {
        if(words[i].length() > maxLength)
            maxLength = words[i].length();
    }

    // drawing the frame 
    cout << string(maxLength + 4, '#') << '\n';

    for(int i = 0; i < min(n, (int)words.size()); ++i)
    {
        cout << "# " << words[i] << string(maxLength - words[i].length(), ' ') << " #\n";
    }
    cout << string(maxLength + 4, '#');
    return 0;
}
