#ifndef PROBLEM_2
#define PROBLEM_2

#include <iostream>
#include <vector>

class Problem2 {

public:

	int maxProfit(std::vector<int>& prices) {
		if (prices.size() == 0) return 0;
		int min_price = prices[0];
		int max_price = 0;

		for (int i = 0; i < prices.size(); ++i) {
			if (prices[i] < min_price) min_price = prices[i];
			if (prices[i] - min_price > max_price)
				max_price = prices[i] - min_price;
		}

		return max_price;
	}

	void runMaxProfit() {
		std::cout << "Best Time to Buy and Sell Stock\n";
		std::cout << "How many numbers are in your array? " << std::endl;

		int num_size;
		std::cin >> num_size;
		std::vector<int> nums;

		for (int i = 0; i < num_size; ++i) {
			int val_;
			std::cout << "\tNumber " << i << ": ";
			std::cin >> val_;
			nums.push_back(val_);
		}

		int best_price = this->maxProfit(nums);
		std::cout << "Max profit is $" << best_price << std::endl;
	}

	void runSolution () {
		this->runMaxProfit();
	}

};

#endif