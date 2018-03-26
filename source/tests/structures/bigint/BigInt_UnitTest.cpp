#include <gtest/gtest.h>
#include "structures/bigint/MyBigInt.h"
#include <iostream>

using namespace std;
#define maxSize  100
TEST(MyBigInt, sumtest){
	MyBigInt<maxSize> mbi(100);
	MyBigInt<maxSize> mbi2(200);
	cout << mbi << endl;
}

