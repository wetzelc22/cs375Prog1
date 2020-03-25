#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <cassert>
#include <algorithm>


int topDown(std::string s1, std::string s2, int x, int y , std::vector<std::vector<int>> mat){
	if(x == 0 || y == 0){
		return 0;
	}
	if(mat[x-1][y-1] != -1){
		return mat[x-1][y-1];
	}

	if(s1[x-1] == s2[y-1]){
		mat[x-1][y-1] = 1 + topDown(s1, s2, x-1, y-1, mat);
		return mat[x-1][y-1];
	}else{
		mat[x-1][y-1] = std::max(topDown(s1, s2, x, y-1, mat), topDown(s1, s2, x-1, y, mat));
		return mat[x-1][y-1];
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

	int n = x.size();
	int m = y.size();
	std::vector<std::vector<int> > mat(n+1, std::vector<int>(m+1, -1));
	int len = topDown(x, y, n, m, mat);


	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time = end-start;
	std::ofstream output(argv[3]);
	
	output << len << "\n";
	output << time.count() << " seconds\n";
	output.close();

	return 0;
}
