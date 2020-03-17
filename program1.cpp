#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>


int topDown(std::vector<std::vector<int>> & mat, std::string s1, std::string s2){
	for(int i = 0; i <= n; i++){
		for(int j = 0 j <= m; j++){
			if(i == 0 || j == 0){
				mat[i][j] = 0;
			}else{
				if(s1[i-1] == s2[j-1]){
					mat[i][j] = 1 + mat[i-1][j-1];
				}else{
					if(mat[i-1][j] > mat[i][j-1]){
						mat[i][j] = mat[i-1][j];
					}else{
						mat[i][j] = mat[i][j-1];
					}
				}
			}
		}
	}
	return mat[n][m];
}

int main(int argc, char **argv){
	std::chrono start = high_resolution_clock::now();
	assert(argc == 4);
	std::string x;
	std::string y;
	std::ifstream reader(argv[1]);
	std::ifstream reader2(argv[2]);
	reader >> x;
	reader2 >> y;
	reader.close(); reader2.close();

	int n = s1.size();
	int m = s2.size();
	vector<vector<int> > mat(n+1, vector<int>(m+1, 0));
	int len = topDown(mat, s1, s2);


	std::chrono end = high_resolution_clock::now();
	std::chrono time = duration_cast<seconds>(end-start);
	std::ofstream output(argv[3]);
	if(n < 10 || m < 10){
		for(int i = 0; i < n+1; i++){
			for(int j = 0; j < m+1; j++){
				output << mat[i][j] << " " ;
			}
			output << "\n";
		}
	}
	output << len << "\n";
	output << time.count() << " seconds\n";
	output.close();

	return 0;
}