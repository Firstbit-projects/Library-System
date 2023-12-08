#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class Book
{
	int id;
	char name[25];
	char author[25];
	double price;
	double rating;
	
	public:
		Book();
		Book(int , char* , char* , double , double );
		//Setters
		void setId(int id);
	
	    void setName(const char* name);
	
	    void setAuthor(const char* author);
	
	    void setPrice(double price);
	
	    void setRating(double rating);
	
	    //Getters
	    int getId();
	
	    const char* getName();
	
	    const char* getAuthor();
	
	    double getPrice();
	
	    double getRating();
	    
	    void updateBook();
	    
		//display book
		void displayBook();
		
		
};


int searchById(Book*, int );
int searchByName(Book*, int );
void removeBook(Book* , int& , int );
void maximum(Book* , int );
void top3(Book* , int );
void addBook(Book*& , int& );
void setBooks(Book* );

