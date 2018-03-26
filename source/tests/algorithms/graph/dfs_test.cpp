#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;


TEST(Graph, adjacency_matrix){
	ifstream file("dfs.txt");
	int T;
	file >> T;
	while(T--){
		int N;
		file >> N;
		unordered_map<int,int> m;
		vector<int> v(N);
		vector<vector<bool>> adjacency_matrix(N,vector<bool>(N, false));
		for(int i = 0; i < N; i++){
			file >> v[i];
			m.insert(make_pair(v[i],i));	
		}
		int E;
		file >> E;
		file.ignore(numeric_limits<streamsize>::max(),'\n');
		for(int i = 0; i < E; i++){
			stringstream ss;
			string str;
			getline(file,str);
			ss.str(str);
			int currNode;
			int adjacent;
			ss >> currNode;
			while(ss>>adjacent){
				adjacency_matrix[m[currNode]][m[adjacent]] = true;	
			}		
		}
	}
}

TEST(Graph, dfs){
}
