#pragma once
#include "UzemneJednotkyTable.h"
#include "m_debug.h"
class DataInput
{
private:
	structures::Array<int>* loadArray(string& nazov, string& kod, fstream* input,size_t size);
	const char semicolon_ = ';';
public:
	void loadData(UzemneJednotkyTable& table);
};

