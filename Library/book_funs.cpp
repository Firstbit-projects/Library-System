
#include "book.h"
#include <iomanip>
using namespace std;

//Setters
Book::Book(){
	id = 0;
	strcpy(this->name, "not given");
	strcpy(this->author, "not given");
	price = 0.0;
	rating = 0.0;
}
Book::Book(int id, char* name, char* author, double price, double rating){
	this->id = id;
	strcpy(this->name, name);
	strcpy(this->author, author);
	this->price = price;
	this->rating = rating;
}
void Book::setId(int id) {
this->id = id;
}

void Book::setName(const char* name) {
    strcpy(this->name, name);
}

void Book::setAuthor(const char* author) {
    strcpy(this->author, author);
}

void Book::setPrice(double price) {
    this->price = price;
}

void Book::setRating(double rating) {
    this->rating = rating;
}

//Getters
int Book::getId(){
    return id;
}

const char* Book::getName(){
    return name;
}

const char* Book::getAuthor(){
    return author;
}

double Book::getPrice(){
    return price;
}

double Book::getRating(){
    return rating;
}

void Book::updateBook(){
    int choice;
    cout << "What do you want to update-" << endl;
    cout << "Press 1: Price" << endl;
    cout << "Press 2: Rating" << endl;
    cin >> choice;
    
    if (choice == 1){
        cout << "Enter new Price: ";
        cin >> this->price;
    } else if (choice == 2){
        cout << "Enter new rating: ";
        cin >> this->rating;
    }
    
    cout << "\nUpdated book: " << endl;
    this->displayBook();
}

//display book
void Book::displayBook(){			
	cout << "+----------------------------------------------------------------+" << endl;
    cout << "|    Book id    : "  << this->id << endl;
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|    Book Name  : "  << this->name  << endl;
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|    Author Name: " << this->author<< endl;
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|    Price      : "  << fixed << setprecision(2) << this->price  << endl;
    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|    Rank       : "  << fixed << setprecision(2) << this->rating<< endl;
    cout << "+----------------------------------------------------------------+" << endl;
}




//Gloabal functions
void addBook(Book*& bs, int& n) {

    int id;
	char name[25];
	char author[25];
	double price;
	double rating;
    
    cout << "Enter book id    : ";
    cin >> id;
    cout << "Enter book Name  : ";
    cin.ignore();
    cin.getline(name, sizeof(name));
    cout << "Enter author name: ";
    cin.getline(author, sizeof(author));
    cout << "Enter price      : ";
    cin >> price;
    cout << "Enter rank       : ";
    cin >> rating;
    
    n++;
    bs[n].setId(id);
    bs[n].setName(name);
    bs[n].setAuthor(author);
    bs[n].setPrice(price);
    bs[n].setRating(rating);
    
    cout << "\nAdded book is:-" << endl;
    bs[n].displayBook();
}



//search by id
int searchById(Book* bs, int n) {
    int id, i;
    cout << "Enter id            : ";
    cin >> id;
    
    for (i = 0; i <= n; ++i) {
        if (id == bs[i].getId()) {
            cout << "Found" << endl;
            bs[i].displayBook();
            return i;
        }
    }
    
    return -1;
}

//search by name
int searchByName(Book* bs, int n) {
    char name[50];
    int i;
    cout << "Enter book Name     : ";
    cin.ignore();
    cin.getline(name, sizeof(name));
    
    for (i = 0; i <= n; ++i) {
        if (strcasecmp(bs[i].getName(), name) == 0) {
            cout << "Found" << endl;
            bs[i].displayBook();\
            return i;
        }
    }
    
    return i;
}



//remove book
void removeBook(Book* bs, int& n, int indexToRemove) {
    if (indexToRemove < 0 || indexToRemove >= n) {
        cout << "Invalid index to remove." << endl;
        return;
    }
    
    for (int i = indexToRemove; i <= n - 1; ++i) {
        bs[i] = bs[i + 1];
    }
    
    n--;
    cout << "\nBook Removed" << endl;
}

//maximum price and rating
void maximum(Book* bs, int n){
	cout<<"n: "<<n<<endl;
	int i;
    double maxPrice = bs[0].getPrice();
    double maxRating = bs[0].getRating();
    int maxPriceIndex = 0;
    int maxRatingIndex = 0;
	
    int choice;
    cout << "Price or Rating: \n";
    cout << "press 1: Price \npress 2: Rating \n";
    cin >> choice;

    if (choice == 1) {
        for (i = 1; i <= n; i++) {
            if (bs[i].getPrice() > maxPrice) {
            	cout<<"hiiii";
                maxPrice = bs[i].getPrice();
                maxPriceIndex = i;
            }
        }
        cout << "\nBook with maximum price is:-" << endl;
        bs[maxPriceIndex].displayBook();
        // Call your displayBook function here if needed
    } else if (choice == 2) {
        for (i = 1; i <= n; i++) {
            if (bs[i].getRating() > maxRating) {
                maxRating = bs[i].getRating();
                maxRatingIndex = i;
            }
        }
        cout << "\nBook with maximum rating is:-" << endl;
        // Call your displayBook function here if needed
        bs[maxRatingIndex].displayBook();
    } else {
        cout << "\nWrong choice**" << endl;
    }
}


//top 3 price or rating of book
void top3(Book* bs, int n) {
    double maxPrice1 = 0, maxPrice2 = 0, maxPrice3 = 0;
    double maxRating1 = 0, maxRating2 = 0, maxRating3 = 0;
    int index1 = -1, index2 = -1, index3 = -1;
    int choice;

    cout << "Price or Rating: \n";
    cout << "press 1: Price \npress 2: Rating \n";
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i <= n; ++i) {
            if (bs[i].getPrice() > maxPrice1) {
                maxPrice3 = maxPrice2;
                maxPrice2 = maxPrice1;
                maxPrice1 = bs[i].getPrice();

                index3 = index2;
                index2 = index1;
                index1 = i;
            } else if (bs[i].getPrice() > maxPrice2 && bs[i].getPrice() != maxPrice1) {
                maxPrice2 = bs[i].getPrice();
                index2 = i;
            } else if (bs[i].getPrice() > maxPrice3 && bs[i].getPrice() != maxPrice2) {
                maxPrice3 = bs[i].getPrice();
                index3 = i;
            }
        }
    } else if (choice == 2) {
        for (int i = 0; i <= n; ++i) {
            if (bs[i].getRating() > maxRating1) {
                maxRating3 = maxRating2;
                maxRating2 = maxRating1;
                maxRating1 = bs[i].getRating();

                index3 = index2;
                index2 = index1;
                index1 = i;
            } else if (bs[i].getRating() > maxRating2 && bs[i].getRating() != maxRating1) {
                maxRating2 = bs[i].getRating();
                index2 = i;
            } else if (bs[i].getRating() > maxRating3 && bs[i].getRating() != maxRating2) {
                maxRating3 = bs[i].getRating();
                index3 = i;
            }
        }
    }
	
	cout << "\nTop 3 are:-" << endl;
    if (index1 != -1) {
        bs[index1].displayBook();
    }
    if (index2 != -1) {
        bs[index2].displayBook();
    }
    if (index3 != -1) {
        bs[index3].displayBook();
    }
}
//setbook
void setBooks(Book* bs) {
    bs[0].setId(1);
    bs[0].setName("Do epic shit");
    bs[0].setAuthor("Ankur Warikoo");
    bs[0].setPrice(399.00);
    bs[0].setRating(4.6);

    bs[1].setId(2);
    bs[1].setName("Mrityunjay");
    bs[1].setAuthor("Shivaji Sawant");
    bs[1].setPrice(150.75);
    bs[1].setRating(4.6);

    bs[2].setId(3);
    bs[2].setName("Yayati");
    bs[2].setAuthor("V.S. Khandekar");
    bs[2].setPrice(95.99);
    bs[2].setRating(4.4);

    bs[3].setId(4);
    bs[3].setName("Shyamchi Aai");
    bs[3].setAuthor("Sane Guruji");
    bs[3].setPrice(80.00);
    bs[3].setRating(4.8);

    bs[4].setId(5);
    bs[4].setName("Batatyachi Chal");
    bs[4].setAuthor("P. L. Deshpande");
    bs[4].setPrice(75.99);
    bs[4].setRating(4.2);

    bs[5].setId(6);
    bs[5].setName("Nathmadhav");
    bs[5].setAuthor("Nath Madhav");
    bs[5].setPrice(65.75);
    bs[5].setRating(4.5);

    bs[6].setId(7);
    bs[6].setName("Sukhachya Sarini He Manashi");
    bs[6].setAuthor("Vrinda Bal");
    bs[6].setPrice(50.50);
    bs[6].setRating(4.7);

    bs[7].setId(8);
    bs[7].setName("Vyakti Ani Valli");
    bs[7].setAuthor("P. L. Deshpande");
    bs[7].setPrice(70.00);
    bs[7].setRating(4.4);
}

//ostream& operator<<(ostream& cout, Book& b){
//	b.displayBook();
//	return cout;
//}
