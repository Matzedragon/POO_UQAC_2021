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
	Link *link = new Link();
	Link *cloneLink(link);

	cout << endl << "--- test LINK ---" << endl;

	cout << " 01 - " << link->getNombreVies() << endl;
	cout << " 02 - " << link->getNombreVies() << endl;
	cout << " 03 - " << link->getInventaire() << endl;
	link->ajouterInventaire("45", "Medaillon en or", "Protege de 5 points de degat");
	link->ajouterInventaire("12", "Armure magique", "Protege de 20 points de degat");
	link->ajouterInventaire("01", "Botte elfique", "Deplacement silencieux");
	cout << " 04 - " << link->getInventaire() << endl;
	link->supprimerInventaire("12");
	cout << " 05 - " << link->getInventaire() << endl;
	cout << " 06 - " << link->attaquerEpee() << endl;
	cout << " 07 - " << link->lancerBoomerang() << endl;

	link->tournerEst();
	link->estBlesse(5);
	link->tournerOuest();
	link->tournerNord();
	link->estBlesse(2);
	link->tournerSud();
	cout << " 08 - " << link->getDirection() << endl;
	cout << " 09 - " << link->enVie() << endl;
	cout << " 10 - " << link->getNombreVies() << endl;

	while (!link->peutAccederDonjonGanonPourSauverZelda())
		link->ajouterTriForce();

	link->estBlesse(8);
	cout << " 11 - " << link->enVie() << endl;
	// test du constructeur par copie
	cloneLink = new Link(*link);
	link->estBlesse(2);
	link->tournerSud();
	cloneLink->tournerNord();
	cout << " 12 - " << "link : " << link->getDirection() << " clone : " <<  cloneLink->getDirection() << endl;

	cout << endl;
	// delete the objet 
	delete link, cloneLink;
}

void testMario()
{
	cout << endl << "--- test MARIO ---" << endl;
	Mario* tableauMario[3] = { new Mario("Luigi") };
	// création de deux Luigi à partir de celui présent dans la première case du tableau 
	tableauMario[1] = new Mario(*tableauMario[0]);
	tableauMario[2] = new Mario(*tableauMario[0]);

	
	// test du devoir #2 effectué sur le luigi original (1ere case du tableau).
	tableauMario[0]->mangerFleurFeu();
	cout << " 01 - " << tableauMario[0]->getEtat() << endl;
	tableauMario[0]->mangerFleurGlace();
	cout << " 02 - " << tableauMario[0]->estInvincible() << endl;
	tableauMario[0]->estBlesse();
	cout << " 03 - " << tableauMario[0]->getEtat() << endl;
	tableauMario[0]->attraperEtoile();
	tableauMario[0]->estBlesse();
	tableauMario[0]->estBlesse();
	cout << " 04 - " << tableauMario[0]->estInvincible() << endl;
	tableauMario[0]->estBlesse();
	tableauMario[0]->estBlesse();
	cout << " 05 - " << tableauMario[0]->getEtat() << endl;
	tableauMario[0]->finPouvoirEtoile();
	cout << " 06 - " << tableauMario[0]->estInvincible() << endl;
	tableauMario[0]->estBlesse();
	tableauMario[0]->mangerChampignon();
	tableauMario[0]->estBlesse();
	cout << " 07 - " << tableauMario[0]->direPhraseVictoire() << endl;
	tableauMario[0]->estBlesse();
	cout << " 08 - " << tableauMario[0]->getEtat() << endl;

	cout << endl;
	delete tableauMario[0];
	delete tableauMario[1];
	delete tableauMario[2];
}

void testPacMan()
{
	PacMan * pacman = new PacMan();

	cout << endl << "--- test PACMAN ---" << endl;

	pacman->setDirection('H');
	cout << " 01 - " << pacman->getDirection() << endl;
	pacman->setDirection('C');
	cout << " 02 - " << pacman->getDirection() << endl;
	cout << " 03 - " << pacman->estInvincible() << endl;
	pacman->avalerSuperPacGomme();
	cout << " 04 - " << pacman->attaquer() << endl;
	pacman->finInvincibilite();
	cout << " 05 - " << pacman->attaquer() << endl;
	cout << " 06 - " << pacman->direPhraseVictoire() << endl;

	cout << endl;
	delete pacman;
}

