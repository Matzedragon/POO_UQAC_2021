#include "Mario.h"
#include <iostream>
using namespace std;

Mario::Mario()
{
    invincible = false;
    etat = "petit";
    nom = "Mario";
}

Mario::Mario(std::string _nom)
{
    invincible = false;
    etat = "petit";
    nom = _nom;
}

Mario::Mario(const Mario &copied)
{
    cout << "constructeur par copie"<<endl;
    invincible = copied.estInvincible();
    etat = copied.getEtat();
    nom = copied.getNom();
}

Mario::~Mario()
{
    cout << "Destructor of Mario called" << endl;

}


void Mario::estBlesse()
{
    if (!estInvincible()) {
        if (etat == "petit") {
            etat = "mort";
        }
        else if (etat == "gros") {
            etat = "petit";
        }
        else if (etat == "grosBouleFeu" || etat == "grosBouleGlace") {
            etat = "gros";
        }
    }
}

std::string Mario::getEtat() const
{
    return etat;
}

bool Mario::estInvincible() const
{
    return invincible;
}

void Mario::mangerChampignon()
{
    if (etat == "petit") {
        etat = "gros";
    }
}

void Mario::mangerFleurFeu()
{
    etat = "grosBouleFeu";
}

void Mario::mangerFleurGlace()
{
    etat = "grosBouleGlace";
}

void Mario::attraperEtoile()
{
    invincible = true;
}

void Mario::finPouvoirEtoile()
{
    invincible = false;
}

std::string Mario::direPhraseVictoire()
{
    return "Victoire";
}

std::string Mario::getNom() const
{
    return nom;
}
