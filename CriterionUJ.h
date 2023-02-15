#pragma once
#include "Criterion.h"
#include <iostream>
#include "UzemnaJednotka.h"

template <typename ResultType>

class CriterionUJ : public Criterion<UzemnaJednotka, ResultType>
{
};

