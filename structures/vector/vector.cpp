#include "vector.h"
#include "../utils.h"
#include <cstdlib>
#include <cstring>

namespace structures
{
	Vector::Vector(size_t size) :
		memory_(std::calloc(size, 1)),
		size_(size)
	{	
	}

	Vector::Vector(Vector& other) :
		Vector(other.size_)
	{
		memcpy(memory_, other.memory_, size_);
	}

	Vector::~Vector()
	{
		free(memory_);
	}

	size_t Vector::size()
	{
		return size_;
	}

	Structure& Vector::assign(Structure& other)
	{
		if (this != &other) {
			Vector& otherVector = dynamic_cast<Vector&>(other);
			size_ = otherVector.size_;
			memory_ = realloc(memory_, size_);
			memcpy(memory_, otherVector.memory_, size_);
		}

		return *this;
	}

	bool Vector::equals(Structure& other)
	{
		if (this == &other) {
			return true;
		}
		else {
			Vector* otherVector = dynamic_cast<Vector*>(&other);
			if (otherVector != nullptr) {
				return size_ == otherVector->size_ && memcmp(memory_, otherVector->memory_, size_) == 0;
			}
			else {
				return false;
			}

		}
	}

	byte& Vector::operator[](int index)
	{
		return at(index);
	}

	byte& Vector::at(int index)
	{
		Utils::rangeCheckExcept(index, size_, "Invalid index!");
		return *(reinterpret_cast<byte*>(memory_) + index);
	}

	void Vector::copy(Vector& src, int srcStartIndex, Vector& dest, int destStartIndex, int length)
	{
		/*if (srcStartIndex > 0 && srcStartIndex < src.size() && srcStartIndex + length < src.size()) {
			if (destStartIndex > 0 && destStartIndex < dest.size() && destStartIndex + length < dest.size()) {

			}
		}*/

		Utils::rangeCheckExcept(srcStartIndex, src.size_, "Invalid srcStartIndex");
		Utils::rangeCheckExcept(destStartIndex, dest.size_, "Invalid destStartIndex");
		Utils::rangeCheckExcept(srcStartIndex + length, src.size_ + 1, "Invalid srcStartIndex");
		Utils::rangeCheckExcept(destStartIndex + length, src.size_ + 1, "Invalid destStartIndex");

		if (&src == &dest && abs(srcStartIndex - destStartIndex) < length) {
			memmove(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
		else {
			memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
	}

	byte* Vector::getBytePointer(int index)
	{
		Utils::rangeCheckExcept(index, size_, "Invalid index!");
		return reinterpret_cast<byte*>(memory_) + index;
	}
}