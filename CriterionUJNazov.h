#pragma once
#include "CriterionUJ.h"
using namespace std;
class CriterionUJNazov : public CriterionUJ<string> {
public:
	string evaluate(const UzemnaJednotka& object) { return object.getNazov(); };
	void printCriterion(const UzemnaJednotka& object);
};
inline void CriterionUJNazov::printCriterion(const UzemnaJednotka& object)
{
	cout << evaluate(object) << "\n";
}