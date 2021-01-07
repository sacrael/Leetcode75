﻿#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"

/**
* Leetcode75
* 
* ✔ Project Goal: Go through the list of 75 leetcode problems.
* (https://www.teamblind.com/post/New-Year-Gift---Curated-List-of-Top-100-LeetCode-Questions-to-Save-Your-Time-OaM1orEU)
* ✔ Properly document the process used to solve the problem.
*/

int main(int argc, char* argv) {

	int problem_number;
	printf("Welcome to Leetcode75\nEnter the problem number to run: ");
	std::cin >> problem_number;

	printf("Problem: #%d\n", problem_number);

	switch (problem_number) {
		case 1:
		{
			Problem1 problem_1;
			problem_1.runSolution();
			break;
		}
		case 2:
		{
			Problem2 problem_2;
			problem_2.runSolution();
			break;
		}
		case 3:
		{
			Problem3 problem_3;
			problem_3.runSolution();
			break;
		}
		default:
			printf("Solution for problem %d not implemented.", problem_number);
	}

	return EXIT_SUCCESS;
}

void printArr(std::vector<int>& vec) {
	std::cout << "[ ";
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i];
		if (i < vec.size() - 1) std::cout << ", ";
		else std::cout << " ";
	}
	std::cout << "]\n";
}