//
// Created by francisco on 24/02/18.
//

#include "LongestCommonSubsequence.h"
#include <string>
#include <vector>

template<>
std::string LCSsearch(const std::string & x,const  std::string & y);

template<>
std::vector<int> LCSsearch(const std::vector<int> & x,const  std::vector<int> & y);

template<>
std::vector<bool> LCSsearch(const std::vector<bool> & x,const  std::vector<bool> & y);

template<>
size_t LCS(const std::string & x, const std::string & y);

template<>
size_t LCS(const std::vector<int> & x, const std::vector<int> & y);

