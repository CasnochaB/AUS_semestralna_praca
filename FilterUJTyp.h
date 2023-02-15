#pragma once
#include "FilterWithCriterion_fi.h"
#include "UzemnaJednotka.h"
#include "CriterionUJTyp.h"
class FilterUJTyp :public FilterWithCriterion_fi<UzemnaJednotka, typUzemnejJednotky> {
public:
	FilterUJTyp(typUzemnejJednotky typUj) : FilterWithCriterion_fi(new CriterionUJTyp(), typUj) {};
};