#pragma once
#include "CriterionUJ.h"

using namespace std;
class CriterionUJTyp : public CriterionUJ<typUzemnejJednotky> {
public:
	typUzemnejJednotky evaluate(const UzemnaJednotka& object) { return object.getTypUJ(); };
	void printCriterion(const UzemnaJednotka& object) {};
};
