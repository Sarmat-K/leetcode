#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class solution
{
private:
    vector<int> height;
public:
    solution(vector<int>& h) : height(h) {}

    int maxArea() {
        int left_i = 0,  right_i = height.size()-1 , max_w = 0 ;
        int min_h = 0 ,lenght = 0;
        while (left_i != right_i){
            cout <<"l="<< left_i << ":" << height[left_i] << " r=" << right_i << ":" << height[right_i];
            if (height[left_i] >= height[right_i]){
                min_h = height[right_i];
                lenght = abs(right_i - left_i) ;
                right_i-- ;
            } else {
                min_h = height[left_i];
                lenght = abs(left_i - right_i) ;
                left_i++;
            }
            cout << " h="<< min_h << " len="<< lenght << " max="<< max_w << endl;
            if (max_w < (min_h * lenght)) {
                max_w = min_h* lenght;
            }
        }

        return max_w ;
        
    }


};

int main(){
    vector<int> height  = {1,2};
    solution solution(height);
    cout << solution.maxArea();
    return 0;
}




