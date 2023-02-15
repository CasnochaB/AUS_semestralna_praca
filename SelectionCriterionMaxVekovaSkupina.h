#pragma once
#include "SelectionCriterionMax.h"
#include "CriterionUJVekovaSkupinaPodiel.h"
template <typename K>
class SelectionCriterionMaxVekovaSkupina : public SelectionCriterionMax<K, UzemnaJednotka, double> {
public:
	SelectionCriterionMaxVekovaSkupina(EVS vekovaSkupina)
		: SelectionCriterionMax<K, UzemnaJednotka, double>(new CriterionUJVekovaSkupinaPodiel(vekovaSkupina)) {};
};