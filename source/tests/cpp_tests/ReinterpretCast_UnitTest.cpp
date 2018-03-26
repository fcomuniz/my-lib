#include <gtest/gtest.h>
#include <map>
#include <bitset>

using namespace std;


TEST(reinterpretCastTest, testingWithClass){
	using m_t = map<int,int>;
	using bs_t = bitset<8*sizeof(m_t)>;
	m_t mp = {{1,1},{2,1},{3,1},{4,1}};
	bitset<8*sizeof(m_t)> l = reinterpret_cast<bs_t>(mp);
	cout << l << endl;
}
