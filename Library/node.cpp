//#pragma once
#include "node.h"
template<class T>
Node<T>::Node(T data){
	this->data = data;
	this->next = NULL;
}
template<class T>
void Node<T>::setData(T data){
	this->data = data;
}
template<class T>
void Node<T>::setNext(Node* next){
	this->next = next;
}
template<class T>
T& Node<T>::getData(){
	return data;
}
template<class T>
Node<T>* Node<T>::getNext(){
	return next;
}

