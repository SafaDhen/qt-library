#ifndef BIBLIOTHEK_H
#define BIBLIOTHEK_H


#include "buch.h"
#include <vector>

class Bibliothek
{
private:
    std::vector<Buch*> buecher;
public:
    Bibliothek();
    ~Bibliothek();

    void buchAnlegen();
    void buchLoeschen(int id);
    void bestandAnzeigen() ;
    void buecherNachAuthorAnzeigen() ;
    void buchEmpfehlen();
    void bibliothekSpeichern( std::string& dateiname) ;
    void bibliothekLaden( std::string& dateiname);
    void buchAusleihen(int id,  std::string& ausleiher);
    void buchZurueckgeben(int id);
    void buchZurueckgeben(const std::string& entleiherName);
};

#endif // BIBLIOTHEK_H
