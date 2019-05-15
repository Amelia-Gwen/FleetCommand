#include "Marine.h"

fleet::Marine::Marine(unsigned short rank) :
	IUnit{ "Marine", rank }
{
	hitPoints = 40 + 12 * rank;
	movePoints = 4 + rank;
	attackPoints = 5 + rank / 2;

	attack = 20 + 15 * rank;
	defense = 12 + 8 * rank;
	speed = 0;
	accuracy = 200 + 100 * rank;
	evade = 200 + 100 * rank;

	canBeFlagship = false;
	isFlagship = false;
}
