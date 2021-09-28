#include "PacMan.h"

PacMan::PacMan()
{
}

void PacMan::nouvellePartie()
{
    invincible = false;
    direction = 'H';
}



char PacMan::getDirection() const
{
    return direction;
}


void PacMan::setDirection(char d)
{
    if (d == 'H' || d == 'B' || d == 'G' || d == 'D') {
        direction = d;
    }
}

bool PacMan::estInvincible() const
{
    return invincible;
}

std::string PacMan::attaquer() const
{
    std::string attaque = ":-(";
    if (estInvincible()) {
        attaque = ":-)";
    }
    return attaque;
}

void PacMan::avalerSuperPacGomme()
{
    invincible = true;
}

void PacMan::finInvincibilite()
{
    invincible = false;
}

std::string PacMan::direPhraseVictoire() const
{
    return "victoire";
}
