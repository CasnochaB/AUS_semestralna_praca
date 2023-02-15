#pragma once
#include "structures/table/table.h"
#include "Criterion.h"
template <typename KeyType,typename ObjectType, typename ValueType>

class SelectionCriterion {
public:
	ObjectType selectBest(structures::UnsortedSequenceTable<KeyType, ObjectType>* table);
	SelectionCriterion(Criterion<ObjectType, ValueType>* criterion) { criterion_ = criterion; };
	~SelectionCriterion() {
		delete criterion_;
		criterion_ = nullptr;
	};
protected:
	virtual bool isTestedValueBetter(ValueType bestNow, ValueType testedValue) = 0;
	Criterion<ObjectType, ValueType>* criterion_;
};

template<typename KeyType, typename ObjectType, typename ValueType>
inline ObjectType SelectionCriterion<KeyType, ObjectType, ValueType>::selectBest(structures::UnsortedSequenceTable<KeyType, ObjectType>* table)
{
	ObjectType bestObject = *(*table->getBeginIterator());
	ValueType bestValue = criterion_->evaluate(bestObject);
	for (auto item : *table) {
		ObjectType testedObject = item->accessData();
		ValueType testedValue = criterion_->evaluate(testedObject);
		if (isTestedValueBetter(bestValue, testedValue)) {
			bestValue = testedValue;
			bestObject = testedObject;
		}
	}

}
