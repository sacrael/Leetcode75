#ifndef PROBLEM_8
#define PROBLEM_8

#include <vector>

void printArr(std::vector<int>& vec);
class Problem8 {

public:

	int binarySearchIndex(std::vector<int>& nums, int start, int end, int target) {
		if (end - start <= 1 && nums[start] != target) return -1;
		int mid = (int)((start + end) / 2);
		if (nums[mid] == target) return mid;
		if (nums[mid] > target) return binarySearchIndex(nums, start, mid - 1, target);
		else return binarySearchIndex(nums, mid + 1, end, target);
	}

	int findPivotIndex(std::vector<int>& nums, int start, int end) {
		if (start == end) return start;
		int mid = (int)((start + end) / 2);
		if (mid < end - 1 && nums[mid] > nums[mid + 1]) return mid;
		if (mid > start && nums[mid] < nums[mid - 1]) return mid - 1;
		if (nums[mid] >= nums[start]) return findPivotIndex(nums, mid + 1, end);
		return findPivotIndex(nums, 0, mid - 1);
	}

	int findPivotIndex(std::vector<int>& nums, int target) {
		size_t size = nums.size();
		int pivot = findPivotIndex(nums, 0, size);
		int index = binarySearchIndex(nums, 0, pivot + 1, target);
		if (index == -1) index = binarySearchIndex(nums, pivot + 1, size, target);
		return index;
	}

	void runFindPivotIndex() {
		std::cout << "Search in Rotated Sorted Array\n";

		int size_;
		std::cout << "How many numbers are in the array?\n";
		std::cin >> size_;

		std::vector<int> arr;
		int target;

		for (int i = 0; i < size_; ++i) {
			int val_;
			std::cout << "\tIndex " << i << ": ";
			std::cin >> val_;
			arr.push_back(val_);
		}

		std::cout << "What is the target value? ";
		std::cin >> target;

		std::cout << "\nFinding index of " << target << " in array:\n";
		printArr(arr);
		int res = this->findPivotIndex(arr, target);
		if (res == -1) std::cout << "Value is not in the array\n";
		else std::cout << "Value found at index " << res << std::endl;

	}

	void runSolution() {
		this->runFindPivotIndex();
	}

};

#endif