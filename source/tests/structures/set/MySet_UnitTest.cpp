#include "structures/set/MySet.h"
#include <gtest/gtest.h>
#include <fstream>
#include <string>


using namespace std;
using my_lib::MySet;

TEST(MySet, addingAndRemovingElements){
 	MySet<int,1000> mySet;	

	mySet.insert(1);
	ASSERT_TRUE(mySet.hasValue(1));
	ASSERT_FALSE(mySet.hasValue(2));
	mySet.insert(2);
	ASSERT_TRUE(mySet.hasValue(2));
	mySet.remove(2);
	ASSERT_FALSE(mySet.hasValue(2));
	ASSERT_TRUE(mySet.hasValue(1));
}
TEST(MySet, addingAndRemovingElementsDouble){
 	MySet<double,1000> mySet;	

	mySet.insert(1);
	ASSERT_TRUE(mySet.hasValue(1));
	ASSERT_FALSE(mySet.hasValue(2));
	mySet.insert(2);
	ASSERT_TRUE(mySet.hasValue(2));
	mySet.remove(2);
	ASSERT_FALSE(mySet.hasValue(2));
	ASSERT_TRUE(mySet.hasValue(1));
}
TEST(MySet, addingManyElements){
	ifstream f("MySetTest.txt")	;
	MySet<int,100> mySet;
	std::string line;
	while(getline(f,line)){
		mySet.insert(stoi(line));		
	}
}
