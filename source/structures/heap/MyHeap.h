#ifndef MY_HEAP
#define MY_HEAP

#include <structures/MyGeneral.h>
#include <structures/exceptions/exceptions.h>
#include <vector>
#include <functional>

#include <iostream>

template<class T, class F = std::less<T>>
class MyHeap {
public:

	/** iterative insertion **/
	void insert(T data){
		heap.push_back(data);
		bool swapping = true;
		int i = size;
		while(swapping && i != 0){
			if(compFun(heap[i],heap[(i-1)>>1])){
				swap(heap[i],heap[(i-1)>>1]);	
				i = (i-1)>>1;
			}  else {
				swapping = false;
			}
		}
		size++;
	}
	

	/** iterative solution for removing the first element **/
	void remove(){
		if(size > 0){
			size--;
			if(size == 0){
				heap.pop_back();	
			}else {
				auto v = heap.back();
				heap.pop_back();
				heap[0] = v;	
				bool swapping = true;
				int i = 0;
				while(swapping){
					if(((i<<1)+1) < size && (i<<1)+2 < size){
						auto & hv = (compFun(heap[(i<<1)+1],heap[((i<<1))+2])) ? heap[(i<<1)+1] : heap[((i<<1))+2];
						auto nextIndex = ((compFun(heap[(i<<1)+1],heap[((i<<1))+2]))) ? (i<<1)+1 : ((i<<1))+2;
						if(!compFun(heap[i],hv)){
							swap(heap[i],hv);	
							i = nextIndex;
						} else {
							swapping = false;
						}

					} else if(((i<<1)) < size){
						if(!compFun(heap[i],heap[(i<<1)+1])){
							swap(heap[i],heap[(i<<1)+1]);
							i = ((i<<1)+1);
						} else {
							swapping = false;
						}
					}else if(((i+1)<<1)+1 < size){
						std::cout << "entrou2\n";
						if(!compFun(heap[i],heap[((i)<<1)+2])){
							swap(heap[i],heap[((i)<<1)+2]);
							i = ((i)<<1)+2;
							swapping = true;
						} else {
							swapping = false;
						}
					}  else {
						swapping = false;
					}
				}
			}	
		}else {
			throw empty_exception("The heap is empty, can't remove element");
		}
	}
	
	T top(){
		if(size >0 ){
			return heap[0];	 
		} else {
			throw empty_exception("The heap is empty, can't see top element");
		}	
	}

	bool empty(){
		return size == 0;
	}
		
private:
	using container = std::vector<T>;
	int size = 0;
	container heap;	
	F compFun = F();
};


#endif 
