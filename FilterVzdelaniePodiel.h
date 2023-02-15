#pragma once
#include "FilterWithCriterion_pi.h"
#include "UzemnaJednotka.h"
#include "CriterionUJVzdelaniePodiel.h"

class FilterVzdelaniePodiel : public FilterWithCriterion_pi<UzemnaJednotka, double> {
public:
	FilterVzdelaniePodiel(int valueMin, int valueMax, typVzdelania vzdelanie) : FilterWithCriterion_pi(new CriterionUJVzdelaniePodiel(vzdelanie), valueMin, valueMax) {};
};