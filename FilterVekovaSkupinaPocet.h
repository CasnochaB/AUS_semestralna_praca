#pragma once
#include "FilterWithCriterion_pi.h"
#include "UzemnaJednotka.h"
#include "CriterionUJVekovaSkupinaPocet.h"
class FilterVekovaSkupinaPocet :public FilterWithCriterion_pi<UzemnaJednotka, int> {
public:
	FilterVekovaSkupinaPocet(int valueMin, int valueMax,  EVS vekovaSkupina) : FilterWithCriterion_pi(new CriterionUJVekovaSkupinaPocet(vekovaSkupina), valueMin, valueMax) {};
};