#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    std::vector<int> nums = {5, 3, 8, 1};

    std::sort(nums.begin(), nums.end(),
        [](int a , int b) { return a>b;}
    );

    for(auto n: nums) {
        std::cout << n << std::endl;
    }

    return 0;
}