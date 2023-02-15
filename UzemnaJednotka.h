#pragma once
#include <string>
#include "structures/array/array.h"
#include "m_debug.h"

enum Pohlavie : int
{
	MUZ = 0,
	ZENA = 101
};

enum EVS : int
{
	PREDPRODUKTIVNY = 15,
	PRODUKTIVNY = 65,
	POPRODUKTIVNY = 101
};

enum typUzemnejJednotky : int 
{
	OBEC = 0,
	OKRES = 1,
	KRAJ = 2
};


enum typVzdelania
{
	BEZ_UKONCENEHO_VZDELANIA,
	ZAKLADNE,
	UCNOVSKE,
	STREDNE,
	VYSSIE,
	VYSOKOSKOSLE,
	BEZ_VZDELANIA,
	NEZISTENE
};

using namespace std;

class UzemnaJednotka {
public:
	UzemnaJednotka(string nazov, string kod, typUzemnejJednotky typUJ, structures::Array<int>* vek, structures::Array<int>* vzdelanie);
	UzemnaJednotka(string nazov, string kod, typUzemnejJednotky typUJ);
	~UzemnaJednotka();
	int getPocetObyvatelov() const;
	typUzemnejJednotky getTypUJ() const;
	const string& getKod() const { return kod_; };
	const string& getNazov() const { return nazov_; };
	int getVek(int index) const { return vek_->at(index); };
	int getVzdelanie(int index) const { return vzdelanie_->at(index); };
	void setVek(structures::Array<int>* vek) { vek_ = vek; };
	void setVzdelanie(structures::Array<int>* vzdelanie) ;
	void setNadradena(UzemnaJednotka* nadradena) { nadradena_ = nadradena; };
	UzemnaJednotka* getNadradena() const { return nadradena_; };
	static string typUJtoString(typUzemnejJednotky typUJ);
private:
	string kod_;
	string nazov_;
	structures::Array<int>* vek_;
	structures::Array<int>* vzdelanie_;
	int pocetObyvatelov_;
	typUzemnejJednotky typUJ_;
	UzemnaJednotka* nadradena_;
};