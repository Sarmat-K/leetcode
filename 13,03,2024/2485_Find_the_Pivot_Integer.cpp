#include <iostream>
#include <vector>







int main() {

    std::vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    

    std::vector<int> prefixSums(n, 0);
    

    prefixSums[0] = arr[0]; 
    for (int i = 1; i < n; ++i) {
        prefixSums[i] = prefixSums[i - 1] + arr[i];
    }
    

    std::cout << "Префиксные суммы: ";
    for (int i = 0; i < n; ++i) {
        std::cout << prefixSums[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}