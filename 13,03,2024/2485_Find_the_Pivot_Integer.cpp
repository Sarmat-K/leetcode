#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class solution
{
private:
    int num ;
public:
    solution(int n) : num(n) {}

    // int pivotInteger() {
    //     vector<int> r_sum = {num} ,  l_sum = {0};
    //     for (int i = 1 , j = num - 1 ; i <= num  ; i++, j--){
    //         printf("%d -  L : %d  R : %d \n" , i ,l_sum[i-1], r_sum[i-1] );
    //         l_sum.push_back( l_sum[i-1] + i);
    //         r_sum.push_back( r_sum[i-1] + j);
    //     }

    //     for (int i = 0 , j = num  ; i <= num  ; i++, j--){
    //         if (l_sum[i] == r_sum [j])
    //             return i+1;
    //     }
    //     return -1;
    // }

    int pivotInteger() {
        for(int i=1;i<=num;i++){
             printf("%d -  L : %d  R : %d \n" , i ,((i*(i+1))/2 ), (num*(num+1))/2-( (i*(i+1))/2)+i );
            if( ((i*(i+1))/2 )== (num*(num+1))/2-( (i*(i+1))/2)+i)
                return i;
        }
        return -1;
    }
};





int main() {

    int n = 8;
    solution solution(n);
    cout << solution.pivotInteger();

    return 0;
}