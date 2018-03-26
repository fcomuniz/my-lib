#include <utility>
namespace my_lib{
	namespace my_select{
		template<class iterator>
		iterator partition(iterator begin, iterator end, iterator pivot){
			iterator smaller = begin;
			iterator larger = begin;
		}	
		template<class iterator, class cf_t>
		iterator select_generic(iterator begin, iterator end, int k, cf_t generateFunction){
			iterator pivot;
			iterator b = begin, e = end;
			while(b != e){
				pivot = generateFunction(b,e);
				std::swap(*pivot,*(e-1));
				pivot = e-1;
				auto partPos = partition(b,e,pivot);		
				int l = (partPos-b);
				if(l == k){
					return partPos;
				} else if(l < k){
					b = partPos+1;
					k = k-l;
				} else {
					e = partPos-1;
				}
			}
			return b;
		}
		template<class iterator>
			iterator generatePivot(iterator begin, iterator end){
				return end-1;
			}
		template<class iterator>
			iterator generateRandomPivot(iterator begin, iterator end){
				return (begin+end)/2;		
			}
	}
	template<class iterator>
		iterator select(iterator begin, iterator end, int k){
			return my_select::select_generic(begin,end,k, my_select::generatePivot<iterator>);
		}

	template<class iterator>
		iterator selectRandom(iterator begin, iterator end, int k){
			return my_select::select_generic(begin,end,k, my_select::generateRandomPivot<iterator>);
		}
	

}
