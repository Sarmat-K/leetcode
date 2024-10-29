// Solution for problem 4 : Median of two sorted arrays
// Difficulty: Hard
// Topics: Array , Binary search, Divide and conquer 

// Your solution code goes here.
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums2.size() < nums1.size()){
        return findMedianSortedArrays(nums2 , nums1);
    }

    int min_array = nums1.size();
    int max_array = nums2.size();
    int l = 0 , r = min_array;
    while(l <= r){
        int mid_min = (l + r)/ 2;
        int mid_max = (min_array + max_array + 1) / 2 - mid_min;

        int maxX = (mid_min == 0) ? INT_MIN : nums1[mid_min - 1];
        int minX = (mid_min == min_array) ? INT_MAX : nums1[mid_min];

        int maxY = (mid_max == 0) ? INT_MIN : nums2[mid_max - 1];
        int minY = (mid_max == max_array) ? INT_MAX : nums2[mid_max];

        if(maxX <= minY && maxY <= minX){
            if((min_array+max_array) % 2 == 0){
                return (max(maxX, maxY) + min(minX, minY)) / 2.0;
            }else{
                return(max(maxX,maxY));
            }
        }else if (maxX > minY){
            r = mid_min - 1;
        }else{
            l = mid_min + 1;
        }
    }

}

int main(){

    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,4};

    cout << findMedianSortedArrays(nums1, nums2);

    return 0 ;
}