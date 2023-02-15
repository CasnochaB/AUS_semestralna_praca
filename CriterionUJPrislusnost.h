#pragma once
#include "CriterionUJ.h"
using namespace std;
class CriterionUJPrislusnost : public CriterionUJ<bool> {
public:
	CriterionUJPrislusnost(const UzemnaJednotka* vyssiCelok) { vyssiCelok_ = vyssiCelok; };
	~CriterionUJPrislusnost() { vyssiCelok_ = nullptr; };
	bool evaluate(const UzemnaJednotka& object);
	void printCriterion(const UzemnaJednotka& object);
private:
	const UzemnaJednotka* vyssiCelok_;
};

inline bool CriterionUJPrislusnost::evaluate(const UzemnaJednotka& object) {
	if (object.getNadradena() != nullptr) {
		if (object.getNadradena()->getNadradena() == vyssiCelok_ || object.getNadradena() == vyssiCelok_) {
			return true;
		}
		return false;
	}
	return object.getNadradena() == vyssiCelok_;
}

inline void CriterionUJPrislusnost::printCriterion(const UzemnaJednotka& object)
{
	if (evaluate(object)) {
		cout << "Patri do celku: " << vyssiCelok_->getNazov() << "\n";
	}
	else {
		cout << "Nepatri do celku: " << vyssiCelok_->getNazov() << "\n";
	}
}
