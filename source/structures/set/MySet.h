#ifndef MY_LIB_MY_SET
#define MY_LIB_MY_SET

#include <functional>
#include <algorithm>
#include <list>
#include <array>

namespace my_lib{

	template<class T, int m, class hashF = std::hash<T>>
		class MySet{
			public:
				void insert(const T & value){
					if(!hasValue(value)){
						v[getPosition(value)].push_back(value);
					}
				}

				void remove(const T & value){
					auto & list = v[getPosition(value)];
					typename std::list<T>::iterator iter  = std::find(list.begin(),list.end(),value);
					list.erase(iter);
				}
				
				
				
				bool hasValue(const T & value){
					bool hasFound = false;
					for(auto & elem : v[getPosition(value)]){
						if(elem == value){
							hasFound = true;
							break;
						}
					}
					return hasFound;
				}

			private:
				int getPosition( const T & value ){
					return hashFunction(value)%m;
				}
				std::array<std::list<T>,m> v;
				hashF hashFunction;
				
		};
}


#endif
