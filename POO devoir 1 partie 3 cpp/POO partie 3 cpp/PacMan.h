#pragma once

#include <string>

class PacMan
{
private:
	char direction;
	bool invincible;

public:
	PacMan();
	PacMan(const PacMan&);
	~PacMan();
	char getDirection() const;
	void setDirection(char d);
	bool estInvincible() const;
	std::string attaquer() const;
	void avalerSuperPacGomme();
	void finInvincibilite();
	std::string direPhraseVictoire() const;


};

