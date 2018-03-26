#include <gtest/gtest.h>
#include "algorithms/sort/MyQuickSort.h"
#include <bits/stdc++.h>
using namespace std;

TEST(MyQuickSort_Test, Testing){
	ifstream file("QuickSortTest.txt");
	vector<int> valuesToSort;
	vector<int> compareValue;
	int value;
	while(file>>value){
		valuesToSort.push_back(value);
		compareValue.push_back(value);
	}
	MyQuickSort(valuesToSort.begin(),valuesToSort.end());
	sort(compareValue.begin(),compareValue.end());
	for(int i = 0, n = valuesToSort.size(); i < n; i++){
		ASSERT_EQ(valuesToSort[i], compareValue[i]);
	}


}
