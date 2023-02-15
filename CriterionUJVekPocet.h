#pragma once
#pragma once
#include "CriterionUJ.h"
using namespace std;
class CriterionUJVekPocet : public CriterionUJ<int> {
public:
	CriterionUJVekPocet(int vekOd,int vekDo, Pohlavie pohlavie);
	CriterionUJVekPocet(int vekOd, Pohlavie pohlavie);
	int evaluate(const UzemnaJednotka& object);
	void printCriterion(const UzemnaJednotka& object);
private:
	int vekOd_;
	int vekDo_;
	Pohlavie pohlavie_;
};

inline CriterionUJVekPocet::CriterionUJVekPocet(int vekOd, int vekDo, Pohlavie pohlavie) {
	if (vekOd > 100) {
		vekOd_ = 100;
	}
	else {
		vekOd_ = vekOd;
	}
	if (vekDo > 100) {
		vekDo_ = 100;
	}
	else {
		vekDo_ = vekDo;
	}
	pohlavie_ = pohlavie; 
}

inline CriterionUJVekPocet::CriterionUJVekPocet(int vekOd, Pohlavie pohlavie) : CriterionUJVekPocet(vekOd,100,pohlavie)
{
}

inline int CriterionUJVekPocet::evaluate(const UzemnaJednotka& object) {
	int pocet = 0;
	for (int i = vekOd_; i <= vekDo_; i++) {
		pocet += object.getVek(i + pohlavie_);
	}
	return pocet;
}

inline void CriterionUJVekPocet::printCriterion(const UzemnaJednotka& object)
{
	cout << "Pocet ";
	switch (pohlavie_)
	{
	case MUZ:
		cout << "muzov ";
		break;
	case ZENA:
		cout << "zien ";
		break;
	}
	cout << "vo veku " << vekOd_ << " do " << vekDo_ << " je " << evaluate(object) << "\n" ;
}
