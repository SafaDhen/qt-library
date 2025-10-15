#ifndef BUCH_H
#define BUCH_H
#include <iostream>
using std::string;
class Buch{
private:
    const int id; // Unique book ID
    string nachname;
    string titel;

    static int nummer;
    string ausleiher;
    double preis;

public:

    Buch(string _nachname, string _titel, double preis);
    ~Buch();

    int getId() const;
    string getAutor() const;
    string getTitel() const ;
    string getAusleiher() const;
    double getPreis() const;
    bool istAusgeliehen() const;
    void ausleihen(string& ausleiher);
    void zurueckgeben();

    void display();
};

#endif // BUCH_H
