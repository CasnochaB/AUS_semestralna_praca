#pragma once
#include "UzemneJednotkyTable.h"
#include "CompositeFilter.h"
#include "Filter_AND.h"
#include "Filter_OR.h"
#include "FilterVzdelaniePocet.h"
#include "FilterVzdelaniePodiel.h"
#include "CriterionUJNazov.h"
#include "FilterUJTyp.h"
#include "FilterPrislusnost.h"
#include "FilterVekPocet.h"
#include "FilterVekPodiel.h"
#include "FilterVekovaSkupinaPocet.h"
#include "FilterVekovaSkupinaPodiel.h"
#include "structures/table/sorting/quick_sort.h"
#include "Sorting.h"

class Aplikacia
{
public:
	Aplikacia(UzemneJednotkyTable* uzemneJednotky) { uzemneJednotky_ = uzemneJednotky; };
	~Aplikacia();
	void spusti();
private :
	bool mainMenu();
	void bodoveVyhladavanieMenu();
	void filtrovanieMenu();
	void filterSelectionMenu(CompositeFilter<UzemnaJednotka>* filter);
	void inputFilterVekovaSkupina(int& min, int& max, int& vyber1);
	void inputFilterVek(int& min, int& max, int& vekOd,int& vekDo, int& vyber2);
	void inputFilterVzdelanie(int& min, int& max, int& vyber1);
	void vykonajFiltrovanie(CompositeFilter<UzemnaJednotka>* filter);
	void triedenieMenu();
	void smallSelectionMenu(FilterAND<UzemnaJednotka>& filter);
	void triedenieFilterMenu(CompositeFilter<UzemnaJednotka>* tabulka);
	bool getPoradie();
	void vyberNajlepsichMenu();
	void vybejNajlepsichFilterMenu(CompositeFilter<UzemnaJednotka>* filter);
	void checkInput(int min, int max,int& input);
	UzemnaJednotka* dajUzemnuJednotku(string text);
	void vypisTypovVzdelanie();
	void vypisTypovUzemnejJednotky();
	void vypisTypovPohlavia();
	void vypisTypovEVS();
	void vypisKriteria(UzemnaJednotka* objektNaVypis);
	Pohlavie intToPohlavie(int typ);
	EVS intToEVS(int typ);
	UzemneJednotkyTable* uzemneJednotky_;
};

