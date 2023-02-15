#pragma once
#include "CompositeFilter.h"

template <typename ObjectType>
class FilterAND : public CompositeFilter<ObjectType> {
public:
	bool pass(const ObjectType& object);
};

template<typename ObjectType>
inline bool FilterAND<ObjectType>::pass(const ObjectType& object)
{
	for (auto filter : *CompositeFilter<ObjectType>::filters_) {
		if (!filter->pass(object)) {
			return false;
		}
	}
	return true;
}