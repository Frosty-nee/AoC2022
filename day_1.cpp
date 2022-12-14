#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <format>
#include "day_1.h"


std::vector<std::vector<int>> proc_input(const std::vector<std::string>& raw_input) {
	std::vector<std::vector<int>> elves;
	std::vector<int> elf;
	std::stringstream ss;
	for (const std::string& s : raw_input) {
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

std::vector<int> solve(const std::vector<std::vector<int>>& processed) {
	std::vector<int> totals;
	for (const std::vector<int>& elf : processed) {
		int total = std::reduce(elf.begin(), elf.end());
		totals.push_back(total);
	}
	std::sort(totals.begin(), totals.end(), std::greater());
	return totals;
}

std::vector<int> day_1_output(const std::vector<std::string>& raw_input) {
	std::vector<int> ret;
	std::vector<int> solution = solve(proc_input(raw_input));
	ret.push_back(solution[0]);
	ret.push_back(std::reduce(solution.begin(), solution.begin() + 3));
	return ret;
}