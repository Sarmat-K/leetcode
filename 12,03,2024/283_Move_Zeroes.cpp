#include <iostream>
#include <vector>


using namespace std;

class solution
{
private:
    vector<int> array;
public:
    solution(vector<int>& nums) : array{nums}{}

    void moveZeroes() {
        int  size = array.size();
        for (int i = 0; i < size  ; i++){      
            if (array[i]== 0){
                array.push_back(0);
                array.erase(array.begin() + i);
                i--;
                size--;
            }
        }
    }

    void Print() {
        for (int i = 0; i < array.size(); i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

};

int main(){

    vector <int> nums = {0,0,1};
    solution s(nums);
    s.moveZeroes();
    s.Print();
    return 0;
}




