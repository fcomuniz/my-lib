#include <gtest/gtest.h>
#include <structures/heap/MyHeap.h>


MyHeap<int> createSimpleHeap(){
	MyHeap<int> heap;
	for(int i = 0; i< 10; i++){
		heap.insert(i);
	}
	return heap;
}

TEST(MyHeap, insertData){
	MyHeap<int> heap;
	for(int i = 0; i < 10; i++){
		heap.insert(i);	
	}
	ASSERT_EQ(heap.top(),0);
}
TEST(MyHeap, removeData){
	auto h = createSimpleHeap();
	for(int i = 0; i < 10; i++){
		ASSERT_EQ(h.top(),i);
		h.remove();
	}
}
TEST(MyHeap, heap_sort){
	MyHeap<int> heap;
	std::vector<int> v = {3,9,6,4,5,1};
	for(int i = 0, n= v.size(); i < n; i++){
		heap.insert(v[i]);
	}
	sort(v.begin(),v.end());
	for(int i = 0, n = v.size(); i < n; i++){
		ASSERT_EQ(heap.top(),v[i]);
		heap.remove();
	}
	
	
}

TEST(MyHeap, heap_sort_max){
	MyHeap<int,std::greater<int>> heap;
	std::vector<int> v = {3,9,6,4,5,1};
	for(int i = 0, n= v.size(); i < n; i++){
		heap.insert(v[i]);
	}
	sort(v.begin(),v.end(), std::greater<int>());
	for(int i = 0, n = v.size(); i < n; i++){
		ASSERT_EQ(heap.top(),v[i]);
		heap.remove();
	}
}
