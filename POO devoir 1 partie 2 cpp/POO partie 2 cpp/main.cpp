#include <iostream>
#include "PacMan.h"
#include "Mario.h"
#include "Link.h"

using namespace std;

void testLink();
void testMario();
void testPacMan();

int main()
{
	testPacMan();
	testMario();
	testLink();

	cin.get();
	return 0;
}

void testLink()
{
	Link link;

	cout << endl << "--- test LINK ---" << endl;

	cout << " 01 - " << link.getNombreVies() << endl;
	link.nouvellePartie();
	cout << " 02 - " << link.getNombreVies() << endl;
	cout << " 03 - " << link.getInventaire() << endl;
	link.ajouterInventaire("45", "Medaillon en or", "Protege de 5 points de degat");
	link.ajouterInventaire("12", "Armure magique", "Protege de 20 points de degat");
	link.ajouterInventaire("01", "Botte elfique", "Deplacement silencieux");
	cout << " 04 - " << link.getInventaire() << endl;
	link.supprimerInventaire("12");
	cout << " 05 - " << link.getInventaire() << endl;
	cout << " 06 - " << link.attaquerEpee() << endl;
	cout << " 07 - " << link.lancerBoomerang() << endl;

	link.tournerEst();
	link.estBlesse(5);
	link.tournerOuest();
	link.tournerNord();
	link.estBlesse(2);
	link.tournerSud();
	cout << " 08 - " << link.getDirection() << endl;
	cout << " 09 - " << link.enVie() << endl;
	cout << " 10 - " << link.getNombreVies() << endl;

	while (!link.peutAccederDonjonGanonPourSauverZelda())
		link.ajouterTriForce();

	link.estBlesse(8);
	cout << " 11 - " << link.enVie() << endl;

	cout << endl;

}

void testMario()
{
	Mario mario;
	mario.nouvellePartie();

	cout << endl << "--- test MARIO ---" << endl;

	mario.mangerFleurFeu();
	cout << " 01 - " << mario.getEtat() << endl;
	mario.mangerFleurGlace();
	cout << " 02 - " << mario.estInvincible() << endl;
	mario.estBlesse();
	cout << " 03 - " << mario.getEtat() << endl;
	mario.attraperEtoile();
	mario.estBlesse();
	mario.estBlesse();
	cout << " 04 - " << mario.estInvincible() << endl;
	mario.estBlesse();
	mario.estBlesse();
	cout << " 05 - " << mario.getEtat() << endl;
	mario.finPouvoirEtoile();
	cout << " 06 - " << mario.estInvincible() << endl;
	mario.estBlesse();
	mario.mangerChampignon();
	mario.estBlesse();
	cout << " 07 - " << mario.direPhraseVictoire() << endl;
	mario.estBlesse();
	cout << " 08 - " << mario.getEtat() << endl;

	cout << endl;
}

void testPacMan()
{
	PacMan pacman;
	pacman.nouvellePartie();

	cout << endl << "--- test PACMAN ---" << endl;

	pacman.setDirection('H');
	cout << " 01 - " << pacman.getDirection() << endl;
	pacman.setDirection('C');
	cout << " 02 - " << pacman.getDirection() << endl;
	cout << " 03 - " << pacman.estInvincible() << endl;
	pacman.avalerSuperPacGomme();
	cout << " 04 - " << pacman.attaquer() << endl;
	pacman.finInvincibilite();
	cout << " 05 - " << pacman.attaquer() << endl;
	cout << " 06 - " << pacman.direPhraseVictoire() << endl;

	cout << endl;
}

