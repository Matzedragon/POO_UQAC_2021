#pragma once

#include <string>

class Mario
{
private:
	bool invincible;
	std::string etat;
	std::string nom;
public:
	Mario();
	Mario(std::string);
	Mario(const Mario&);
	~Mario();
	void estBlesse();
	std::string getEtat() const;
	bool estInvincible() const;
	void mangerChampignon();
	void mangerFleurFeu();
	void mangerFleurGlace();
	void attraperEtoile();
	void finPouvoirEtoile();
	std::string direPhraseVictoire();
	std::string getNom() const;

};

