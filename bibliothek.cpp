#include "bibliothek.h"
#include <algorithm>
#include <fstream>
#include <sstream>

using std::cout;
using std::getline;
using std::cin;
using std::endl;

Bibliothek::Bibliothek(){}

Bibliothek::~Bibliothek(){
    for(Buch* b : buecher){
        delete b;
    }
}

void Bibliothek::buchAnlegen(){

    std::string nachname, titel;
    double preis;
    cout << "Autor eingeben: ";
    cin >>nachname;

    cout<<"Titel eingeben: ";
    cin.ignore();
    getline(cin, titel);

    cout<<"Preis eingeben: ";
    cin >> preis;


    buecher.push_back(new Buch(nachname,titel,preis));
    cout <<"Buch erfolgreich angelegt!"<<endl;

}

void Bibliothek::buchLoeschen(int id){
    //lambda funktion
    auto it = find_if(buecher.begin(), buecher.end(), [id](Buch* buch) {
        return buch->getId() == id && !buch->istAusgeliehen(); });

    if(it != buecher.end()){
        delete *it;
        buecher.erase(it);
        cout<< "Buch geloescht"<<endl;
    }
    else{
        cout << " Buch mit id: " << id << "koennte nicht gefunden werden." << endl;
    }
}

void Bibliothek::bestandAnzeigen()  {
    cout << "Aktueller Bestand:\n";
    for ( Buch* b : buecher) {
        b->display();
    }
}

void Bibliothek::buecherNachAuthorAnzeigen()  {
    std::vector<Buch*> sortierteBuecher = buecher;
    // lambda funktion
    sort(sortierteBuecher.begin(), sortierteBuecher.end(), [](Buch* a, Buch* b) {
        return a->getAutor() < b->getAutor();
    });

    for (Buch* b : sortierteBuecher) {
        b->display();
    }
}

void Bibliothek::buchEmpfehlen() {
    std::string autor;
    cout << "Geben Sie den Autor ein (oder lassen Sie es leer fuer eine zufaellige Empfehlung): ";
    cin.ignore();
    getline(cin, autor);

    std::vector<Buch*> passendeBuecher;

    if (!autor.empty()) {
        for (Buch* buch : buecher) {
            if (buch->getAutor() == autor && !buch->istAusgeliehen()) {
                passendeBuecher.push_back(buch);
            }
        }
    } else {
        for (Buch* buch : buecher) {
            if (!buch->istAusgeliehen()) {
                passendeBuecher.push_back(buch);
            }
        }
    }

    if (!passendeBuecher.empty()) {
        int index = rand() % passendeBuecher.size();
        cout << "Buchempfehlung:\n";
        passendeBuecher[index]->display();
    } else {
        cout << "Keine passenden Buecher gefunden.\n";
    }
}

void Bibliothek::bibliothekSpeichern( std::string& dateiname)  {
    std::ofstream file(dateiname);
    if (!file.is_open()) {
        cout << "Fehler beim Oeffnen der Datei."<<endl;
        return;
    }

    for (const Buch* buch : buecher) {
        file << buch->getAutor() << ";" << buch->getTitel() << ";" << buch->getId()<<";"<<buch->getPreis() << endl;
    }

    file.close();
    cout << "Bibliothek wurde erfolgreich gespeichert.\n";
}

void Bibliothek::bibliothekLaden( std::string& dateiname) {
    std::ifstream file(dateiname);
    if (!file.is_open()) {
        cout << "Fehler beim Oeffnen der Datei." << endl;
        return;
    }

    for (Buch* buch : buecher) {
        delete buch;
    }
    buecher.clear();

    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string autor, titel, id,preisStg;
        double preis;
        getline(ss, autor, ';');
        getline(ss, titel, ';');
        getline(ss, id, ';');
        getline(ss,preisStg,';');
        preis=std::stod(preisStg);
        buecher.push_back(new Buch(autor, titel,preis));
    }

    file.close();
    cout << "Bibliothek wurde erfolgreich geladen." << endl;
}


void Bibliothek::buchAusleihen(int id, std::string& ausleiher) {
    for (Buch* buch : buecher) {
        if (buch->getId() == id && !buch->istAusgeliehen()) {
            buch->ausleihen(ausleiher);
            cout << "Buch wurde ausgeliehen." << endl;
            return;
        }
    }
    cout << "Buch nicht gefunden oder bereits ausgeliehen." << endl;
}
/*
void Bibliothek::buchZurueckgeben(int id) {
    for (Buch* buch : buecher) {
        if (buch->getId() == id && buch->istAusgeliehen()) {
            buch->zurueckgeben();
            cout << "Buch wurde zurueckgegeben." << endl;
            return;
        }
    }
    cout << "Buch nicht gefunden oder nicht ausgeliehen." << endl;
}
*/
void Bibliothek::buchZurueckgeben(const std::string& entleiherName) {
    for (Buch* buch : buecher) {
        if (buch->istAusgeliehen() && buch->getAusleiher() == entleiherName) {
            buch->zurueckgeben();
            cout << "Buch wurde zurueckgegeben." << endl;
            return;
        }
    }
    cout << "Kein Buch gefunden, das von '" << entleiherName << "' ausgeliehen wurde." << endl;
}
