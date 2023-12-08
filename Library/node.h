#pragma once
#include <iostream>
using namespace std;
template<class T>
class Node{
	T data;
	Node* next;
	
	public:
		Node(T);
		void setData(T);
		void setNext(Node*);
		T& getData();
		Node* getNext();
};
