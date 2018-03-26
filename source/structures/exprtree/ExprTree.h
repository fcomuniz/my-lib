#ifndef MY_LIB_EXPR_TREE
#define MY_LIB_EXPR_TREE

template<class S>
class ExprTreeNode;

template<class S>
using ExTPtr = ExprTreeNode *;

template<class S>
class ExprTreeNode{
	public:
		ExprTreeNode(S k, ExTPtr l = nullptr, ExTPtr r = nullptr) : key(k) , left(l), right(r){
					
		
		}
		S key;
		ExTPtr left, right;
}


template <class S>
class ExprTree{
	ExTPtr factor(){

	}

}


#endif
