#include <gtest/gtest.h>
#include "algorithms/sort/MyHeapSort.h"
#include <fstream>

using namespace std;
namespace MyHeapSort_UnitTest{

template<class T>
	void printVector(ostream & os, const vector<T> & v){
		for(auto & elem: v){
			os << elem << " ";
		}
		os << endl;
	}
}

TEST(MyHeapSort, sorting){
	ifstream f("QuickSortTest.txt");	
	std::string line;	
	vector<int> vi;
	while(getline(f,line)){
		int value = stoi(line);
		vi.push_back(value);	
	}
	vector<int> vi2 = vi;
	cout << "sorting " << vi.size() << " elements" << endl;
	my_lib::heapSort(vi);
	sort(vi2.begin(), vi2.end());
	for(int i = 0; i < vi.size(); i++){
		ASSERT_EQ(vi[i],vi2[i]);
	}
}

TEST(MyHeapSort, smallSorting){
	vector<int> vi = {16,14,10,8,7,9,3,2,4,1};
	my_lib::heapSort(vi, std::greater<int>());
	MyHeapSort_UnitTest::printVector(cout,vi);
}

TEST(MyHeapSort, heapify){
	vector<int> vi = {1,14,10,8,7,9,3,2,4,16};
	int n = vi.size()-2;
	MyHeapSort_UnitTest::printVector(cout,vi);
	my_lib::heapsort::heapify(vi,0,n,std::greater<int>());
	MyHeapSort_UnitTest::printVector(cout,vi);
}

