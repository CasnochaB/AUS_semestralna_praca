#pragma once
#include "FilterWithCriterion.h"

template <typename ObjectType, typename ValueType>
class FilterWithCriterion_fi : public FilterWithCriterion<ObjectType, ValueType> {
public:
	FilterWithCriterion_fi(Criterion<ObjectType,ValueType>* criterion,ValueType value);
private:
	ValueType value_;
protected:
	bool passFilter(ValueType value);
};

template<typename ObjectType, typename ValueType>
inline FilterWithCriterion_fi<ObjectType, ValueType>::FilterWithCriterion_fi(Criterion<ObjectType, ValueType>* criterion, ValueType value) :
	 FilterWithCriterion<ObjectType,ValueType>::FilterWithCriterion(criterion)
{
	value_ = value;
}

template<typename ObjectType, typename ValueType>
inline bool FilterWithCriterion_fi<ObjectType, ValueType>::passFilter(ValueType value)
{
	return value == value_;
}
