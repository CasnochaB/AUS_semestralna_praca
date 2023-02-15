#pragma once
#include "FilterWithCriterion_pi.h"
#include "UzemnaJednotka.h"
#include "CriterionUJVekPocet.h"
class FilterVekPocet :public FilterWithCriterion_pi<UzemnaJednotka, int> {
public:
	FilterVekPocet(int valueMin, int valueMax,int  vekOd,int vekDo, Pohlavie pohlavie) : FilterWithCriterion_pi(new CriterionUJVekPocet(vekOd,vekDo, pohlavie), valueMin, valueMax) {};
};