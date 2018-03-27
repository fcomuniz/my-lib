#ifndef MY_LIB_MY_BINARY_SEARCH_TREE
#define MY_LIB_MY_BINARY_SEARCH_TREE

#include <structures/exceptions/exceptions.h>

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
			virtual ~node(){
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
		nptr<T> getLeftmost(nptr<T> node){
			if(node == nullptr) throw my_lib::exception::empty_exception("getting leftmost");
			while(node->left != nullptr){
				node = node->left;
			}
			return node;
		}
		template<class T>
			nptr<T> getRightmost(nptr<T> node){
				if(node == nullptr) throw my_lib::exception::empty_exception("getting rightmost");
				while(node->right != nullptr){
					node = node->right;
				}
				return node;

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
			template<class T,class iterator>
			nptr<T> constructTree(iterator begin, iterator end, nptr<T> parent = nullptr){
				if(begin == end) return nullptr;
				int dist = end-begin-1;
				iterator middle = begin + (dist)/2;
				nptr<T> node = new my_lib::my_bst::node<T>(*middle);	
				node->left = constructTree<T>(begin,middle,node);
				node->right = constructTree<T>(middle+1,end,node);
				node->parent = parent;
				return node;
			}
			template<class T>
				void deleteTree(nptr<T> node){
					if(node == nullptr) return;
					deleteTree(node->left);
					deleteTree(node->right);
					delete node;
				}
		template<class T>
			struct BSTIterator{
				public:
					BSTIterator(){
						currentPointer = nullptr;
					}
					BSTIterator(nptr<T> position){
						currentPointer = position;
					}
					bool operator==(const BSTIterator & iter) const{
						return currentPointer == iter.currentPointer;
					}
					bool operator!=(const BSTIterator & iter) const{
						return !((*this)==iter);
					}
					template<class v>
						BSTIterator<T> operator+(v integralValue)const {
							auto ptr = currentPointer;
							while(integralValue--){
								if(ptr == nullptr) throw exception::noNextException("bst iterator");
								ptr = getSuccessor(ptr);
							}
							return BSTIterator(ptr);
						}
					BSTIterator<T> operator++(int a){
						return *this= this->operator+(1);
					}

					const T & operator*()const {
						return (*currentPointer).val;
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
			MyBinarySearchTree(iterator begin, iterator end): root(nullptr){
				sort(begin,end);
				constructTree(begin, end);
				if(root == nullptr){
				beginIter = my_bst::BSTIterator<T>(nullptr);
				}else {
				beginIter = my_bst::BSTIterator<T>(my_bst::getLeftmost(root));
				}
				endIter = my_bst::BSTIterator<T>(nullptr);
			}		
			
			iterator begin(){
				return beginIter;
			}
			iterator end(){
				return endIter;
			}


			protected:
			template<class c_f>
			void traverseTree(c_f visitFunction){
				my_bst::InorderTraversal(root,visitFunction);
			}

			private:
			
			using nptr = my_bst::nptr<T>;
			template<class iterator>
				void constructTree(iterator begin, iterator end){
					if(root != nullptr) delete root;
					root = nullptr;
					root = my_bst::constructTree<T>(begin,end);
				}
			iterator beginIter;
			iterator endIter;
			nptr root;
		};

}

#endif
