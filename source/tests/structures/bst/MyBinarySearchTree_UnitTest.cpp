#include <gtest/gtest.h>
#include <vector>
#include <structures/bst/MyBinarySearchTree.h>


using my_lib::MyBinarySearchTree;

template<class T>
class MyBSTUnit :public MyBinarySearchTree<T>{
	public:
	using MyBinarySearchTree<T>::MyBinarySearchTree;
	void traverseTreeVal(){
		auto visitFunction = [] (T p){
			std::cout << p << " ";
		};
		MyBinarySearchTree<T>::traverseTree(visitFunction);	
		std::cout << std::endl;
	}
};


TEST(MyBinarySearchTree, construction){
	std::vector<int> v = {1,2,3,4,5,6,10,-1,3,523,3};
	MyBSTUnit<int> b(v.begin(),v.end());
	b.traverseTreeVal();
}

TEST(MyBinarySearchTree, iterator){
	std::vector<double> v = {1.3,3.2,4.5,3.4,3.2,9,5.6,10,1000};
	MyBSTUnit<double> b(v.begin(),v.end());
	auto beg = b.begin();
	while(beg != b.end()){
		std::cout << *beg << std::endl;
		beg++;
	}
	beg = b.begin();
	std::for_each(beg,b.end(), [](double v){
			std::cout << v << std::endl;
			});
}
TEST(MyBinarySearchTree, empty_tree){
	std::vector<double> v = {};
	try{

	MyBSTUnit<double> b(v.begin(),v.end());
		ASSERT_EQ(b.begin(),b.end());
	} catch (std::exception & e){
		std::cerr << e.what() << std::endl;
	}
}
