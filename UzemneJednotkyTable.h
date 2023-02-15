#pragma once

#include <iostream>
#include "UzemnaJednotka.h"
#include "structures/table/sorted_sequence_table.h"
#include "structures/table/unsorted_sequence_table.h"
#include "Filter.h"
#include "structures/structure_iterator.h"

using namespace std;

class UzemneJednotkyTable 
{
public:
	UzemneJednotkyTable();
	~UzemneJednotkyTable();
	void pridajUzemnuJednotku(string nazov, string kod,  typUzemnejJednotky typUJ,structures::Array<int>* vek, structures::Array<int>* vzdelanie);
	void pridajUzemnuJednotku(UzemnaJednotka* uzemnaJednotka);
	structures::SortedSequenceTable<string, UzemnaJednotka*>* getZoznam() { return uzemneJednotky_; };
	UzemnaJednotka* getJednotka(string nazov);
private:
	structures::SortedSequenceTable<string, UzemnaJednotka*>* uzemneJednotky_;
};

inline UzemneJednotkyTable::UzemneJednotkyTable() {
	uzemneJednotky_ = new structures::SortedSequenceTable<string, UzemnaJednotka*>();
}

inline UzemneJednotkyTable::~UzemneJednotkyTable() {
	for (auto item : *uzemneJednotky_) {
		delete item->accessData();
	}
	delete uzemneJednotky_;
	uzemneJednotky_ = nullptr;
}

inline void UzemneJednotkyTable::pridajUzemnuJednotku(string nazov, string kod, typUzemnejJednotky typUJ, structures::Array<int>* vek, structures::Array<int>* vzdelanie) {
	UzemnaJednotka* newUj = new UzemnaJednotka(nazov, kod,  typUJ, vek, vzdelanie);
	uzemneJednotky_->insert(nazov,newUj);
}

inline void UzemneJednotkyTable::pridajUzemnuJednotku(UzemnaJednotka* uzemnaJednotka)
{
	uzemneJednotky_->insert(uzemnaJednotka->getNazov(), uzemnaJednotka);
}


inline UzemnaJednotka* UzemneJednotkyTable::getJednotka(string nazov)
{
	return uzemneJednotky_->find(nazov);
}





