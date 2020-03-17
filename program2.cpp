#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <cassert>
#include <algorithm>


int longestCS(std::string s1, std::string s2){
	if(s1.empty() || s2.empty()){
		return 0;
	}
	if(s1.back() == s2.back()){
		return 1 + longestCS(s1.substr(0,s1.size()-1), s2.substr(0,s2.size()-1));
	}else{
		return std::max(longestCS(s1.substr(0,s1.size()), s2.substr(0,s2.size()-1)), longestCS(s1.substr(0,s1.size()-1), s2.substr(0,s2.size())));
	}
}


int main(int argc, char **argv){
	auto start = std::chrono::high_resolution_clock::now();
	assert(argc == 4);
	std::string x;
	std::string y;
	std::ifstream reader(argv[1]);
	std::ifstream reader2(argv[2]);
	reader >> x;
	reader2 >> y;
	reader.close(); reader2.close();

	int len = longestCS(x, y);

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time = end-start;
	
	std::ofstream output(argv[3]);
	output << len << "\n";
	output << time.count() << " seconds\n";
	output.close();

	return 0;
}
