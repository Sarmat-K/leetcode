// Solution for problem 271: Encode and Decode string
// Difficulty: medium
// Topics: String

// Your solution code goes here.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Code{
public:

    string encode(vector<string>& strs) {
        string encode = "";
        for(const string& word : strs){
            encode += to_string(word.size()) + '@' + word;
        }
        return encode;
    }

    vector<string> decode(string s) {
        vector<string> decode;

        int i = 0;

        while(i < s.size()){

            int j = i;
            while(s[j] != '@'){
                j++;
            }
            int lenght = stoi(s.substr(i, j - i)); // забираем длтну слова 
            i = j + 1; // переход к началу строки 
            decode.push_back(s.substr(i, lenght));
            i += lenght;

        }
        return decode;

    }

};

int main(){
    Code text;
    vector<string> vec = {"apple" , "car" , "cat", "sigma"};
    string enc = text.encode(vec);
    cout << enc << endl;

    vector<string> dec = text.decode(enc);

    for(const string& word : dec){
        cout << word << " ";
    }
    cout << endl;

    

    return 0;
}