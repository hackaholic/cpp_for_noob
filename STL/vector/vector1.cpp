#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    vector<int> nums;

    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);

    for(int i=0;i< nums.size();i++) std::cout << nums[i] << std::endl;

    return 0;
}