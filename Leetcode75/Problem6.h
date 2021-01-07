#ifndef PROBLEM_6
#define PROBLEM_6

#include <vector>
#include <iostream>

void printArr(std::vector<int>& vec);
class Problem6 {

public:

	int maximumProductSubarray(std::vector<int>& nums) {
		size_t size = nums.size();
		int curr_min = nums[0], curr_max = nums[0];
		int answer = nums[0];

		for (size_t i = 1; i < size; ++i) {
			curr_min *= nums[i];
			curr_max *= nums[i];

			int new_min, new_max;
			new_min = std::min(curr_min, std::min(curr_max, nums[i]));
			new_max = std::max(curr_min, std::max(curr_max, nums[i]));
			curr_min = new_min; curr_max = new_max;

			answer = std::max(answer, curr_max);
		}
		return answer;
	}

	void runMaximumProductSubarray() {
		std::cout << "Maximum Product Subarray\n";
		std::cout << "What is the size of the array? ";
		int size_;
		std::cin >> size_;

		std::vector<int> arr;
		for (int i = 0; i < size_; ++i) {
			int val_;
			std::cout << "\tIndex " << i << ": ";
			std::cin >> val_;
			arr.push_back(val_);
		}

		std::cout << "Array: " << std::endl;
		printArr(arr);
		int max_ = this->maximumProductSubarray(arr);
		std::cout << "Maximum Product SUbarray value: " << max_ << std::endl;

	}

	void runSolution() {
		this->runMaximumProductSubarray();
	}

};

#endif