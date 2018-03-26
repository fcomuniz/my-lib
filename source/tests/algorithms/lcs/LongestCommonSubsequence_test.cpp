//
// Created by francisco on 24/02/18.
//

#include <gtest/gtest.h>
#include "algorithms/pd/lcs/LongestCommonSubsequence.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;


TEST(testing1, test_lcs){
    string s1 = "10010101";
    string s2 = "010110110";
    auto s3 = LCSsearch(s2,s1);
    ASSERT_EQ("101010",s3);
}

TEST(LCS, LCSTests){
    string s1 = "10010101";
    string s2 = "010110110";
    ASSERT_EQ(LCS(s1,s2),6);
}