// Solution for problem 49: Group Anagramas
// Difficulty: Medium
// Topics: Array, hash table, String, Sorting

// Your solution code goes here.

#include <iostream> 
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string , vector<string>> ans;

    for(auto const& word : strs) {
        string sortedS = word;
        sort(sortedS.begin(), sortedS.end());
        ans[sortedS].push_back(word);
    }

    vector<vector<string>> result;

    for(auto word1 : ans){
        result.push_back(word1.second);
    }
    return result;
}

int main(){

    vector <string> strs = {"eat","tea","tan","ate","nat","bat"};

        vector<vector<string>> result = groupAnagrams(strs);

    // Вывод результата
    for (const auto& group : result) {
        cout << "[";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
        
