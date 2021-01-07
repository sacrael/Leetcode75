#ifndef PROBLEM_4
#define PROBLEM_4

#include <vector>

void printArr(std::vector<int>& vec);
class Problem4 {
public:

	std::vector<int> productExceptSelf(std::vector<int>& nums) {

		// 2. Two Iteration
		std::vector<int> left_side;
		std::vector<int> right_side;

		right_side.resize(nums.size());
		for (int i = 0; i < nums.size(); ++i) {

			// first iteration: calculate the product on the left sides
			if (i == 0) left_side.push_back(1);
			else left_side.push_back(left_side[i - 1] * nums[i - 1]);

			// second iteration: calculate the product on the right side
			int j = nums.size() - 1 - i;
			if (j == nums.size() - 1) right_side[j] = 1;
			else right_side[j] = right_side[j + 1] * nums[j + 1];
		}

		std::vector<int> products;
		// now, multiply the value in right_side and left_side
		for (int i = 0; i < nums.size(); ++i) {
			products.push_back(left_side[i] * right_side[i]);
		}
		return products;
	}

	void runProductExceptSelf() {
		std::cout << "Product of Array Except Self\n";
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

		std::cout << "Array: \n";
		printArr(arr);

		std::vector<int> result = this->productExceptSelf(arr);
		std::cout << "Product except self: \n";
		printArr(result);

	}

	void runSolution() {
		this->runProductExceptSelf();
	}
};

#endif