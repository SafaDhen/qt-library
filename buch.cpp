#include "buch.h"
using std::cout;
using std::endl;

int Buch::nummer = 1;

Buch::Buch(std::string _nachname, std::string _titel, double preis)
    :id(nummer++), nachname(_nachname),titel(_titel), preis(preis){}


Buch::~Buch(){}

int Buch::getId() const{
    return id;
}

std::string Buch::getAutor() const{
    return nachname;
}

std::string Buch::getTitel() const{
    return titel;
}

std::string Buch::getAusleiher() const {
    return ausleiher;
}

double Buch::getPreis() const{
    return preis;
}

bool Buch::istAusgeliehen() const {
    return !ausleiher.empty();
}

void Buch::ausleihen( string& ausleiherName) {
    if (!istAusgeliehen()) {
        ausleiher = ausleiherName;
    } else {
        cout << "Buch ist bereits ausgeliehen." << endl;
    }
}

void Buch::zurueckgeben() {
    if (istAusgeliehen()) {
        ausleiher = "";
    } else {
        cout << "Buch ist nicht ausgeliehen." << endl;
    }
}

void Buch::display()  {
    cout << "ID: " << id << ", Autor: " << nachname << ", Titel: " << titel << ", Preis: " << preis;
    if (istAusgeliehen()) {
        cout << " (Ausgeliehen von: " << ausleiher << ")";
    }
    cout << endl;
}


