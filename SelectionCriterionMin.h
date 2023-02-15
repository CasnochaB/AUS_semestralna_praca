#pragma once
#include "SelectionCriterion.h"
#include "Criterion.h"
template <typename KeyType, typename ObjectType, typename ValueType>
class SelectionCriterionMin : public SelectionCriterion<typename KeyType, typename ObjectType, typename ValueType> {
public:
	SelectionCriterionMin(Criterion<ObjectType, ValueType>* criterion) : SelectionCriterion<KeyType, ObjectType, ValueType>(criterion) {};
protected:
	bool isTestedValueBetter(ValueType bestNow, ValueType bestTested);
};

template<typename KeyType, typename ObjectType, typename ValueType>
inline bool SelectionCriterionMin<KeyType, ObjectType, ValueType>::isTestedValueBetter(ValueType bestNow, ValueType bestTested)
{
	return bestTested < bestNow;
}
