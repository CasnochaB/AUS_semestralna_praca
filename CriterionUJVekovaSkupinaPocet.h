#pragma once
#include "CriterionUJ.h"

using namespace std;
class CriterionUJVekovaSkupinaPocet : public CriterionUJ<int> {
public:
	CriterionUJVekovaSkupinaPocet(EVS vekovaSkupina) { vekovaSkupina_ = vekovaSkupina; };
	int evaluate(const UzemnaJednotka& object);
	void printCriterion(const UzemnaJednotka& object);
private:
	EVS vekovaSkupina_;
};

inline int CriterionUJVekovaSkupinaPocet::evaluate(const UzemnaJednotka& object) {
	int i;
	switch (vekovaSkupina_)
	{
	case PREDPRODUKTIVNY:
		i = 0; break;
	case PRODUKTIVNY:
		i = PREDPRODUKTIVNY; break;
	case POPRODUKTIVNY:
		i = PRODUKTIVNY; break;
	}
	int pocet = 0;
	for (; i < vekovaSkupina_; i++) {
		pocet += object.getVek(i + MUZ);
		pocet += object.getVek(i + ZENA);
	}
	return pocet;
}

inline void CriterionUJVekovaSkupinaPocet::printCriterion(const UzemnaJednotka& object)
{
	cout << "Pocet ";
	switch (vekovaSkupina_)
	{
	case PREDPRODUKTIVNY:
		cout << "predproduktivnych: ";
		break;
	case PRODUKTIVNY:
		cout << "produktivnych: ";
		break;
	case POPRODUKTIVNY:
		cout << "poproduktivnych: ";
		break;
	}
	cout << evaluate(object) << "\n";
}
