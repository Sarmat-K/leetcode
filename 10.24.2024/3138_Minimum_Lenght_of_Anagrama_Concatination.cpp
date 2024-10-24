// Solution for problem 3138: Minimum Lenght of Anagrama Concatination
// Difficulty: Medium
// Topics: Hash table, String, Concatenation

// Your solution code goes here.

#include <iostream> 
 #include <vector>
 #include <algorithm>
 #include <unordered_map>

 using namespace std;

 bool areaAnagrams (const string& str ,  int d){
    unordered_map<char, int> table;

    for(int i = 0; i < d; i++){
        table[str[i]]++;
    }

    for(int i = 0 ;i < str.size(); i+= d){
        unordered_map<char , int> temp_table;
        for(int j = i; j < i+d; j++){
            temp_table[str[j]]++;
        }
        if(table != temp_table)
            return false;
    }
    return true;
 }


 int min_lenght_of_Anagrama(string s){
    int n=s.length();

    for(int i = 1; i <= n ; i++){
        if(n % i == 0){
            if(areaAnagrams(s,i))
                return i;
        }
    }
    return n;
 }

int main(){

    string s = "abba";

    cout << min_lenght_of_Anagrama(s)<< endl;

    return 0 ;
}