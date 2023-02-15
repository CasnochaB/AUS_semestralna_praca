#pragma once
#include "Filter.h"
#include "Criterion.h"

template <typename ObjectType, typename ValueType>
class FilterWithCriterion : public Filter<ObjectType> {
public:
	bool pass(const ObjectType& object) { return passFilter(criterion_->evaluate(object)); };
	~FilterWithCriterion() { delete criterion_; criterion_ = nullptr; };
	FilterWithCriterion(Criterion<ObjectType, ValueType>* criterion) { criterion_ = criterion; };
	void printCriterion(const ObjectType& object);
private:
protected:
	virtual bool passFilter(ValueType value) = 0;
	Criterion<ObjectType, ValueType>* criterion_;
};

template<typename ObjectType, typename ValueType>
inline void FilterWithCriterion<ObjectType, ValueType>::printCriterion(const ObjectType& object)
{
	criterion_->printCriterion(object);
	//cout << criterion_->evaluate(*object) << "\n";
}
