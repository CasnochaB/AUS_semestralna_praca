#include "UzemnaJednotka.h"

UzemnaJednotka::UzemnaJednotka(string nazov, string kod,  typUzemnejJednotky typUJ, structures::Array<int>* vek, structures::Array<int>* vzdelanie)
	: UzemnaJednotka::UzemnaJednotka(nazov, kod, typUJ)
{
	vek_ = vek;
	setVzdelanie(vzdelanie);
}

UzemnaJednotka::UzemnaJednotka(string nazov, string kod,  typUzemnejJednotky typUJ) {
	nazov_ = nazov; 
	kod_ = kod;
	typUJ_ = typUJ;
	pocetObyvatelov_ = 0;
	vek_ = nullptr;
	vzdelanie_ = nullptr;
	nadradena_ = nullptr;
}

UzemnaJednotka::~UzemnaJednotka()
{
	delete vek_;
	delete vzdelanie_;
	vek_ = nullptr;
	vzdelanie_ = nullptr;
	pocetObyvatelov_ = 0;
	nadradena_ = nullptr;
}

int UzemnaJednotka::getPocetObyvatelov() const
{
	return pocetObyvatelov_;
}

typUzemnejJednotky UzemnaJednotka::getTypUJ() const
{
	return typUJ_;
}

void UzemnaJednotka::setVzdelanie(structures::Array<int>* vzdelanie)
{
	vzdelanie_ = vzdelanie;
	for (int i = 0; i < vzdelanie_->size(); i++) {
		pocetObyvatelov_ += vzdelanie_->at(i);
	}
}

string UzemnaJednotka::typUJtoString(typUzemnejJednotky typUJ)
{
	switch (typUJ)
	{
	case OBEC: return "Obec";
	case OKRES: return "Okres";
	case KRAJ: return "Kraj";
	}
	return string();
}



