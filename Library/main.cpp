#include <iostream>
#include <fstream>
#include "linkList.cpp"
#include "book.h"
int main() {
	LinkedList<Book> lt;
	
	ifstream in("text.bin", ios::binary);
	if(in.is_open()){
		Book obj;
		while(in.read(reinterpret_cast<char*>(&obj), sizeof(obj))){
			lt.insertEnd(obj);
		}
		in.close();
	}
	else{
		cout<<"File opening for reading is fail!";
	}
	
	int choice=0;
	do{
		cout<<"\n\t\t1.Insert at Beginning";
		cout<<"\n\t\t2.Insert at End";
		cout<<"\n\t\t3.Display";
		cout<<"\n\t\t4.Insert at position";
		cout<<"\n\t\t5.Delete at Beginning";
		cout<<"\n\t\t6.Delete at End";
		cout<<"\n\t\t7.Delete at position";
		cout<<"\n\t\t8.Delete by Book id";
		cout<<"\n\t\t9.Manage book";
		cout<<"\n\t\t10.Exit\n";
		cin>>choice;
		int id;
		char name[25];
		char author[25];
		double price;
		double rating;

		switch(choice){
			case 1:{
				cout<<"Enter id: ";
				cin>>id;
				cout<<"Book name: ";
				fflush(stdin);
				gets(name);
				cout<<"Author name: ";
				gets(author);
				cout<<"Price: ";
				cin>>price;
				cout<<"rating: ";
				cin>>rating;
				Book bk(id, name, author, price, rating);
				lt.insertBeg(bk);
				break;
			}
			case 2:{
				cout<<"Enter id: ";
				cin>>id;
				cout<<"Book name: ";
				fflush(stdin);
				gets(name);
				cout<<"Author name: ";
				gets(author);
				cout<<"Price: ";
				cin>>price;
				cout<<"rating: ";
				cin>>rating;
				Book bk(id, name, author, price, rating);
				lt.insertEnd(bk);
				break;
			}
			case 3:{
				lt.display();
				break;
			}
			case 4:{
				int pos;
				cout<<"Enter position: ";
				cin>>pos;
				cout<<"Enter id: ";
				cin>>id;
				cout<<"Book name: ";
				fflush(stdin);
				gets(name);
				cout<<"Author name: ";
				gets(author);
				cout<<"Price: ";
				cin>>price;
				cout<<"rating: ";
				cin>>rating;
				Book bk(id, name, author, price, rating);
				lt.insertPos(pos, bk);
				break;
			}
			case 5:{
				lt.deleteBeg();
				break;
			}
			case 6:{
				lt.deleteEnd();
				break;
			}
			case 7:{
				int pos;
				cout<<"Enter position: ";
				cin>>pos;
				lt.deletePos(pos);
				break;
			}
			case 8:{
				int id;
				cout<<"Enter id to delete: ";
				cin>>id;
				lt.deleteData(id);
				break;
			}
			case 9:{
				int ch;
		        cout << "#----------------------------------------------------------------#\n";
		        cout << "#\tPress 1: Search a Book                                   #\n";
		        cout << "#----------------------------------------------------------------#\n";
		        cout << "#\tPress 2: Update price or rating of a Book                #\n";
		        cout << "#----------------------------------------------------------------#\n";
		        cout << "#\tPress 3: show a book with Max Price/Rating               #\n";
		        cout << "#----------------------------------------------------------------#\n";
		        cin>>ch;
				switch (ch) {
		            case 1:
					{
						if(lt.getStart() == NULL){
		            		cout<<"\nThere are no books to search!\n";
						}
						else{
							int id;
							cout<<"Enter id: ";
							cin>>id;
							lt.searchData(id);
						}
		                break;
		            }
		            case 2:
		            {
		            	if(lt.getStart() == NULL){
		            		cout<<"\nThere are no books to update!";
						}
						else{
							int id;
							cout<<"Enter id: ";
							cin>>id;
							if(!lt.updateData(id)){
								cout<<"Book not found!\n";
							}
						}
		                break;
		            }
		            case 3:{
		            	if(lt.getStart() == NULL){
		            		cout<<"\nThere are no books to show!";
						}
						else{
		                	lt.maxData();
						}
						break;
					}
		            default:
		                cout << "\nWrong choice****\n";
		                break;
		        }
				break;
			}
			case 10:{
				cout<<"\n--------End of Program--------\n";
				choice = 0;
				break;
			}
			default:{
				cout<<"\n-----Invalid Entry-----\n";
				break;
			}
		}
	}while(choice);

	ofstream out("text.bin", ios::binary);
	if(out.is_open()){
		Node<Book>* temp = lt.getStart();
		while(temp!=NULL){
			Book b = temp->getData();
			out.write(reinterpret_cast<char*>(&b), sizeof(b));
			temp = temp->getNext();
		}
		out.close();
	}
	else{
		cout<<"File opening for writing is fail!\n";
	}
	return 0;
}
