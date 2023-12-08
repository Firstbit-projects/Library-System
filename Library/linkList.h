#pragma once
#include "node.cpp"
template<class T>
class LinkedList{
	Node<T>* start;
	
	public:
		LinkedList();
		void setStart(Node<T>*);
		Node<T>* getStart();
		void insertBeg(T&);
		void insertEnd(T&);
		void insertPos(int, T&);
		void deleteBeg();
		void deleteEnd();
		void deletePos(int);
		void deleteData(int);
		Node<T>* searchData(int);
		bool updateData(int);
		void maxData();
		void display();
		~LinkedList();
};
