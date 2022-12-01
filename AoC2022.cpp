#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <format>
#include "day_1.h"

using namespace std;

vector<string> load_raw(string f) {
	ifstream infile(f);
	string line;
	vector<string> ret;
	while (getline(infile, line)) {
		ret.push_back(line);
	}
	return ret;
}

int main(int argc, char *argv[]) {
	if (argc <= 1) {
		int day;
		cout << "input day: ";
		cin >> day;
		cout << day + "\n";
	}
	cout << day_1_output(load_raw("day_1_input.txt"));
}
