#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <format>
#include "day_1.h"


std::string d1_p2() {
	return "";
}

std::vector<std::vector<int>> proc_input(std::vector<std::string> raw_input) {
	std::vector<std::vector<int>> elves;
	std::vector<int> elf;
	std::stringstream ss;
	for (std::string s : raw_input) {
		//is this the end of the elf?
		if (s.length() == 0) {
			elves.push_back(elf);
			elf.clear();
			continue;
		}
		//convert string to int and add it to the elf
		int snack;
		snack = stoi(s);
		elf.push_back(snack);
	}
	return elves;
}

std::vector<int> solve(std::vector<std::vector<int>> processed) {
	std::vector<int> totals;
	for (std::vector<int> elf : processed) {
		int total = std::reduce(elf.begin(), elf.end());
		totals.push_back(total);
	}
	std::sort(totals.begin(), totals.end(), std::greater());
	return totals;
}

std::string day_1_output(std::vector<std::string> raw_input) {
	std::string ret;
	std::vector<int> solution = solve(proc_input(raw_input));
	int p1_solution = solution[0];
	int p2_solution = std::reduce(solution.begin(), solution.begin() + 3);
	ret = std::format("part 1: {}\npart 2: {}", p1_solution, p2_solution);
	return ret;
}