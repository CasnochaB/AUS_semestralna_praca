#pragma once
#include "SelectionCriterion.h"
#include "Criterion.h"
template <typename KeyType, typename ObjectType, typename ValueType>
class SelectionCriterionMax : public SelectionCriterion<typename KeyType, typename ObjectType, typename ValueType> {
public:
	SelectionCriterionMax(Criterion<ObjectType, ValueType>* criterion) : SelectionCriterion<KeyType, ObjectType, ValueType>(criterion) {};
protected:
	bool isTestedValueBetter(ValueType bestNow, ValueType bestTested);
};

template<typename KeyType, typename ObjectType, typename ValueType>
inline bool SelectionCriterionMax<KeyType, ObjectType, ValueType>::isTestedValueBetter(ValueType bestNow, ValueType bestTested)
{
	return bestTested > bestNow;
}
