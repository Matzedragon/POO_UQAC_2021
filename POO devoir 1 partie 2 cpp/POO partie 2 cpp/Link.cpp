#include "Link.h"

void Link::nouvellePartie()
{
	vie = 12;
	nbTriForce = 0;
}

void Link::ajouterInventaire(std::string id, std::string nom, std::string pouvoir)
{
	int i = 0;
	while (inventaire[i].id != "") { i++; };
	inventaire[i] = { id, nom, pouvoir };
}

void Link::supprimerInventaire(std::string idItem)
{
	int i = 0;
	while (inventaire[i].id != idItem && i < 3) {
		i++;
	}
	if (i < 3) {
		inventaire[i].id = "";
		inventaire[i].nom = "";
		inventaire[i].pouvoir = "";
	}

}

std::string Link::getInventaire() const
{
	std::string strInventaire = "Inventaire : \n";
	for (int i = 0; i < 3; i++) {
		if (inventaire[i].id == "") {
			strInventaire += " <Vide>\n";
		}
		else {
			strInventaire += " " +inventaire[i].id + " - " + inventaire[i].nom + " - " + inventaire[i].pouvoir + "\n";
		}
	}
	return strInventaire;
}

std::string Link::attaquerEpee() const
{
	return "attaque";
}

std::string Link::lancerBoomerang() const
{
	return "lance boomerang"; 
}

void Link::ajouterTriForce()
{
	if (nbTriForce < MAX_TRI_FORCE) {
		nbTriForce++;
	}
}

bool Link::peutAccederDonjonGanonPourSauverZelda() const
{
	if (nbTriForce == 8) {
		return true;
	}
	return false;
}

char Link::getDirection()
{
	return direction;
}

void Link::tournerNord()
{
	direction = 'N';
}

void Link::tournerSud()
{
	direction = 'S';
}

void Link::tournerOuest()
{
	direction = 'O';
}

void Link::tournerEst()
{
	direction = 'E';
}

int Link::getNombreVies() const
{
	return vie;
}

void Link::estBlesse(int dmg)
{
	if (vie-dmg < 0) {
		vie=0;
	}
	else {
		vie -= dmg;
	}
}

bool Link::enVie() const
{
	if (vie > 0) {
		return true;
	}
	else {
		return false;
	}

}
