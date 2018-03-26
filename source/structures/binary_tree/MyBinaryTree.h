#ifndef MYBINARYTREE_H
#define MYBINARYTREE_H
#include <stack>
#include <iostream>

template<class T>
struct MyBinaryTreeNode;

template<class T>
using MBTNPtr = MyBinaryTreeNode<T> *;


template<class T>
struct MyBinaryTreeNode{
	MyBinaryTreeNode(): left(nullptr), right(nullptr){

	}
	MyBinaryTreeNode(T data):data(data),left(nullptr), right(nullptr){

	}
	virtual ~MyBinaryTreeNode(){
		delete left;
		delete right;
		left = nullptr;
		right = nullptr;
	}

	T data;
	MBTNPtr<T> left = nullptr;
	
	MBTNPtr<T> right = nullptr;
};
template<class T>
class MyBinaryTree{
	public:
		MBTNPtr<T> root;
		
		template<class F>	
		void inOrderTraversal(){

		}
	private:	

};

template<class T>
class MyBinarySearchTree : MyBinaryTree<T>{
	public:
		void insert(T data){

		}
		void remove(T data){

		}
	
		static void rebalanceTree(MyBinarySearchTree & st){

		}

		friend std::ostream operator<<(std::ostream & os, MyBinarySearchTree & tree){
			auto cf = [os](MBTNPtr<T> ptr){
				os << ptr->data << " ";
			};
			inOrderTraversal(tree->root,cf);
			return os;
		}

		friend std::istream  operator>>(std::istream & is, MyBinarySearchTree & tree){


			return is;
		}	
};

template<class T, typename F>
void inOrderTraversal(MBTNPtr<T> node, F visitFunction){
	if(node != nullptr){
		inOrderTraversal(node->left, visitFunction);
		visitFunction(node);
		inOrderTraversal(node->right,visitFunction);
	}	
}

template<class T, typename F>
void preOrderTraversal(MBTNPtr<T> node, F visitFunction){
	if(node != nullptr){
		visitFunction(node);
		preOrderTraversal(node->left,visitFunction);
		preOrderTraversal(node->right,visitFunction);
	}
}
template<class T, typename F>
void postOrderTraversal(MBTNPtr<T> node, F visitFunction){
	if(node != nullptr){
		postOrderTraversal(node->right,visitFunction);
		visitFunction(node);
		postOrderTraversal(node->left, visitFunction);
	}	
}


template<class T>
MBTNPtr<T> findLowestCommonAncestorBST(MBTNPtr<T> root, T value1, T value2){
	auto auxval = value1;
	value1 = min(value1, value2);
	value2 = max(auxval,value2);
	while(root != nullptr){
		T currVal = root->data;			
		if(currVal >= value1 && currVal <= value2 ){
			return root;
		} else if(currVal < value1){
			root = root->left;
		} else {
			root = root->right;
		}
	}	
	return root;
}
template <class T, class F>
void iterativePreorder(MBTNPtr<T> root, F visitFunction){
	std::stack<MBTNPtr<T>> s;
	s.push(root);
	while(!s.empty()){
		auto top = s.top();
		s.pop();
		visitFunction(top);
		if(top->right != nullptr){
			s.push(top->right);
		}
		if(top->left != nullptr){
			s.push(top->left);
		}
	}
}

template<class T, class F>
void iterativePostorder(MBTNPtr<T> root, F visitFunction){
	std::stack<MBTNPtr<T>> s;
	MBTNPtr<T> p = root, q = root;
	while(p != nullptr){
		for(;p->left != nullptr; p = p->left){
			s.push(p);
		}
		while(p->right == nullptr || p->right == q){
			visitFunction(p);
			q = p;
			if(s.empty()){
				return;
			}	
			p = s.top();
			s.pop();			
		}
		s.push(p);
		p = p->right;
	}
}

template<class T>
MBTNPtr<T> deserializeTree(std::istream & s){
	return nullptr;
}

#endif
