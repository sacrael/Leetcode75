#ifndef PROBLEM_3
#define PROBLEM_3

/// <summary>
/// Problem: Contains Duplicate
/// https://leetcode.com/problems/contains-duplicate/submissions/
/// </summary>

#include <iostream>
#include <vector>
#include <unordered_set>

void printArr(std::vector<int>& vec);
class Problem3 {
public:

	bool containsDuplicate(std::vector<int>& nums) {
		std::unordered_set<int> set_;
		for (int i = 0; i < nums.size(); ++i) {
			if (set_.find(nums[i]) != set_.cend()) return true;
			set_.insert(nums[i]);
		}
		return false;
	}

	void runContainsDuplicate() {
		std::cout << "Contains Duplicate\n";

		int size_;
		std::cout << "How many numbers are in the array?\n";
		std::cin >> size_;

		std::vector<int> arr;

		for (int i = 0; i < size_; ++i) {
			int val_;
			std::cout << "\tIndex " << i << ": ";
			std::cin >> val_;
			arr.push_back(val_);
		}

		printArr(arr);
		bool result = this->containsDuplicate(arr);
		if (result) std::cout << "Array does contain duplicates\n";
		else std::cout << "Array does NOT contain dupicates\n";

	}

	void runSolution() {
		this->runContainsDuplicate();
	}
};

#endif