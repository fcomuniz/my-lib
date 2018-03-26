#ifndef MY_QUICK_SORT_MY_LIB
#define MY_QUICK_SORT_MY_LIB

#include <iterator>

template <class iterator, class cf_t>
iterator MyPartition(iterator begin, iterator end, cf_t compareFunction){
	auto value = *(end-1);
	auto i = begin-1;
	for(iterator j = begin; j < end-1; j++){
		if(compareFunction(*j,value)){
			i++;
			std::swap(*i,*j);
		}
	}
	std::swap((*(i+1)), *((end-1)));
	return i+1;
}

template<class iterator, class cf_t = std::less< typename std::iterator_traits<iterator>::value_type>>
void MyQuickSort(iterator begin, iterator end, cf_t compareFunction = std::less< typename std::iterator_traits<iterator>::value_type>()){
	if(begin < end){
		auto pos = MyPartition(begin,end,compareFunction);
		MyQuickSort(begin,pos);
		MyQuickSort(pos+1,end);
	}
}

#endif
