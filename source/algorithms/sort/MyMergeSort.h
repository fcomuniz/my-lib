#ifndef MY_LIB_MY_MERGE_SORT
#define MY_LIB_MY_MERGE_SORT

#include <iterator>
#include <functional>

namespace my_lib{
	template<typename iterator, typename function>
	void MyMergeSort(iterator begin, iterator end, fuction f = std::less<std::iterator_traits<iterator>> ()){
		auto middle = begin	
	}

	template<typename iterator, typename function>
	void MyMerge(iterator begin1, iterator end1, iterator begin2, iterator end2, fuction compareFunction){
		while(begin1 != end1 || begin2 != end2){

		}	
	}
}

#endif
