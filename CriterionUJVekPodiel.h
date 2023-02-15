#pragma once
#include "CriterionUJ.h"
using namespace std;
class CriterionUJVekPodiel : public CriterionUJ<double> {
public:
	CriterionUJVekPodiel(int vekOd,int vekDo, Pohlavie pohlavie) ;
	double evaluate(const UzemnaJednotka& object);
	void printCriterion(const UzemnaJednotka& object);
private:
	int vekOd_;
	int vekDo_;
	Pohlavie pohlavie_;
};
inline CriterionUJVekPodiel::CriterionUJVekPodiel(int vekOd,int vekDo, Pohlavie pohlavie) {
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

inline double CriterionUJVekPodiel::evaluate(const UzemnaJednotka& object) {
	if (object.getPocetObyvatelov() == 0) {
		return 0;
	}
	double pocet = 0;
	for (int i = vekOd_; i <= vekDo_; i++) {
		pocet += object.getVek(i + pohlavie_);
	}
	double pocetObyvatelov = object.getPocetObyvatelov();
	return (pocet / pocetObyvatelov)*100;
}

inline void CriterionUJVekPodiel::printCriterion(const UzemnaJednotka& object)
{
	cout << "Podiel ";
	switch (pohlavie_)
	{
	case MUZ:
		cout << "muzov ";
		break;
	case ZENA:
		cout << "zien ";
		break;
	}
	cout << "vo veku " << vekOd_ << " do " << vekDo_ << " je " << evaluate(object) << "\n";
}
