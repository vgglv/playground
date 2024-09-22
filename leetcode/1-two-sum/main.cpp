#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i=0; i<nums.size(); i++) {
            int diff = target - nums[i];
            if (map.contains(diff)) {
                return {map[diff], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};

void runCase(std::vector<int> nums, const std::vector<int>& expectedResults, int target) {
    Solution sol;
    auto actualResults = sol.twoSum(nums, target);
    if (expectedResults.size() != actualResults.size()) {
        std::cout << "Case failed. Vectors not equal.\n";
        return;
    }
    bool isEqual = std::equal(expectedResults.begin(), expectedResults.end(), actualResults.begin());
    if (!isEqual) {
        std::cout << "Case failed. Vectors not equal\n";
        {
            std::cout << "Expected results:\n";
            std::for_each(expectedResults.begin(), expectedResults.end(), [](int value) {
                std::cout << value << "; ";
            });
            std::cout << "\n";
        }
        {
            std::cout << "Actual results:\n";
            std::for_each(actualResults.begin(), actualResults.end(), [](int value) {
                std::cout << value << "; ";
            });
            std::cout << "\n";
        }
        return;
    }
    std::cout << "Success!\n";
}

int main() {
    std::cout << "Running case 1...\n";
    runCase({2, 7, 11, 15}, {0, 1}, 9);

    std::cout << "Running case 2...\n";
    runCase({3, 2, 4}, {1, 2}, 6);

    std::cout << "Running case 3...\n";
    runCase({3, 3}, {0, 1}, 6);
    return 0;
}