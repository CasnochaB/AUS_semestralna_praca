#pragma once
#include "FilterWithCriterion_pi.h"
#include "UzemnaJednotka.h"
#include "CriterionUJVekovaSkupinaPodiel.h"

class FilterVekovaSkupinaPodiel : public FilterWithCriterion_pi<UzemnaJednotka, double> {
public:
	FilterVekovaSkupinaPodiel(int valueMin, int valueMax, EVS vekovaSkupina) : FilterWithCriterion_pi(new CriterionUJVekovaSkupinaPodiel(vekovaSkupina), valueMin, valueMax) {};
};