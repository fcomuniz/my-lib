#include <gtest/gtest.h>
#include "structures/graph/MyGraph.h"
#include <iostream> 
#include <fstream>
#include <functional>

using namespace std;
using namespace placeholders;

TEST(MyGraph, dfs){
	ifstream f("mytestgraph.txt");
	MyGraph<int> g;
	initializeGraph(g,f);
	std::vector<int> values;
	auto visitFunction = [] ( int  data){
		cout << data << endl;
	};
	g.dfs(visitFunction);
}

TEST(MyGraph, bfs){
	ifstream f("mytestgraph.txt");
	MyGraph<int> g;
	initializeGraph(g,f);
	std::vector<int> values;
	auto visitFunction = [] ( int  data){
		cout << data << endl;
	};
	g.bfs(visitFunction);
}

