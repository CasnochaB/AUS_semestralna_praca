#pragma once
#include "FilterWithCriterion_pi.h"
#include "UzemnaJednotka.h"
#include "CriterionUJVekPodiel.h"

class FilterVekPodiel : public FilterWithCriterion_pi<UzemnaJednotka, double> {
public:
	FilterVekPodiel(int valueMin, int valueMax, int  vekOd, int vekDo, Pohlavie pohlavie) : FilterWithCriterion_pi(new CriterionUJVekPodiel(vekOd,vekDo, pohlavie), valueMin, valueMax) {};
};