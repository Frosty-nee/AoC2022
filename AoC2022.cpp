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


std::vector<std::string> load_raw(const std::string& f) {
	std::ifstream infile(f);
	std::string line;
	std::vector<std::string> ret;
	while (getline(infile, line)) {
		ret.push_back(line);
	}
	return ret;
}

int main(int argc, char *argv[]) {
	std::vector<std::string> raw_input = load_raw("day_1_input.txt");
	std::vector<int> solutions = day_1_output(raw_input);
	for ( const int& i : solutions) {
		printf("%i\n", i);
	}
}
