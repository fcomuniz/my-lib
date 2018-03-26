#ifndef MY_LIB_MY_HEAP_SORT
#define MY_LIB_MY_HEAP_SORT

#include <vector>
#include <functional>


namespace my_lib{
	namespace heapsort{
		int getParent(int i){
			return i>>1;
		}
		int getLeftChild(int i){
			return (i<<1)+1;
		}
		int getRightChild(int i){
			return getLeftChild(i)+1;
		}

		template<class T, class cf_t = std::less<T>>
		void heapify(std::vector<T> & A, int index, int n, cf_t compareFunction){
			if(index >= n) return;
			int left = getLeftChild(index);	
			int right = getRightChild(index);
			int largest;
			if(left < n && compareFunction(A[left],A[index]))
				largest = left;
			else 
				largest = index;
			if (right < n && compareFunction(A[right],A[largest]))
				largest = right;
			if(largest != index){
				std::swap(A[largest],A[index]);
				heapify(A,largest,n,compareFunction);
			}
		}

		template<class T, class cf_t = std::less<T>>
			void build_heap(std::vector<T> & A, cf_t compareFunction){
				int start = A.size()/2 -1;
				int n = A.size();
				for(int i = start; i >=0; i--){
					heapify(A,i,n,compareFunction);
				}
			}

	}
	template<class T, class cf_t = std::less<T>>
		void heapSort(std::vector<T> & A, cf_t compareFunction = cf_t()){
			heapsort::build_heap(A,compareFunction);
			int n = A.size();
			for(int i = A.size()-1; i >=1; i--){
				std::swap(A[0],A[i]);
				n--;
				heapsort::heapify(A,0,n,compareFunction);
			}
			reverse(A.begin(),A.end());
		}
}





#endif
