#pragma once

template <typename ObjectType, typename ResultType>
class Criterion
{
public:
	virtual ResultType evaluate(const ObjectType& object) = 0;
	virtual void printCriterion(const ObjectType& object) = 0;
};

