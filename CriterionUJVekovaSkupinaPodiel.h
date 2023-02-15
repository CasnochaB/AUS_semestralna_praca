#pragma once
#include "CriterionUJ.h"

class CriterionUJVekovaSkupinaPodiel : public CriterionUJ<double> {
public:
	CriterionUJVekovaSkupinaPodiel(EVS vekovaSkupina) {  vekovaSkupina_ = vekovaSkupina; };
	double evaluate(const UzemnaJednotka& object);
	void printCriterion(const UzemnaJednotka& object);
private:
	EVS vekovaSkupina_;
};

inline double CriterionUJVekovaSkupinaPodiel::evaluate(const UzemnaJednotka& object) {
	if (object.getPocetObyvatelov() == 0) {
		return 0;
	}
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
	double pocet = 0;
	for (; i < vekovaSkupina_; i++) {
		pocet += object.getVek(i + MUZ);
		pocet += object.getVek(i + ZENA);
	}
	double pocetObyvatelov = object.getPocetObyvatelov();
	return (pocet/pocetObyvatelov)*100;
}

inline void CriterionUJVekovaSkupinaPodiel::printCriterion(const UzemnaJednotka& object)
{
	cout << "Podiel ";
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
