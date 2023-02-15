#pragma once
#include "FilterWithCriterion_fi.h"
#include "UzemnaJednotka.h"
#include "CriterionUJNazov.h"
class FilterNazov : public FilterWithCriterion_fi<UzemnaJednotka, std::string> {
public:
	FilterNazov(string name) : FilterWithCriterion_fi(new CriterionUJNazov(), name) {};
};