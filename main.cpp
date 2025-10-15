#include "bibliothek.h"
#include <iostream>
#include <string>
#include "buch.h"

using namespace std;

int main() {
    Bibliothek bibliothek;
    char wahl;
    while(true){
        cout << "|================================|" <<endl;
        cout << "|      Bibliotheksverwaltung     |" <<endl;
        cout << "|================================|" <<endl;
        cout << "|(1) Buch anlegen                |" <<endl;
        cout << "|(2) Buch loeschen               |" <<endl;
        cout << "|(3) Bestand anzeigen            |" <<endl;
        cout << "|(4) Buecher nach Autor anzeigen |" <<endl;
        cout << "|(5) Buch empfehlen              |" <<endl;
        cout << "|(6) Bibliothek speichern        |" <<endl;
        cout << "|(7) Bibliothek laden            |" <<endl;
        cout << "|(8) Buch ausleihen              |" <<endl;
        cout << "|(9) Buch zurueckgeben           |" <<endl;
        cout << "|(0) Programm verlassen          |" <<endl;
        cout << "|================================|" <<endl;
        cout << "Ihre Wahl: ";
        cin >> wahl;

        switch (wahl) {
        case '1':{
            bibliothek.buchAnlegen();
            break;
        }
        case '2': {
            int id;
            cout << "Geben Sie die ID des zu löschenden Buches ein: ";
            cin >> id;
            bibliothek.buchLoeschen(id);
            break;
        }
        case '3':{
            bibliothek.bestandAnzeigen();
            break;
        }
        case '4':{
            bibliothek.buecherNachAuthorAnzeigen();
            break;
        }
        case '5':{
            bibliothek.buchEmpfehlen();
            break;
        }
        case '6': {
            string dateiname;
            cout << "Geben Sie den Dateinamen zum Speichern ein (z.B. Buchverwaltung.txt): ";
            cin >> dateiname;
            bibliothek.bibliothekSpeichern(dateiname);
            break;
        }
        case '7': {
            string dateiname;
            cout << "Geben Sie den Dateinamen zum Laden ein (z.B. Buchverwaltung.txt): ";
            cin >> dateiname;
            bibliothek.bibliothekLaden(dateiname);
            break;
        }
        case '8': {
            int id;
            string ausleiher;
            cout << "Geben Sie die ID des Buches ein: ";
            cin >> id;
            cout << "Geben Sie den Namen des Ausleihers ein: ";
            cin.ignore();
            getline(cin, ausleiher);
            bibliothek.buchAusleihen(id, ausleiher);
            break;
        }
        case '9': {
            string name;
            cout << "Geben Sie Ihren Namen ein: ";
            cin >>name;
            bibliothek.buchZurueckgeben(name);
            break;
        }
        case '0':{
            cout << "Programm wird beendet.\n";
            exit(0);
        }
        default:{
            cout << "Ungueltige Wahl. Bitte erneut versuchen.\n";
            break;
        }
        }
    }

    return 0;
}
