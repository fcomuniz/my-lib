#ifndef MY_LIB_MY_BINARY_SEARCH_TREE
#define MY_LIB_MY_BINARY_SEARCH_TREE

#include <exceptions/exceptions.h>

namespace my_lib{
	namespace my_bst{
		template<class T>
		struct node;

		template<class T>
		using nptr = node<T>*;

		template<class T>
		struct node{
			node(): left(nullptr), right(nullptr), parent(nullptr){

			}
			node(T val): node(){
				this->val = val;

			}
			nptr<T> left, right, parent;	
			T val;
		};

		template<class T, class cf_t>
			void InorderTraversal(nptr<T> root, cf_t visitFunction){
				if(root != nullptr){
					InorderTraversal(root->left, visitFunction);
					visitFunction(root->val);
					InorderTraversal(root->right, visitFunction);
				}
			}

		template<class T>
			nptr<T> TreeSearch(nptr<T> root, const T & k){
				if(root == nullptr || k == root->val){
					return root;
				}
				if(k < root->val){
					return TreeSearch(root->left,k);
				} else {
					return TreeSearch(root->right,k);
				}
			}
		template<class T>
			nptr<T> iterativeTreeSearch(nptr<T> root, const T & k){

			}

		template<class T>
		T getLeftmost(nptr<T> node){
			if(node == nullptr) throw my_lib::exception::empty_exception();
			const T & returnValue;
			while(node != nullptr){
				returnValue = node->val;
				node = node->left;
			}
			return returnValue;
		}
		template<class T>
			T getRightmost(nptr<T> node){
				if(node == nullptr) throw my_lib::exception::empty_exception("getting rightmost");
				const T & returnValue;
				while(node != nullptr){
					returnValue = node->val;	
					node = node->right;
				}
				return returnValue;

			}
		template<class T>
			nptr<T> getSuccessor(nptr<T> x){
				if(x == nullptr) return nullptr;
				if(x->right != nullptr)
					return getLeftmost(x->right);
				auto y = x->parent;
				while(y != nullptr && x == y->right){
					x = y;
					y = y->parent;
				}
				return y;
			}
		template<class T>
			nptr<T> getPredecessor(nptr<T> x){
				if(x == nullptr) return nullptr;
				if(x->left != nullptr){
					return getRightmost(x->left);
				}
				auto y = x->parent;
				while(y != nullptr && x == y->left){
					x = y;
					y = y->parent;
				}
				return y;
			}
		template<class T>
			struct BSTIterator{
				public:
					BSTIterator(){
						currentPointer == nullptr;
					}
					BSTIterator(nptr<T> position){
						currentPointer = position;
					}
					bool operator==(const BSTIterator & iter){
						return currentPointer == iter.currentPointer;
					}
					template<class v>
						bool operator+(v integralValue){
							while(integralValue--){
								if(currentPointer == nullptr) throw exception::noNextException("bst iterator");
								currentPointer = getSuccessor(currentPointer);
							}
						}

				private:
					nptr<T> currentPointer;

			};

	}
	template<class T>
		class MyBinarySearchTree{
			public:
			using iterator = my_bst::BSTIterator<T>;
			template<class iterator>
			MyBinarySearchTree(iterator begin, iterator end){
				sort(begin,end);
				constructTree(begin,end);
				beginIter = my_bst::BSTIterator(my_bst::getLeftmost(root));
				endIter = my_bst::BSTIterator(my_bst::getRightmost(root));
			}		
			
			iterator begin(){
				return beginIter;
			}
			iterator end(){
				return endIter;
			}

			private:
			using nptr = my_bst::nptr<T>;
			iterator beginIter;
			iterator endIter;
			nptr root;
			template<class iterator>
			void constructTree(iterator begin, iterator end){

			}


				
		};

}

#endif
