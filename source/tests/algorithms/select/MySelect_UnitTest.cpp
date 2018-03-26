#include <gtest/gtest.h>
#include "algorithms/select/MySelect.h"
#include <bits/stdc++.h>
using namespace std;


TEST(MySelect, simpleSelect){
	const int s = 10000;
	vector<int> v(s);
	for(int i =0; i < s;i++){
		v[i] = i;
	}
	random_shuffle(v.begin(),v.end());
	for(int i = 0; i < s; i++){
		auto it = my_lib::select(v.begin(),v.end(), i+1);
		EXPECT_EQ(*it,i);
	}
}
