#pragma once
#include "CriterionUJ.h"
using namespace std;
class CriterionUJVzdelaniePocet : public CriterionUJ<int> {
public:
	CriterionUJVzdelaniePocet(typVzdelania vzdelanie) { vzdelanie_ = vzdelanie; };
	int evaluate(const UzemnaJednotka& object);
	void printCriterion(const UzemnaJednotka& object);
private:
	typVzdelania vzdelanie_;
};

inline int CriterionUJVzdelaniePocet::evaluate(const UzemnaJednotka& object) {
	return object.getVzdelanie(vzdelanie_);
}

inline void CriterionUJVzdelaniePocet::printCriterion(const UzemnaJednotka& object)
{
	
	cout << "Pocet obyvatelov ";
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
