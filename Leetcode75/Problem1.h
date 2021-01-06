#ifndef PROBLEM_1
#define PROBLEM_1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

#include "Solution.h"

class Problem1 : public Solution {

public:

	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		// Linear Solution
		std::unordered_map<int, int> seen;

		int i = 0;
		std::unordered_map<int, int>::const_iterator itr;
		while (i < nums.size()) {

			// If the number we need to meet target is in the map,
			// return that number's index and the current index
			if ((itr = seen.find(target - nums[i])) != seen.cend()) {
				return std::vector<int> {itr->second, i};
			}

			// Add the current index and value into the unordered map "seen"
			seen[nums[i]] = i;

			++i;
		}

		// no solution found -- default
		return std::vector<int> {0, 0};
	}

	void runTwoSum() {
		std::cout << "Two Sum\n";
		std::cout << "How many numbers are in your array? " << std::endl;

		int num_size;
		std::cin >> num_size;
		std::vector<int> nums;

		for (int i = 0; i < num_size; ++i) {
			int val_;
			std::cout << "\tNum " << i << ": ";
			std::cin >> val_;
			nums.push_back(val_);
		}

		std::cout << "What is the target number? " << std::endl;
		int target;
		std::cin >> target;

		// Get the result
		std::vector<int> answer = this->twoSum(nums, target);

		if (answer.size() != 2) {
			std::cerr << "Error: Invalid solution format\n";
			return;
		}

		std::cout << nums[answer[0]] << " + " << nums[answer[1]] << " = " << (nums[answer[0]] + nums[answer[1]]) << "\n";
		if (nums[answer[1]] + nums[answer[0]] == target)	std::cout << "Correct answer" << std::endl;
		else												std::cout << "Incorrect answer" << std::endl;

		assert(nums[answer[0]] + nums[answer[1]] ==  target);
	}

	int runSolution() override {
		this->runTwoSum();
		return IMPLEMENTED;
	}

};

#endif