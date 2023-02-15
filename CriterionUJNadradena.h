#pragma once
#include "CriterionUJ.h"
using namespace std;
class CriterionUJNadradena : public CriterionUJ<UzemnaJednotka*> {
public:
	UzemnaJednotka* evaluate(const UzemnaJednotka& object) { return object.getNadradena(); };
	void printCriterion(const UzemnaJednotka& object);
};

inline void CriterionUJNadradena::printCriterion(const UzemnaJednotka& object)
{
	cout << "Nadradena jednotka: " << evaluate(object)->getNazov() << "\n";
}