#pragma once
#include "SelectionCriterionMin.h"
#include "CriterionUJVekovaSkupinaPodiel.h"
template <typename K>
class SelectionCriterionMinVekovaSkupina : public SelectionCriterionMin<K, UzemnaJednotka, double> {
public:
	SelectionCriterionMinVekovaSkupina(EVS vekovaSkupina)
		: SelectionCriterionMin<K, UzemnaJednotka, double>(new CriterionUJVekovaSkupinaPodiel(vekovaSkupina)) {};
};