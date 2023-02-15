#pragma once
#include "CompositeFilter.h"

template <typename ObjectType>
class FilterOR : public CompositeFilter<ObjectType> {
public:
	bool pass(const ObjectType& object);
};

template<typename ObjectType>
inline bool FilterOR<ObjectType>::pass(const ObjectType& object)
{
	if (CompositeFilter<ObjectType>::filters_->size() == 0) {
		return true;
	}
	for (auto filter : *CompositeFilter<ObjectType>::filters_) {
		if (filter->pass(object)) {
			return true;
		}
	}
	return false;
}
