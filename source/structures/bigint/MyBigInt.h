

#ifndef MY_LIB_MYBIGINT_H
#define MY_LIB_MYBIGINT_H

#include <bitset>
#include <iostream>

template<int size>
class MyBigInt{
	public:
	using cont = std::bitset<size>;
	template<class integralType>
	MyBigInt(integralType b) : mb(b){

	}

	template<class T>
	friend MyBigInt operator+(const MyBigInt & bg, T v){
		cont value (v);	
		int carry = 0;
		int val;
		for(int i = 0; i < size; i++){
			val = value[i] ^ bg.mb[i] ^ carry;
			carry = value[i] & bg.mb[i] || value[i] & carry || bg.mb[i] & carry;
			value[i] = val;
		}
		return MyBigInt(value);

	}
	friend std::ostream & operator<<(std::ostream & os, const MyBigInt & n){
		bool foundOne = false;
		for(int i = size; i >=0; i--){
			if(!foundOne && n.mb[i]){
				foundOne = true;
			}
			if(foundOne){
				os << n.mb[i];
			}

		}
		return os;
		
	}
	void printWithZeros(std::ostream & os){
		for(int i = size; i >=0; i--){
			os << mb[i];
		}
	}
	private:
	std::bitset<size> mb;
};



template<int size>
std::bitset<size> subtract(const std::bitset<size> & n1, const std::bitset<size> & n2){

}

template<int size>
std::bitset<size> multiply(const std::bitset<size> & n1, const std::bitset<size> & n2){
	std::bitset<size> multiply;
	return multiply;
}

template<int size>
std::ostream & printWithoutZeros(std::ostream & os, const std::bitset<size> & n1){
	bool hasZero = true;
	for(int i = size-1; i >=0; i--){
		if(hasZero && n1[i]){
			hasZero = false;
		}else {
			os << n1[i]; 
		}
	}
}
#endif //MY_LIB_MYBIGINT_H



