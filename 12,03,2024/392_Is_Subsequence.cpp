#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution
{
private:
    string s1;
    string s2;
public:
    solution(string s1 , string s2) : s1(s1), s2(s2) {}

    bool isSubsequence() {
        int index_l = 0 ;
        bool res = false;
        s2+='0';
        if (s1.size() == 0 ){
            return true;
        } else if (s2.size() == 0 ){
            return false;
        }
        for(char l : s1 ){
            for (index_l ; index_l < s2.size(); index_l++){
                // cout << index_l << ":" << res << " , ";
                if(s2[index_l] == l){
                    index_l ++;
                    res = true;
                    cout << index_l << ":" << res << " , ";

                    break;
                }
                res = false;
            }            
        }
        return res;
        
    }


};

int main(){
    string s = "acb", t = "ahbgdc";
    solution solution(s, t);
    cout << solution.isSubsequence();
    return 0;
}




