#ifndef PROBLEM_7
#define PROBLEM_7

class Problem7 {

public:
	
	int findMin(std::vector<int>& nums) {
		int min = nums[0];
		int size = nums.size();
		for (size_t i = 1; i < size; ++i) {
			if (nums[i] < min) return nums[i];
		}
		return min;
	}

	void runFindMin() {
		std::cout << "Find Minimum in Rotated Sorted Subarray\n";
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
		std::cout << "Min: " << this->findMin(arr) << std::endl;

	}

	void runSolution() {
		this->runFindMin();
	}
};

#endif