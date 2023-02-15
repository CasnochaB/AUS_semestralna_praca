#pragma once
#include "FilterWithCriterion_pi.h"
#include "UzemnaJednotka.h"
#include "CriterionUJVzdelaniePocet.h"
class FilterVzdelaniePocet :public FilterWithCriterion_pi<UzemnaJednotka, int> {
public:
	FilterVzdelaniePocet(int valueMin,int valueMax,typVzdelania vzdelanie) : FilterWithCriterion_pi(new CriterionUJVzdelaniePocet(vzdelanie),valueMin,valueMax ) {};
};