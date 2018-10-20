#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <vector>
#include <unordered_map>

class Solution {
public:
  std::vector<int> twoSum(const std::vector<int>& nums, const int& target) {
    std::unordered_map<int, int> complements;
    for (int i = 0; i < nums.size(); ++i) {
      int complement = target - nums[i];
      if (complements.count(complement) > 0) {
        return {complements.at(complement), i};
      }
      complements.emplace(nums[i], i);
    }
    return {0, 0};
  }
};

TEST_CASE("Empty input") {
  Solution s;
  const std::vector<int> input{};
  const int target = 1;
  const std::vector<int> expected{0,0};
  std::vector<int> result = s.twoSum(input, target);
  CHECK(result == expected);
}

TEST_CASE("One element input") {
  Solution s;
  const std::vector<int> input{100};
  const int target = 100;
  const std::vector<int> expected{0,0};
  std::vector<int> result = s.twoSum(input, target);
  CHECK(result == expected);
}

TEST_CASE("Two elements input") {
  Solution s;
  const std::vector<int> input{3,7};
  const int target = 10;
  const std::vector<int> expected{0,1};
  std::vector<int> result = s.twoSum(input, target);
  CHECK(result == expected);
}

TEST_CASE("SuperLongInput") {
  Solution s;
  const std::vector<int> input{3,4,1,6,1,2,3,10,50,2,31,4,3};
  const int target = 60;
  const std::vector<int> expected{7, 8};
  std::vector<int> result = s.twoSum(input, target);
  CHECK(result == expected);
}

TEST_CASE("Negative numbers") {
  Solution s;
  const std::vector<int> input{-15, -5, -8, -15};
  const int target = -30;
  const std::vector<int> expected {0, 3};
  std::vector<int> result = s.twoSum(input, target);
  CHECK(result == expected);
}

TEST_CASE("No solution") {
  Solution s;
  const std::vector<int> input{15, -15};
  const int target = 2;
  const std::vector<int> expected {0, 0};
  std::vector<int> result = s.twoSum(input, target);
  CHECK(result == expected);
}

