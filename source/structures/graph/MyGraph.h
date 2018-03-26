#include <map>
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
template<class T>
struct MyGraphNode;

template<class T>
using MGNPtr = MyGraphNode<T> *;

template<class T>
struct MyGraphNode{
	MyGraphNode(){}
	MyGraphNode(T data) : data(data){

	}
	T data;
	std::vector<MGNPtr<T>> adj;
	std::vector<MGNPtr<T>> incoming;
	friend std::istream & operator>>(std::istream & stream, MyGraphNode & node){
		return stream >> node.data;
	}
};

template<class T, class Container = std::map<T,MGNPtr<T>>>
struct MyGraph{
	virtual ~MyGraph(){
		clearNodes();
	}
	Container nodes;
	void clearNodes(){
		for(auto & val : nodes){
			delete val.second;
			val.second = nullptr;
		}
		nodes.clear();
	}
	
	template<class F>
	void dfs(F visitFunction){
		std::set<MGNPtr<T>> hasVisited;	
		for(auto iter = nodes.begin(), end = nodes.end(); iter != end; iter++){
			dfs(visitFunction, hasVisited, (*iter).second);
		}
	}
	template<class F>
	void bfs(F visitFunction){
		std::queue<MGNPtr<T>> q;
		std::set<MGNPtr<T>> hasVisited;
		for(auto iter = nodes.begin(), end = nodes.end(); iter != end; iter++){
			if(hasVisited.count(iter->second) > 0){
				
			} else {
				q.push(iter->second);
				while(!q.empty()){
					auto v = q.front();
					q.pop();	
					if(hasVisited.count(v) > 0) continue;
					hasVisited.insert(v);
					visitFunction(v->data);				
					for(auto & node : v->adj){
						q.push(node);
					}	
				}
			}
		}

	}
private:

	template<class F>
	void dfs(F visitFunction, std::set<MGNPtr<T>> & hasVisited, MGNPtr<T> node){
		if(node == nullptr) return;
		if(hasVisited.count(node)){
			return;
		}
		hasVisited.insert(node);
		visitFunction(node->data);
		auto & adjs = node->adj;
		for(auto iter = adjs.begin(), end = adjs.end(); iter != end; iter++){
			dfs(visitFunction,hasVisited,*iter);
		}
	}
	
	
};

/**
 * Initializes a graph given a istream, it gets in the first line all the nodes, and in the subsequent lines gets each of the connections
 * **/
template<class T>
void initializeGraph(MyGraph<T> & graph, std::istream & stream = std::cin){
	 graph.clearNodes();
         std::string a;
	 getline(stream,a);    
	 T val;
	 std::stringstream ss; 
	 ss.str(a);          
	 while(ss >> val){
		 graph.nodes.emplace(std::make_pair(val,new MyGraphNode<T>(val)));
		 	 
	 }
	 while(getline(stream,a)){
		 ss.clear();
		 ss.str(a);
		 T pos;
		 ss >> pos;
		 try{
			 auto auxPtr = graph.nodes.at(pos);
			 while(ss >> val){
				 auxPtr->adj.push_back(graph.nodes.at(val));
				 
			 }   
			 
		 } catch(std::exception & e){ 
			 std::cerr << e.what() << std::endl;
		 }
		 
	 }
	 return;
}

template<class T>
void printGraph(MyGraph<T> & graph, std::ostream & stream = std::cout){
	for(auto & elem : graph.nodes){
		stream << elem.first << ": ";
			for(auto & auxElem : elem.second->adj){
				stream << auxElem->data << " ";
			
			}   
		stream << std::endl;
	
	}   
		
}



