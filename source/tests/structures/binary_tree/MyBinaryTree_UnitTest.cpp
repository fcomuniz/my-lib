#include <gtest/gtest.h>
#include <structures/binary_tree/MyBinaryTree.h>

using namespace std;


template<class T>
MBTNPtr<T> buildTree(){
	MBTNPtr<T> root = new MyBinaryTreeNode<T>(1);
	root->left = new MyBinaryTreeNode<T>(3);
	root->right = new MyBinaryTreeNode<T>(5);
	root->left->left = new MyBinaryTreeNode<T>(10);
	return root;
}

template<class T>
MBTNPtr<T>  buildTree(istream & s){
	return nullptr;		
}

TEST(MyBinaryTree, preorder){
	auto t = buildTree<int>();
	auto visitFunction = [](MBTNPtr<int> node){
		cout << node->data << " ";	
	};
	preOrderTraversal(t,visitFunction);
	cout << endl;

}

TEST(MyBinaryTree, iterativePreorder){
	auto t = buildTree<int>();
	auto visitFunction = [](MBTNPtr<int> node){
		cout << node->data << " ";	
	};
	iterativePreorder(t,visitFunction);
	cout << endl;

}

TEST(MyBinaryTree, iterativePostorder){
	auto t = buildTree<int>();
	auto visitFunction = [](MBTNPtr<int> node){
		cout << node->data << " ";	
	};
	iterativePostorder(t,visitFunction);
	cout << endl;

}
