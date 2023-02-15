#pragma once
#include "Filter.h"
#include "structures/list/linked_list.h"

template <typename ObjectType>
class CompositeFilter : public Filter<ObjectType> {
public:
	CompositeFilter() { filters_ = new structures::ArrayList<Filter<ObjectType>*>(); };
	~CompositeFilter();
	void registerFilter(Filter<ObjectType>* filter) { filters_->add(filter); };
	void printCriterion(const ObjectType& object);
protected:
	structures::ArrayList<Filter<ObjectType>*>* filters_;
};

template<typename ObjectType>
inline CompositeFilter<ObjectType>::~CompositeFilter()
{
	for (int i = 0; i < filters_->size();i++) {
		delete filters_->at(i);
	}
	delete filters_;
	filters_ = nullptr;
}

template<typename ObjectType>
inline void CompositeFilter<ObjectType>::printCriterion(const ObjectType& object)
{
	for (auto filter : *filters_) {
		filter->printCriterion(object);
	}
}
