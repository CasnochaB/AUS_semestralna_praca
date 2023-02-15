#pragma once
#include "FilterWithCriterion.h"

template <typename ObjectType, typename ValueType>
class FilterWithCriterion_pi : public FilterWithCriterion<ObjectType, ValueType> {
public:
	FilterWithCriterion_pi(Criterion<ObjectType, ValueType>* criterion,ValueType valueMin, ValueType valueMax);
private:
	ValueType valueMin_;
	ValueType valueMax_;
protected:
	bool passFilter(ValueType value) override;
};

template<typename ObjectType, typename ValueType>
inline FilterWithCriterion_pi<ObjectType, ValueType>::FilterWithCriterion_pi(Criterion<ObjectType, ValueType>* criterion, ValueType valueMin, ValueType valueMax) :
	FilterWithCriterion<ObjectType, ValueType>::FilterWithCriterion(criterion) 
{
	valueMin_ = valueMin;
	valueMax_ = valueMax;
}

template<typename ObjectType, typename ValueType>
inline bool FilterWithCriterion_pi<ObjectType, ValueType>::passFilter(ValueType value)
{
	return value >= valueMin_ && value <= valueMax_;
}