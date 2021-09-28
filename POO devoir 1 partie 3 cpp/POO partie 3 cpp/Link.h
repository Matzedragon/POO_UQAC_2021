#pragma once

#include <string>
class Link
{
private:
	struct item {
		std::string id;
		std::string nom;
		std::string pouvoir;
	};
	char *direction;
	int vie;
	int nbTriForce;
	const int MAX_TRI_FORCE = 8;
	item inventaire[3];
public:
	Link();
	Link(const Link&);
	~Link();
	void ajouterInventaire(std::string id, std::string nom, std::string pouvoir);
	void supprimerInventaire(std::string idItem);
	std::string getInventaire() const;
	std::string attaquerEpee()const;
	std::string lancerBoomerang()const;
	void ajouterTriForce();
	bool peutAccederDonjonGanonPourSauverZelda()const;
	char getDirection();
	void tournerNord();
	void tournerSud();
	void tournerOuest();
	void tournerEst();
	int getNombreVies()const;
	void estBlesse(int dmg);
	bool enVie() const;


};

