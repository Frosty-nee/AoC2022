#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <map>
#include "day_2.h"


std::map<char, char> victory_map = {
	{'B', 'A'},
	{'C', 'B'},
	{'A', 'C'}
};

int score_p1(std::string s) {
	// I could be doing this with math but I suck at math
	// too bad I realized how do to this with math after I solved it already fuck
	char oplay = s[0];
	char meplay = s[2] - 23;
	int score = meplay % 64;
	if (victory_map[meplay] == oplay) {
		score += 6;
	}
	else if (meplay == oplay) {
		//draw
		score += 3;
	}
	
	return score;
}

int solve_p1(std::vector<std::string> raw_input) {
	int total_score = 0;
	for (std::string s : raw_input) {
		total_score += score_p1(s);
	}
	return total_score;
}

int solve_p2(std::vector<std::string> raw_input) {
	int total_score = 0;
	for (std::string s : raw_input) {
		int score = 0;
		char oplay = s[0];
		char meplay;
		char result = s[2];
		if (result == 'X') {
			//I need to lose
			meplay = victory_map[oplay];
		}
		else if (result == 'Z') {
			//I need to win
			meplay = victory_map[victory_map[oplay]]; //I am a genius but also vv
		}
		else {
			//draw
			meplay = oplay;
		}
		score = score_p1(std::format("{} {}", oplay, meplay+=23)); // I am ashamed of my transgressions
		total_score += score;
	}
	return total_score;
}


std::vector<int>day_2_output(std::vector<std::string> raw_input) {
	std::vector<int> ret;
	ret.push_back(solve_p1(raw_input));
	ret.push_back(solve_p2(raw_input));
	return ret;
}