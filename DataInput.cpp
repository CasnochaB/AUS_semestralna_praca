#include "DataInput.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;



structures::Array<int>* DataInput::loadArray(string& nazov, string& kod,fstream* input,size_t size)
{
	structures::Array<int>* inputArray = new structures::Array<int>(size);
	string garbage;
	getline(*input, garbage);
	stringstream dataInput(garbage);
	string data;
	getline(dataInput, kod, semicolon_);
	getline(dataInput, nazov, semicolon_);
	getline(dataInput, data, semicolon_);
	for (int i = 0; i < inputArray->size(); i++)
	{
		inputArray->at(i) = stoi(data);
		getline(dataInput, data, semicolon_);
	}
	return inputArray;
}

void DataInput::loadData(UzemneJednotkyTable& table)
{
	string riadok;
	fstream FileVek("Data/vek.csv");
	fstream FileObce("Data/obce.csv");
	fstream FileVzdelanie("Data/vzdelanie.csv");
	fstream FileOkresy("Data/okresy.csv");
	fstream FileKraje("Data/kraje.csv");


	if (!(FileVek.is_open() && FileObce.is_open() && FileVzdelanie.is_open() && FileOkresy.is_open() && FileKraje.is_open())) {
		throw std::exception("csv file is open");
	}

	getline(FileObce, riadok);
	getline(FileOkresy, riadok);
	getline(FileVek, riadok);
	getline(FileVzdelanie, riadok);
	getline(FileKraje, riadok);
	int j = 0;
	int i = 0;
	int k = 0;
	string kodObec;
	string OfficialTitleObec;
	string mediumTitleObec;
	string shortTitleObec;
	string noteObec;
	while (j < 2927)
	{	
		j++;	
		structures::Array<int>* vekObce = loadArray(shortTitleObec, kodObec,  &FileVek, 202);
		structures::Array<int>* vzdelanieObce = loadArray(shortTitleObec, kodObec,  &FileVzdelanie, 8);
		/*cout << j << " ";
		cout << kodObec + "-";
		cout << shortTitleObec + "-";
		cout << noteObec + "\n";*/
		table.pridajUzemnuJednotku(shortTitleObec, kodObec, OBEC, vekObce, vzdelanieObce);
	}

	string kodOkres;
	string OfficialTitleOkres;
	string mediumTitleOkres;
	string shortTitleOkres;
	string noteOkres;

	structures::UnsortedSequenceTable<string, UzemnaJednotka*>* okresy =new structures::UnsortedSequenceTable<string, UzemnaJednotka*>();

	while (i < 79) {

		getline(FileOkresy, kodOkres, semicolon_);
		getline(FileOkresy, kodOkres, semicolon_);
		i++;
		getline(FileOkresy, OfficialTitleOkres, semicolon_);
		getline(FileOkresy, mediumTitleOkres, semicolon_);
		getline(FileOkresy, shortTitleOkres, semicolon_);
		getline(FileOkresy, noteOkres);
		UzemnaJednotka* NadradenyOkres = new UzemnaJednotka(OfficialTitleOkres, kodOkres,  OKRES);
		table.pridajUzemnuJednotku(NadradenyOkres);
		structures::Array<int>* vekOkres = new structures::Array<int>(202);
		structures::Array<int>* vzdelanieOkres = new structures::Array<int>(8);
		okresy->insert(kodOkres, NadradenyOkres);
		for (auto item : *table.getZoznam()) {
			string kod = item->accessData()->getKod();
			kod = kod.substr(0, 6);
			if (kod == kodOkres && item->accessData()->getTypUJ() == OBEC) {
				item->accessData()->setNadradena(NadradenyOkres);
				for (int x = 0; x < vekOkres->size(); x++) {
					if (x < 8) {
						vzdelanieOkres->at(x) += item->accessData()->getVzdelanie(x);
					}
					vekOkres->at(x) += item->accessData()->getVek(x);
				}
			}
		}		
		NadradenyOkres->setVek(vekOkres);
		NadradenyOkres->setVzdelanie(vzdelanieOkres);
	}

	string kodKraj;
	string OfficialTitleKraj;
	string mediumTitleKraj;
	string shortTitleKraj;
	string noteKraj;

	while (k < 9) {

		k++;

		getline(FileKraje, kodKraj, semicolon_);
		getline(FileKraje, kodKraj, semicolon_);

		getline(FileKraje, OfficialTitleKraj, semicolon_);
		getline(FileKraje, mediumTitleKraj, semicolon_);
		getline(FileKraje, shortTitleKraj, semicolon_);
		getline(FileKraje, noteKraj);
		kodKraj = noteKraj.substr(5);
		structures::Array<int>* vekKraj = new structures::Array<int>(202);
		structures::Array<int>* vzdelanieKraj = new structures::Array<int>(8);
		UzemnaJednotka* NadradenyKraj = new UzemnaJednotka(OfficialTitleKraj, kodKraj, KRAJ);
		table.pridajUzemnuJednotku(NadradenyKraj);
		for (auto item : *okresy) {
			string kod = item->accessData()->getKod();
			kod = kod.substr(0, 5);
			if (kod == kodKraj && item->accessData()->getTypUJ() == OKRES) {
				item->accessData()->setNadradena(NadradenyKraj);
				for (int x = 0; x < vekKraj->size(); x++) {
					if (x < 8) {
						vzdelanieKraj->at(x) += item->accessData()->getVzdelanie(x);
					}
					vekKraj->at(x) += item->accessData()->getVek(x);
				}
			}
		}
		NadradenyKraj->setVek(vekKraj);
		NadradenyKraj->setVzdelanie(vzdelanieKraj);
	}
	delete okresy;
}






