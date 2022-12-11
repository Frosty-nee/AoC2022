#include <iostream>
#include <string>
#include <vector>
#include <format>
#include <set>

#include "day_3.h"

std::string ascii_letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::vector<std::vector<std::set<char>>> process_input(std::vector<std::string> raw_input) {
	std::vector<std::vector<std::set<char>>> procinp;
	for (std::string s : raw_input) {
		std::vector<std::set<char>> row;
		std::set<char> c1set;
		std::set<char> c2set;
		std::string c1 = s.substr(0, s.length() / 2);
		std::string c2 = s.substr(s.length() / 2, s.length());
		for (char c : c1) {
			c1set.insert(c);
		}
		row.push_back(c1set);
		for (char c : c2) {
			c2set.insert(c);
		}
		row.push_back(c2set);
		procinp.push_back(row);
	}
	return procinp;
}

int score_item(char c) {
	if (c >= 97) {
		return c - 96 ;
	}
	else if (c <= 90) {
		return c - 64 + 26;
	}
	else {
		return -1;
	}
}

int solve_p1(std::vector<std::vector<std::set<char>>> procinp) {
	int sum = 0;
	for (std::vector backpack : procinp) {
		for (char letter : ascii_letters) {
			if (backpack[0].count(letter) > 0 && backpack[1].count(letter) > 0) {
				sum += score_item(letter);
			}
		}

	}
	return sum;
}

int solve_p2(std::vector<std::vector<std::set<char>>> procinp) {
	int sum = 0;
	for (int i = 2; i <= procinp.size(); i += 3) {
		std::set<char> elves [3];
		for (int j = 0; j < 3; j++) {
			std::vector<std::set<char>> e = procinp[(i - j)];
			std::set<char> eset;
			for (std::set s : e) {
				eset.insert(s.begin(), s.end());
			}
			elves[j] = eset;
		}
		for (char c : ascii_letters) {
			if (elves[0].count(c) > 0 && elves[1].count(c) > 0 && elves[2].count(c) > 0 ) {
				sum += score_item(c);
			}
		}
		
	}
	return sum;
}

std::vector<int> day_3_output(std::vector<std::string> raw_input) {
	std::vector<int> ret;
	std::vector<std::vector<std::set<char>>> procinp = process_input(raw_input);
	ret.push_back(solve_p1(procinp));
	ret.push_back(solve_p2(procinp));
	return ret;
	
}