#include "Aplikacia.h"

Aplikacia::~Aplikacia()
{
	delete uzemneJednotky_;
}

void Aplikacia::spusti()
{
	while (mainMenu()) {
		cout << "\n\n";
	}
}

bool Aplikacia::mainMenu()
{
	cout << "Vyberte operaciu: \n";
	cout << "1. Bodove Vyhladavanie\n";
	cout << "2. Filtrovanie\n";
	cout << "3. Triedenie\n";
	cout << "4. Vyber najlepsich\n";
	cout << "5. opustit\n";

	string input;
	bool vyber = true;
	while (vyber) {
		cin >> input;
		vyber = false;
		if (input == "1") {
			bodoveVyhladavanieMenu();
		}
		else if (input == "2") {
			filtrovanieMenu();
		}
		else if (input == "3") {
			triedenieMenu();
		}
		else if (input == "4") {
			vyberNajlepsichMenu();
		}
		else if (input == "" || input == "5") {
			return false;
		}
		else {
			vyber = true;
			cout << "Zadali ste nespravny vyber, zopakujte volbu:\n";
		}
	}
	return true;
}

void Aplikacia::bodoveVyhladavanieMenu()
{
	string input;
	cout << "Zadajte Meno uzemnej jednotky:\n";
	vypisKriteria(dajUzemnuJednotku(input));
	cout << "Zmacnite enter pre pokracovanie\n";
	getchar();
}


void Aplikacia::filtrovanieMenu()
{
	string input;
	cout << "Vyberte kompozitny Filter:\n";
	cout << "1. AND\n";
	cout << "2. OR\n";
	bool vyber = true;
	while (vyber) {
		cin >> input;
		vyber = false;
		if (input == "1") {
			FilterAND<UzemnaJednotka> filter;
			filterSelectionMenu(&filter);
			vykonajFiltrovanie(&filter);
		}
		else if (input == "2") {
			FilterOR<UzemnaJednotka> filter;
			filterSelectionMenu(&filter);
			vykonajFiltrovanie(&filter);
		}
		else {
			vyber = true;
			cout << "Zadali ste nespravny vyber, zopakujte volbu:\n";
		}
	}
}

void Aplikacia::filterSelectionMenu(CompositeFilter<UzemnaJednotka>* filter)
{
	cout << "\n";
	int znak = 1;
	while (znak != 9) {
		cout << "Zadajte filtre ktore chcete pouzit:\n";
		cout << "1. filter vzdelaniePocet\n";
		cout << "2. filter vzdelaniePodiel\n";
		cout << "3. filter typ uzemnej jednotky\n";
		cout << "4. filter prislusnost\n";
		cout << "5. filter vekPocet\n";
		cout << "6. filter vekPodiel\n";
		cout << "7. filter EVS pocet\n";
		cout << "8. filter EVS podiel\n";
		cout << "9. pokracovat\n\n";
		int min;
		int max;
		int vekOd;
		int vekDo;
		int vyber1;
		int vyber2;
		string vyberText;
		checkInput(1, 9, znak);
		switch (znak)
		{
		case 1:
			inputFilterVzdelanie(min, max, vyber1);
			{
				FilterVzdelaniePocet* lesserFilter = new FilterVzdelaniePocet(min, max, static_cast<typVzdelania>(vyber1-1));
				filter->registerFilter(lesserFilter);
			}
			break;

		case 2:
			inputFilterVzdelanie(min, max, vyber1);
			{
				FilterVzdelaniePodiel* lesserFilter = new FilterVzdelaniePodiel(min, max, static_cast<typVzdelania>(vyber1-1));
				filter->registerFilter(lesserFilter);

			}
			break;
		case 3:
			cout << "Zadajte typ uzemnej jednotky\n";
			Aplikacia::vypisTypovUzemnejJednotky();
			checkInput(1, 3, vyber1);
			{
				FilterUJTyp* lesserFilter = new FilterUJTyp(static_cast<typUzemnejJednotky>(vyber1 - 1));
				filter->registerFilter(lesserFilter);
			}
			break;
		case 4:
			cout << "Zadajte nazov vyssieho celku\n";
			{
				FilterPrislusnost* lesserFilter = new FilterPrislusnost(dajUzemnuJednotku(vyberText));
				filter->registerFilter(lesserFilter);
			}
			break;
		case 5:
			inputFilterVek(min, max, vekOd,vekDo, vyber2);
			{
				FilterVekPocet* lesserFilter = new FilterVekPocet(min,max,vekOd,vekDo,intToPohlavie(vyber2));
				filter->registerFilter(lesserFilter);
			}
			break;
		case 6:
			inputFilterVek(min, max, vekOd,vekDo, vyber2);
			{
				FilterVekPodiel* lesserFilter = new FilterVekPodiel(min, max, vekOd,vekDo, intToPohlavie(vyber2));
				filter->registerFilter(lesserFilter);
			}
			break;
		case 7:
			inputFilterVekovaSkupina(min, max, vyber1);
			{
				FilterVekovaSkupinaPocet* lesserFilter = new FilterVekovaSkupinaPocet(min,max,intToEVS(vyber1));
				filter->registerFilter(lesserFilter);
			}
			break;
		case 8:
			inputFilterVekovaSkupina(min, max, vyber1);
			{
				FilterVekovaSkupinaPodiel* lesserFilter = new FilterVekovaSkupinaPodiel(min, max, intToEVS(vyber1));
				filter->registerFilter(lesserFilter);
			}
			break;
		}
	}
}

void Aplikacia::inputFilterVekovaSkupina(int& min, int& max, int& vyber1)
{

	cout << "\nZadajte min pocet:\n";
	checkInput(0, INT_MAX, min);
	cout << "\nZadajte max pocet:\n";
	checkInput(min, INT_MAX, max);
	cout << "\nZadajte vekovu skupinu\n";
	vypisTypovEVS();
	checkInput(1, 3, vyber1);
}

void Aplikacia::inputFilterVek(int& min, int& max, int& vekOd,int& vekDo, int& vyber2)
{

	cout << "Zadajte min pocet:\n";
	checkInput(0, INT_MAX, min);
	cout << "Zadajte max pocet:\n";
	checkInput(min, INT_MAX, max);
	cout << "Zadajte vek od(0-100)\n";
	checkInput(0, INT_MAX, vekOd);
	cout << "Zadajte vek do(0-100)\n";
	checkInput(vekOd, INT_MAX, vekDo);
	cout << "Zadajte pohlavie\n";
	vypisTypovPohlavia();
	checkInput(1, 2, vyber2);
}

void Aplikacia::inputFilterVzdelanie(int& min, int& max, int& vyber1)
{
	cout << "Zadajte min pocet:\n";
	checkInput(0, INT_MAX, min);
	cout << "Zadajte max pocet:\n";
	checkInput(min, INT_MAX, max);
	cout << "Zadajte typ vzdelania\n";
	Aplikacia::vypisTypovVzdelanie();
	checkInput(1, 8, vyber1);
}


void Aplikacia::vykonajFiltrovanie(CompositeFilter<UzemnaJednotka>* filter)
{
	cout << "--------------------------------------------\n";
	CriterionUJNazov nazov;
	CriterionUJTyp typUJ;
	for (auto item : *uzemneJednotky_->getZoznam()) {
		if (filter->pass(*item->accessData())) {
			cout << "-----------\n";
			cout << UzemnaJednotka::typUJtoString(typUJ.evaluate(*item->accessData())) << "\n";
			cout << nazov.evaluate(*item->accessData()) << "\n";
			filter->printCriterion(*item->accessData());
			cout << "-----------\n\n";
		}
	}
	cout << "--------------------------------------------\n";
}

void Aplikacia::triedenieMenu()
{
	FilterAND<UzemnaJednotka> filter;
	smallSelectionMenu(filter);
	triedenieFilterMenu(&filter);
}

void Aplikacia::smallSelectionMenu(FilterAND<UzemnaJednotka>& filter)
{
	
	int input = 0;
	int vyber;
	string vyberText;

	while (input != 3) {

		cout << "Vyberte filter:\n";
		cout << "1. filter typ uzemnej jednotky\n";
		cout << "2. filter prislusnost\n";
		cout << "3. pokracovat\n";

		checkInput(1, 3, input);
		switch (input) {
		case 1:
			cout << "Zadajte typ uzemnej jednotky\n";
			Aplikacia::vypisTypovUzemnejJednotky();
			checkInput(1, 3, vyber);
			{
				FilterUJTyp* lesserFilter = new FilterUJTyp(static_cast<typUzemnejJednotky>(vyber - 1));
				filter.registerFilter(lesserFilter);
			}
			break;
		case 2:
			cout << "Zadajte nazov vyssieho celku\n";
			{
				UzemnaJednotka* uj = dajUzemnuJednotku(vyberText);
				FilterPrislusnost* lesserFilter = new FilterPrislusnost(uj);
				filter.registerFilter(lesserFilter);
			}
			break;
		case 3:
			break;
		}
	}
}

void Aplikacia::triedenieFilterMenu(CompositeFilter<UzemnaJednotka>* filter)
{
	cout << "Vyberte ulohu:\n";
	cout << "1. zoradit podla nazvu\n";
	cout << "2. pouzit filter vzdelanie pocet\n";
	cout << "3. pouzit filter vzdelanie podiel\n";
	cout << "4. pouzit filter vek pocet\n";
	cout << "5. pouzit filter vek podiel\n";

	int input;
	bool poradie;
	int min;
	int max;
	int vekOd;
	int vekDo;
	int vyber1;
	int vyber2;
	checkInput(1, 5, input);
	switch (input)
	{
	case 1:
		poradie = getPoradie();
		{
			structures::UnsortedSequenceTable<string, string>* triedenaTabulka = new structures::UnsortedSequenceTable<string, string>();
			CriterionUJNazov criterion;
			for (auto item : *uzemneJednotky_->getZoznam()) {
				if (filter->pass(*item->accessData())) {
					triedenaTabulka->insert(item->getKey(), criterion.evaluate(*item->accessData()));
				}
			}
			if (triedenaTabulka->size() > 0) {
				Sorting<string, string> sorter;
				sorter(*triedenaTabulka,poradie);
				for (auto item : *triedenaTabulka) {
					cout <<  item->getKey() << "\n";
				}
			}
			else {
				
				cout << "Zadana mnozina je prazdna!\n";
			}
			delete triedenaTabulka;
		}
		break;

	case 2:
		inputFilterVzdelanie(min, max, vyber1);
		{
			FilterVzdelaniePocet* lesserFilter = new FilterVzdelaniePocet(min, max, static_cast<typVzdelania>(vyber1 - 1));
			filter->registerFilter(lesserFilter);
			poradie = getPoradie();

			structures::UnsortedSequenceTable<string, int>* triedenaTabulka = new structures::UnsortedSequenceTable<string, int>();
			CriterionUJVzdelaniePocet criterion(static_cast<typVzdelania>(vyber1 - 1));
			for (auto item : *uzemneJednotky_->getZoznam()) {
				if (filter->pass(*item->accessData())) {
					triedenaTabulka->insert(item->getKey(), criterion.evaluate(*item->accessData()));
				}
			}

			if (triedenaTabulka->size() > 0) {
				CriterionUJVzdelaniePocet criterion(static_cast<typVzdelania>(vyber1 - 1));
				Sorting<string, int> sorter;
				sorter(*triedenaTabulka, poradie);
				for (auto item : *triedenaTabulka) {
					cout << item->accessData() << "   " << item->getKey() << "\n";
				}
			}
			else {
				cout << "Zadana mnozina je prazdna!\n";
			}
			delete triedenaTabulka;
		}
		break;

	case 3:
		inputFilterVzdelanie(min, max, vyber1);
		{
			FilterVzdelaniePodiel* lesserFilter = new FilterVzdelaniePodiel(min, max, static_cast<typVzdelania>(vyber1 - 1));
			filter->registerFilter(lesserFilter);
			poradie = getPoradie();

			structures::UnsortedSequenceTable<string, double>* triedenaTabulka = new structures::UnsortedSequenceTable<string, double>();
			CriterionUJVzdelaniePodiel criterion(static_cast<typVzdelania>(vyber1 - 1));
			for (auto item : *uzemneJednotky_->getZoznam()) {
				if (filter->pass(*item->accessData())) {
					triedenaTabulka->insert(item->getKey(), criterion.evaluate(*item->accessData()));
				}
			}

			if (triedenaTabulka->size() > 0) {
				Sorting<string, double> sorter;
				sorter(*triedenaTabulka, poradie);
				for (auto item : *triedenaTabulka) {
					cout << item->accessData() << "   " << item->getKey() << "\n";
				}
			}
			else {
				cout << "Zadana mnozina je prazdna!\n";
			}
			delete triedenaTabulka;
		}
		break;
	case 4:
		inputFilterVek(min, max, vekOd,vekDo, vyber2);
		{
			FilterVekPocet* lesserFilter = new FilterVekPocet(min, max, vekOd, vekDo, intToPohlavie(vyber2));
			filter->registerFilter(lesserFilter);
			poradie = getPoradie();

			structures::UnsortedSequenceTable<string, int>* triedenaTabulka = new structures::UnsortedSequenceTable<string, int>();
			CriterionUJVekPocet criterion(vyber1, intToPohlavie(vyber2));
			for (auto item : *uzemneJednotky_->getZoznam()) {
				if (filter->pass(*item->accessData())) {
					triedenaTabulka->insert(item->getKey(),criterion.evaluate(*item->accessData()));
				}
			}

			if (triedenaTabulka->size() > 0) {
				Sorting<string, int> sorter;
				sorter(*triedenaTabulka, poradie);
				for (auto item : *triedenaTabulka) {
					cout << item->accessData() << "   " << item->getKey() << "\n";
				}
			}
			else {
				cout << "Zadana mnozina je prazdna!\n";
			}
			delete triedenaTabulka;
		}
		break;
	case 5:
		inputFilterVek(min, max, vekOd, vekDo, vyber2);
		{
			FilterVekPodiel* lesserFilter = new FilterVekPodiel(min, max, vekOd, vekDo, intToPohlavie(vyber2));
			filter->registerFilter(lesserFilter);
			poradie = getPoradie();

			structures::UnsortedSequenceTable<string, double>* triedenaTabulka = new structures::UnsortedSequenceTable<string, double>();
			CriterionUJVekPodiel criterion(vekOd,vekDo, intToPohlavie(vyber2));
			for (auto item : *uzemneJednotky_->getZoznam()) {
				if (filter->pass(*item->accessData())) {
					triedenaTabulka->insert(item->getKey(), criterion.evaluate(*item->accessData()));
				}
			}

			if (triedenaTabulka->size() > 0) {
				Sorting<string, double> sorter;
				sorter(*triedenaTabulka, poradie);
				for (auto item : *triedenaTabulka) {
					cout << item->accessData() << "   " << item->getKey() << "\n";
				}
			}
			else {
				cout << "Zadana mnozina je prazdna!\n";
			}
			delete triedenaTabulka;
		}
		break;
	}

}

bool Aplikacia::getPoradie()
{
	cout << "Zoradit:\n";
	cout << "1. vzostupne\n";
	cout << "2. zostupne\n";

	int input;
	checkInput(1, 2, input);
	switch (input)
	{
	case 1:
		return true;

	case 2:
		return false;
	}
}

void Aplikacia::vyberNajlepsichMenu()
{

	FilterAND<UzemnaJednotka> filter;
	smallSelectionMenu(filter);
	vybejNajlepsichFilterMenu(&filter);
}

void Aplikacia::vybejNajlepsichFilterMenu(CompositeFilter<UzemnaJednotka>* filter)
{
	cout << "Vyberte selekcne kriterium:\n";
	cout << "1. najvacsia vekova skupina\n";
	cout << "2. najmensia vekova skupina\n";

	int min;
	int max;
	int vyber1;
	int input;
	checkInput(1, 2, input);
	switch (input)
	{
	case 1:
		inputFilterVekovaSkupina(min, max, vyber1);
		{
			double najvacsiPodiel = 0;
			FilterVekovaSkupinaPodiel* filterSkupina = new FilterVekovaSkupinaPodiel(min, max, intToEVS(vyber1));
			filter->registerFilter(filterSkupina);
			UzemnaJednotka* najlepsi = nullptr;
			CriterionUJVekovaSkupinaPodiel podiel(intToEVS(vyber1));
			for (auto item : *uzemneJednotky_->getZoznam()) {
				if (filter->pass(*item->accessData())) {
					double test = podiel.evaluate(*item->accessData());
					if (test > najvacsiPodiel) {
						najvacsiPodiel = test;
						najlepsi = item->accessData();
					}
				}
			}
			if (najlepsi != nullptr) {
				while (najlepsi != nullptr) {
					cout << najlepsi->typUJtoString(najlepsi->getTypUJ()) << "\n";
					cout << najlepsi->getNazov() << "\n";
					cout << "Podiel: " << podiel.evaluate(*najlepsi) << "\n\n";
					najlepsi = najlepsi->getNadradena();
				}
			}
			else {
				cout << "Zadana mnozina je prazdna!\n";
			}
		}
		break;
	case 2:
		inputFilterVekovaSkupina(min, max, vyber1);
		{
			double najmensiPodiel = INT_MAX;
			FilterVekovaSkupinaPodiel* filterSkupina = new FilterVekovaSkupinaPodiel(min, max, intToEVS(vyber1));
			filter->registerFilter(filterSkupina);
			UzemnaJednotka* najlepsi = nullptr;
			CriterionUJVekovaSkupinaPodiel podiel(intToEVS(vyber1));
			for (auto item : *uzemneJednotky_->getZoznam()) {
				if (filter->pass(*item->accessData())) {
					double test = podiel.evaluate(*item->accessData());
					if (test < najmensiPodiel) {
						najmensiPodiel = test;
						najlepsi = item->accessData();
					}
				}
			}
			if (najlepsi != nullptr) {
				while (najlepsi != nullptr) {
					cout << najlepsi->typUJtoString(najlepsi->getTypUJ()) << "\n";
					cout << najlepsi->getNazov() << "\n";
					cout << "Podiel: " << podiel.evaluate(*najlepsi) << "\n\n";
					najlepsi = najlepsi->getNadradena();
				}
			}
			else {
				cout << "Zadana mnozina je prazdna!\n";
			}
		}
		break;
	}
}

void Aplikacia::checkInput(int min, int max,int& input) 
{
	string text;
	bool opakovat = true;
	while (opakovat) {
		try
		{
			cin >> text;
			input = stod(text);
			if (input < min || input > max) {
				cout << "Neplatny vstup zopakujte volbu:\n";
				opakovat = true;
			}
			else {
				opakovat = false;
			}
		}
		catch (std::exception& e) {
			cout << "Neplatny vstup zopakujte volbu:\n";
			opakovat = true;
		}
	}
}

UzemnaJednotka* Aplikacia::dajUzemnuJednotku(string text)
{
	getline(cin, text); 
	getline(cin, text);
	UzemnaJednotka* uj;
	while (!uzemneJednotky_->getZoznam()->tryFind(text, uj)) {
		cout << "Uzemna jednotka sa nenasla, zopakujte vstup:\n";
		getline(cin, text);
	}
	return uj;
}

void Aplikacia::vypisTypovVzdelanie()
{
	cout << "1. BEZ_UKONCENEHO_VZDELANIA\n";
	cout << "2. ZAKLADNE\n";
	cout << "3. UCNOVSKE\n";
	cout << "4. STREDNE\n";
	cout << "5. VYSSIE\n";
	cout << "6. VYSOKOSKOSLE\n";
	cout << "7. BEZ_VZDELANIA\n";
	cout << "8. NEZISTENE\n";
}

void Aplikacia::vypisTypovUzemnejJednotky()
{
	cout << "1. OBEC\n";
	cout << "2. OKRES\n";
	cout << "3. KRAJ\n";
}

void Aplikacia::vypisTypovPohlavia()
{
	cout << "1. MUZ\n";
	cout << "2. ZENA\n";
}

void Aplikacia::vypisTypovEVS()
{
	cout << "1. PREDPRODUKTIVNY\n";
	cout << "2. PRODUKTIVNY\n";
	cout << "3. POPRODUKTIVNY\n";
}

Pohlavie Aplikacia::intToPohlavie(int typ)
{
	if (typ == 1) {
		return MUZ;
	}
	return ZENA;
}

EVS Aplikacia::intToEVS(int typ)
{
	if (typ == 1) {
		return PREDPRODUKTIVNY;
	}
	else if (typ == 2) {
		return PRODUKTIVNY;
	}
	else {
		return POPRODUKTIVNY;
	}
}

void Aplikacia::vypisKriteria(UzemnaJednotka* objektNaVypis)
{
	CriterionUJNazov criterionNazov;
	CriterionUJTyp criterionTyp;
	CriterionUJVzdelaniePocet vzdelaniePocetNevzdelany(BEZ_UKONCENEHO_VZDELANIA);
	CriterionUJVzdelaniePocet vzdelaniePocetZakladne(ZAKLADNE);
	CriterionUJVzdelaniePocet vzdelaniePocetUcnovske(UCNOVSKE);
	CriterionUJVzdelaniePocet vzdelaniePocetStredne(STREDNE);
	CriterionUJVzdelaniePocet vzdelaniePocetVyssie(VYSSIE);
	CriterionUJVzdelaniePocet vzdelaniePocetVysokoskolske(VYSOKOSKOSLE);
	CriterionUJVzdelaniePocet vzdelaniePocetBezVzdelania(BEZ_VZDELANIA);
	CriterionUJVzdelaniePocet vzdelaniePocetNezistene(NEZISTENE);

	CriterionUJVekovaSkupinaPocet skupinaPocetPredproduktivny(PREDPRODUKTIVNY);
	CriterionUJVekovaSkupinaPocet skupinaPocetProduktivny(PRODUKTIVNY);
	CriterionUJVekovaSkupinaPocet skupinaPocetPoproduktivny(POPRODUKTIVNY);
	UzemnaJednotka* temp = objektNaVypis;
	while (temp != nullptr) {
		cout << "\n" << criterionNazov.evaluate(*temp) << "\n" << temp->typUJtoString(criterionTyp.evaluate(*temp)) << "\n";
		cout << "Bez ukonceneho vzdelania: " << vzdelaniePocetNevzdelany.evaluate(*temp) << "\n";
		cout << "So zakladnym vzdelanim: " << vzdelaniePocetZakladne.evaluate(*temp) << "\n";
		cout << "S ucnovskym vzdelanim: " << vzdelaniePocetUcnovske.evaluate(*temp) << "\n";
		cout << "So strednym vzdelanim: " << vzdelaniePocetStredne.evaluate(*temp) << "\n";
		cout << "S vyssim vzdelanim: " << vzdelaniePocetVyssie.evaluate(*temp) << "\n";
		cout << "S vysokoskolskym vzdelanim: " << vzdelaniePocetVysokoskolske.evaluate(*temp) << "\n";
		cout << "Bez vzdelania: " << vzdelaniePocetBezVzdelania.evaluate(*temp) << "\n";
		cout << "S nezistenim vzdelanim: " << vzdelaniePocetNezistene.evaluate(*temp) << "\n";

		cout << "Pocet predproduktivnych obyvatelov: " << skupinaPocetPredproduktivny.evaluate(*temp) << "\n";
		cout << "Pocet produktivnych obyvatelov: " << skupinaPocetProduktivny.evaluate(*temp) << "\n";
		cout << "Pocet poproduktivnych obyvatelov: " << skupinaPocetPoproduktivny.evaluate(*temp) << "\n" << "\n";

		temp = temp->getNadradena();
	}
}
