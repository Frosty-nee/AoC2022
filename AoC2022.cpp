#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <format>
#include "day_1.h"
#include "day_2.h"
#include "day_3.h"
#include "day_4.h"


std::vector<std::string> load_raw(std::string f) {
	std::ifstream infile(f);
	std::string line;
	std::vector<std::string> ret;
	while (getline(infile, line)) {
		ret.push_back(line);
	}
	return ret;
}

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		int day;
		std::cout << "input day: ";
		std::cin >> day;
		std::cout << day + "\n";
	}
	std::vector<int> solutions = day_4_output(load_raw("day_4_input.txt"));
	for (int i : solutions) {
		printf("%i\n", i);
	}
}
