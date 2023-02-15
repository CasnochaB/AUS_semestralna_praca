#pragma once
#pragma once
#include "FilterWithCriterion_fi.h"
#include "UzemnaJednotka.h"
#include "CriterionUJPrislusnost.h"

class FilterPrislusnost : public FilterWithCriterion_fi<UzemnaJednotka, bool> {
public:
	FilterPrislusnost(UzemnaJednotka* vyssiCelok) : FilterWithCriterion_fi(new CriterionUJPrislusnost(vyssiCelok), vyssiCelok) {};
};