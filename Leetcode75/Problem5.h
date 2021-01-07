#ifndef PROBLEM_5
#define PROBLEM_5

#include <iostream>
#include <vector>

void printArr(std::vector<int>& vec);
class Problem5 {

public:

	int maximumSubarray(std::vector<int>& nums) {
		int max_sum = nums[0];
		std::vector<int> cache{ nums[0] };

		for (int i = 1; i < nums.size(); ++i) {
			cache.push_back(std::max(nums[i], cache[i - 1] + nums[i]));
			max_sum = std::max(max_sum, cache[i]);
		}

		return max_sum;
	}

	void runMaximumSubarray() {
		std::cout << "Maximum Subarray\n";
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

		std::cout << "Maximum Subarray Sum = " << this->maximumSubarray(arr) << std::endl;
	}

	void runSolution() {
		this->runMaximumSubarray();
	}
};

#endif