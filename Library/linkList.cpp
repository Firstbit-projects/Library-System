#include "linkList.h"
#include "book.h"
template<class T>
LinkedList<T>::LinkedList(){
	start=NULL;
}
template<class T>
void LinkedList<T>::setStart(Node<T>* start){
	this->start = start;
}
template<class T>
Node<T>* LinkedList<T>::getStart(){
	return start;
}
template<class T>
void LinkedList<T>::insertBeg(T& data){
	
	Node<T>* temp = new Node<T>(data);
	temp->setNext(start);
	
	start = temp;
}
template<class T>
void LinkedList<T>::insertEnd(T& data){
	Node<T>* temp = new Node<T>(data);
	if(start==NULL){
		start = temp;
	}
	else{
		Node<T>* p = start;
		while(p->getNext()!=NULL){
			p = p->getNext();
		}
		p->setNext(temp);
	}
}
template<class T>
void LinkedList<T>::insertPos(int pos, T& data){
	Node<T>* temp = new Node<T>(data);
	if(start==NULL){
		cout<<"Linked list is empty...\nNode added to the first position";
		start = temp;
		return;
	}
	else if(pos==1){
		temp->setNext(start);
		start = temp;
		return;
	}
	else{
		Node<T>* p = start;
		int i=1;
		while(p->getNext()!=NULL && i<pos-1){
			p = p->getNext();
			i++;
		}
		temp->setNext(p->getNext());
		p->setNext(temp);
		return;
	}
}
template<class T>
void LinkedList<T>::deleteBeg(){
	if(start==NULL){
		cout<<"List is empty!!!\n";
		return;
	}
	else{
		Node<T>* temp=start;
		start = start->getNext();
		delete temp;
		cout<<"Success...\n";
		return;
	}
}
template<class T>
void LinkedList<T>::deleteEnd(){
	if(start==NULL){
		cout<<"List is empty!!!\n";
		return;
	}
	else{
		Node<T>* p = start;
		if(p->getNext()==NULL){
			start = NULL;
			delete p;
		}
		else{
			while(p->getNext()->getNext()!=NULL){
				p=p->getNext();
			}
			
			delete p->getNext();
			p->setNext(NULL);
			return;
		}
		cout<<"Success...\n";
	}
}
template<class T>
void LinkedList<T>::deletePos(int pos){
	if(start==NULL){
		cout<<"List is empty!!!\n";
		return;
	}
	if(start->getNext()==NULL){
		Node<T>* temp=start;
		delete temp;
		start=NULL;
		return;
	}
	if(pos==1){
		Node<T>* temp=start;
		start = start->getNext();
		delete temp;
		return;
	}
	else{
		int i=1;
		Node<T>* p = start;
		while(p->getNext()!=NULL && i<pos-1){
			p=p->getNext();
			i++;
		}
		if(i==pos-1){
			Node<T>* temp = p->getNext();
			p->setNext(temp->getNext());
			delete temp;
			cout<<"Success...\n";
		}
		else{
			cout<<"Invalid postion!!!\n";
		}
		return;
	}
}
template<class T>
void LinkedList<T>::deleteData(int id){
	if(start==NULL){
		cout<<"\nThere no Element!!!\n";
		return;
	}
	else if(start->getData().getId() == id){
		Node<T>* temp = start;
		start = start->getNext();
		delete temp;
		cout<<"Success...\n";
		return;
	}
	else{
		Node<T>* p = start;
		while(p->getNext() != NULL){
			if(p->getNext()->getData().getId() == id)
			{
				Node<T>* temp = p->getNext();
				p->setNext(temp->getNext());
				delete temp;
				cout<<"Success...\n";
				break;
			}
			p = p->getNext();
		}
		return;
	}
}
template<class T>
void LinkedList<T>::display(){
	if(start==NULL){
		cout<<"\nThere no Element!!!\n";
	}
	else{
		Node<T>* p = start;
		while(p!=NULL){
//			cout<<p->getData();
//			cout<<"\t"<<p->getData();
			p->getData().displayBook();
			p = p->getNext();
		}
	}
}
template<class T>
Node<T>* LinkedList<T>::searchData(int id){
	if(start==NULL){
		cout<<"There is no data\n";
		return NULL;
	}
	else{
		Node<T>* p = start;
		if(p->getData().getId()==id){
			p->getData().displayBook();
			return p;
		}
		else{
			while(p->getNext()!=NULL){
				if(p->getData().getId()==id){
					p->getData().displayBook();
					return p;
				}
				p=p->getNext();
			}
			if(p->getData().getId()==id){
				p->getData().displayBook();
				return p;
			}
		}
		return NULL;
	}
}

template<class T>
bool LinkedList<T>::updateData(int id){
	Node<T>* p = searchData(id);
	if(p==NULL){
		return false;
	}
	else{
		p->getData().updateBook();
		return true;
	}
}

template<class T>
void LinkedList<T>::maxData(){
	if(start!=NULL){
		Node<T>* p = start;
		
		double maxPrice = p->getData().getPrice();
	    double maxRating = p->getData().getRating();
	    Node<T>* temp = p;
		
	    int choice;
	    cout << "Price or Rating: \n";
	    cout << "press 1: Price \npress 2: Rating \n";
	    cin >> choice;
	
	    if (choice == 1) {
	        while(p->getNext()!=NULL) {
	            if (p->getData().getPrice() > maxPrice) {
	                maxPrice = p->getData().getPrice();
	                temp = p;
	            }
	            p=p->getNext();
	        }
	        if (p->getData().getPrice() > maxPrice) {
                maxPrice = p->getData().getPrice();
                temp = p;
	        }
	        cout << "\nBook with maximum price is:-" << endl;
	        temp->getData().displayBook();
	    } 
		else if (choice == 2) {
	        while(p->getNext()!=NULL) {
	            if (p->getData().getRating() > maxRating) {
	                maxRating = p->getData().getRating();
	                temp = p;
	            }
	            p = p->getNext();
	        }
	        if (p->getData().getRating() > maxRating) {
                maxRating = p->getData().getRating();
                temp = p;
            }
	        cout << "\nBook with maximum rating is:-" << endl;
	        temp->getData().displayBook();
	    } 
		else {
	        cout << "\nWrong choice**" << endl;
	    }
	}
}

template<class T>
LinkedList<T>::~LinkedList(){
	
	Node<T>* p = start->getNext();
	delete start;
	while(p->getNext()!=NULL){
		Node<T>* temp = p;
		p=p->getNext();
		delete temp;
	}
}

