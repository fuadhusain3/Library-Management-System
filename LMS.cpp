#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
using namespace std;

#define MAX 100

class GUI
{
public:
    static void color(int c)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }
    static void title()
    {
        color(11);
        cout<< "\n=====================================\n";
        cout<< "      LIBRARY MANAGEMENT SYSTEM      \n";
        cout<< "=====================================\n";
        color(7);
    }
    static void line()
    {
        cout<< "-------------------------------------\n";
    }
};

struct borrowrecord
{
    int bookID;
    int daysLeft;
};

class Login
{
private:
    string user="admin";
    string pass="123";

public:
    bool check()
    {
        GUI::title();

        string u, p;
        cout<<"Username: ";
        cin>>u;
        cout<<"Password: ";
        cin>>p;

        return (u==user && p==pass);
    }
};

class Person
{
protected:

    int id;
    string name;

public:
    virtual void input()
    {
        cout<<"ID: ";
        cin>>id;
        cout<<"Name: ";
        cin>>name;
    }
    int getID()
    {
        return id;
    }
};

class Borrower : public Person
{
private:
    borrowrecord rec;

public:
    void input()
    {
        Person::input();
        
        cout<< "Book ID: ";
        cin>>rec.bookID;
        cout<< "Days left: ";
        cin>>rec.daysLeft;
    }
    void update()
    {
        cout<< "New name: ";
        cin>>name;
        cout<< "New days: ";
        cin>>rec.daysLeft;
    }
    void show()
    {
        cout << id << "\t"
             << name << "\t"
             << rec.bookID << "\t"
             << rec.daysLeft << endl;
    }
    void save(ofstream &f)
    {
        f << id << " "
          << name << " "
          << rec.bookID << " "
          << rec.daysLeft << endl;
    }
    void load(ifstream &f)
    {
        f >> id >> name >> rec.bookID >> rec.daysLeft;
    }
};

class Book
{
private:

    int id;
    string title;
    string author;
    int stock;

public:
    void input()
    {
        cout<<"Book ID: ";
        cin>>id;
        cout<<"Title: ";
        cin>>title;
        cout<<"Author: ";
        cin>>author;
        cout<<"Quantity: ";
        cin>>stock;
    }
    void show()
    {
        cout << id << "\t"
             << title << "\t"
             << author << "\t"
             << stock << endl;
    }
    void update()
    {
        cout<<"New title: ";
        cin>>title;
        cout<<"New author: ";
        cin>>author;
        cout<<"New quantity: ";
        cin>>stock;
    }
    int getID()
    {
        return id;
    }
    void save(ofstream &f)
    {
        f << id << " "
          << title << " "
          << author << " "
          << stock << endl;
    }
    void load(ifstream &f)
    {
        f >> id >> title >> author >> stock;
    }
};

class Library
{
private:
    Book books[MAX];
    Borrower borrowers[MAX];

    int bCount=0;
    int brCount=0;

public:
    Library()
    {
        loadBooks();
        loadBorrowers();
    }
    void saveBooks()
    {
        ofstream f("books.txt");
        f << bCount << endl;

        for(int i=0; i<bCount; i++)
            books[i].save(f);

        f.close();
    }
    void loadBooks()
    {
        ifstream f("books.txt");
        if(!f)
            return;

        f >> bCount;
        for(int i=0; i<bCount; i++)
            books[i].load(f);

        f.close();
    }
    void saveBorrowers()
    {
        ofstream f("borrowers.txt");
        f << brCount << endl;

        for(int i=0; i<brCount; i++)
            borrowers[i].save(f);

        f.close();
    }
    void loadBorrowers()
    {
        ifstream f("borrowers.txt");
        if (!f)
            return;
        f >> brCount;

        for(int i=0; i<brCount; i++)
            borrowers[i].load(f);

        f.close();
    }
    void enterStock()
    {
        books[bCount].input();
        bCount++;
        saveBooks();
    }
    void viewStock()
    {
        cout<<"\nBOOK STOCK\n";
        GUI::line();

        cout<<"ID\tTITLE\tAUTHOR\tQTY\n";
        GUI::line();

        for(int i=0; i<bCount; i++)
            books[i].show();
    }
    void addNewBook()
    {
        enterStock();
    }

    void updateBook()
    {
        int id;
        cin>>id;

        for(int i=0; i<bCount; i++)
        {
            if(books[i].getID() == id)
            {
                books[i].update();
                saveBooks();
                return;
            }
        }
    }
    
    void deleteBook()
    {
        int id;
        cin >> id;

        for(int i=0; i<bCount; i++)
        {
            if(books[i].getID()==id)
            {
                for(int j=i; j<bCount - 1; j++)
                    books[j]=books[j + 1];

                bCount--;
                saveBooks();
                return;
            }
        }
    }

    void bookDetails()
    {
        int id;
        cin >> id;
        cout << "ID\tTITLE\tAUTHOR\tQTY\n";

        for(int i=0; i<bCount; i++)
        {
            if (books[i].getID() == id)
                books[i].show();
        }
    }

    void registerBorrower()
    {
        borrowers[brCount].input();
        brCount++;
        saveBorrowers();
    }

    void updateBorrower()
    {
        int id;
        cin >> id;
        
        for(int i=0; i<brCount; i++)
        {
            if(borrowers[i].getID()==id)
            {
                borrowers[i].update();
                saveBorrowers();
                return;
            }
        }
    }

    void deleteBorrower()
    {
        int id;
        cin >> id;

        for(int i=0; i<brCount; i++)
        {
            if(borrowers[i].getID() == id)
            {
                for(int j=i; j<brCount-1; j++)
                    borrowers[j]=borrowers[j+1];

                brCount--;
                saveBorrowers();
                return;
            }
        }
    }

    void showDetails()
    {
        viewStock();
        cout << "\nBORROWERS\n";
        cout << "ID\tNAME\tBOOK\tDAYS\n";

        for(int i=0; i<brCount; i++)
            borrowers[i].show();
    }
    
    void borrowedTimeLeft()
    {
        cout<<"\nBORROWED TIME\n";

        for (int i=0; i<brCount; i++)
            borrowers[i].show();
    }
};

int main()
{
    Login L;
    if(!L.check())
        return 0;

    Library lib;
    int ch;

    while (1)
    {
        GUI::title();

        cout<<"\n1 Enter stock";
        cout<<"\n2 View stock";
        cout<<"\n3 Add book";
        cout<<"\n4 Update book";
        cout<<"\n5 Delete book";
        cout<<"\n6 Book details";
        cout<<"\n7 Register borrower";
        cout<<"\n8 Update borrower";
        cout<<"\n9 Delete borrower";
        cout<<"\n10 Show details";
        cout<<"\n11 Borrowed time";
        cout<<"\n12 Exit";

        cin >> ch;

        switch (ch)
        {
        case 1: lib.enterStock(); break;
        case 2: lib.viewStock(); break;
        case 3: lib.addNewBook(); break;
        case 4: lib.updateBook(); break;
        case 5: lib.deleteBook(); break;
        case 6: lib.bookDetails(); break;
        case 7: lib.registerBorrower(); break;
        case 8: lib.updateBorrower(); break;
        case 9: lib.deleteBorrower(); break;
        case 10: lib.showDetails(); break;
        case 11: lib.borrowedTimeLeft(); break;
        case 12: return 0;
        }
    }
}