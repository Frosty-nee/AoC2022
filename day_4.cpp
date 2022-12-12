#include <vector>
#include <iostream>
#include <string>
#include <format>
#include <sstream>

#include "day_4.h"

std::vector<std::vector<int>> process_input(std::vector<std::string> raw_input) {
	std::vector<std::vector<int>> procinp;
	for (std::string s : raw_input) {
		std::vector<int> elf_pair;
		std::string elves[2];
		elves[0] = s.substr(0, s.find(","));
		elves[1] = s.substr(s.find(",")+1, s.size());
		//there is almost certainly a better way to do this, fix later
		elf_pair.push_back(stoi(elves[0].substr(0, elves[0].find("-"))));
		elf_pair.push_back(stoi(elves[0].substr(elves[0].find("-") + 1, elves[0].size())));
		elf_pair.push_back(stoi(elves[1].substr(0, elves[1].find("-"))));
		elf_pair.push_back(stoi(elves[1].substr(elves[1].find("-") + 1, elves[1].size())));
		procinp.push_back(elf_pair);
		std::cout << std::format("{}-{}, {}-{}\n", elf_pair[0], elf_pair[1], elf_pair[2], elf_pair[3]);
	}
	return procinp;
}

int solve_p1(std::vector<std::vector<int>> procinp) {
	int ret = 0;
	for (std::vector<int> vec : procinp) {
		if ((vec[0] <= vec[2] && vec[1] >= vec[3]) || (vec[2] <= vec[0] && vec[3] >= vec[1])) {
			ret++;
		}
	}
	return ret;
}

int solve_p2(std::vector<std::vector<int>> procinp) {
	int ret = 0;
	for (std::vector<int> vec : procinp) {
		if (vec[0] >= vec[2] && vec[0] <= vec[3]) ret++;
		else if (vec[1] >= vec[2] && vec[1] <= vec[3]) ret++;
		else if (vec[2] <= vec[1] && vec[2] >= vec[0]) ret++;
		else if (vec[3] >= vec[0] && vec[3] <= vec[1]) ret++;
	}
	return ret;
}

std::vector<int> day_4_output(std::vector<std::string> raw_input) {
	std::vector<int> ret;
	std::vector<std::vector<int>> procinp = process_input(raw_input);
	ret.push_back(solve_p1(procinp));
	ret.push_back(solve_p2(procinp));
	return ret;
}