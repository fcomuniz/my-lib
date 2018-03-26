//
// Created by francisco on 24/02/18.
//

#ifndef MY_LIB_LONGESTCOMMONSUBSEQUENCE_H
#define MY_LIB_LONGESTCOMMONSUBSEQUENCE_H

#include <algorithm>
#include <stack>
#include "iostream"

template<class T>
T LCSsearch(const T & x,const  T & y){
    auto n = x.size();
    auto m = y.size();
    size_t c[n+1][m+1] = {};
    int i, j;
    int f;
    for(i = 0, f = std::max(m,n); i < f; i++){
        if(i < n){
            c[i][0] = 0;
        }
        if(i < m){
           c[0][i] = 0;
        }
    }
    for(i = 1; i <= n; i++){
        for (j = 1; j <= m; ++j) {
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
            } else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
            } else {
                c[i][j] = c[i][j-1];
            }
        }
    }
    i = n;
    j = m;
    T retV;
    while(c[i][j] != 0){
        if(x[i-1] == y[j-1]){
            retV.push_back(x[i]);
            i--;
            j--;
        } else if(c[i-1][j] >= c[i][j-1]){
            i--;
        } else{
            j--;
        }
    }
    std::reverse(retV.begin(),retV.end());
    return retV;
}

template<class T>
size_t LCS(const T& x, const T & y){
    auto n = x.size();
    auto m = y.size();
    size_t c[n+1][m+1] = {};
    int i, j;
    int f;
    for(i = 0, f = std::max(m,n); i < f; i++){
        if(i < n){
            c[i][0] = 0;
        }
        if(i < m){
           c[0][i] = 0;
        }
    }
    for(i = 1; i <= n; i++){
        for (j = 1; j <= m; ++j) {
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
            } else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
            } else {
                c[i][j] = c[i][j-1];
            }
        }
    }
    return c[n][m];
}



#endif //MY_LIB_LONGESTCOMMONSUBSEQUENCE_H
