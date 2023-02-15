#pragma once
#include "CriterionUJ.h"
using namespace std;
class CriterionUJVzdelaniePodiel : public CriterionUJ<double> {
public:
	CriterionUJVzdelaniePodiel(typVzdelania vzdelanie) { vzdelanie_ = vzdelanie; };
	double evaluate(const UzemnaJednotka& object);
	void printCriterion(const UzemnaJednotka& object);
private:
	typVzdelania vzdelanie_;
};

inline double CriterionUJVzdelaniePodiel::evaluate(const UzemnaJednotka& object) {
	if (object.getPocetObyvatelov() == 0) {
		return 0;
	}
	double pocet = object.getVzdelanie(vzdelanie_);
	double pocetObyvatelov = object.getPocetObyvatelov();
	return (pocet / pocetObyvatelov) * 100;
}

inline void CriterionUJVzdelaniePodiel::printCriterion(const UzemnaJednotka& object)
{

	cout << "Podiel obyvatelov ";
	switch (vzdelanie_)
	{
	case BEZ_UKONCENEHO_VZDELANIA:
		cout << "bez ukonceneho vzdelania";
		break;
	case ZAKLADNE:
		cout << "so zakladnym vzdelanim";
		break;
	case UCNOVSKE:
		cout << "s ucnovskym vzdelanim";
		break;
	case STREDNE:
		cout << "so strednym vzdelanim";
		break;
	case VYSSIE:
		cout << "s vyssim vzdelanim";
		break;
	case VYSOKOSKOSLE:
		cout << "s vysokoskolskym vzdelanim";
		break;
	case BEZ_VZDELANIA:
		cout << "bez vzdelania";
		break;
	case NEZISTENE:
		cout << "s nezistenym vzdelanim";
		break;
	}
	cout << ": " << evaluate(object) << "\n";
}
