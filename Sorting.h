#pragma once
#include "structures/table/unsorted_sequence_table.h"

template <typename K, typename T>
class Sorting
{
public:
	void sort(structures::UnsortedSequenceTable<K, T>& table, bool poradie);
    void operator()(structures::UnsortedSequenceTable<K, T>& table, bool poradie);
private:
	void asscendingSort(int min, int max, structures::UnsortedSequenceTable<K, T>& table);
	void descendingSort(int min, int max, structures::UnsortedSequenceTable<K, T>& table);
};

template<typename K, typename T>
inline void Sorting<K, T>::operator()(structures::UnsortedSequenceTable<K, T>& table, bool poradie)
{
    this->sort(table,poradie);
}
template<typename K, typename T>
inline void Sorting<K, T>::sort(structures::UnsortedSequenceTable<K, T>& table, bool poradie)
{
	if (poradie) {
		asscendingSort(0, table.size() - 1, table);
	}
	else {
		descendingSort(0, table.size() - 1, table);
	}
}

template<typename K, typename T>
inline void Sorting<K, T>::asscendingSort(int min, int max, structures::UnsortedSequenceTable<K, T>& table)
{
    auto pivot = table.getItemAtIndex((min + max) / 2).accessData();
    int lavy = min;
    int pravy = max;
    do {
        while (table.getItemAtIndex(lavy).accessData() < pivot)
        {
            lavy++;
        }
        while (table.getItemAtIndex(pravy).accessData() > pivot)
        {
            pravy--;
        }
        if (lavy <= pravy)
        {
            table.swap(lavy, pravy);
            lavy++;
            pravy--;
        }
    } while (lavy <= pravy);
    if (min < pravy)
    {
        asscendingSort(min, pravy, table);
    }
    if (lavy < max)
    {
        asscendingSort(lavy, max, table);
    }
}

template<typename K, typename T>
inline void Sorting<K, T>::descendingSort(int min, int max, structures::UnsortedSequenceTable<K, T>& table)
{
    auto pivot = table.getItemAtIndex((min + max) / 2).accessData();
    int lavy = min;
    int pravy = max;
    do {
        while (table.getItemAtIndex(lavy).accessData() > pivot)
        {
            lavy++;
        }
        while (table.getItemAtIndex(pravy).accessData() < pivot)
        {
            pravy--;
        }
        if (lavy <= pravy)
        {
            table.swap(lavy, pravy);
            lavy++;
            pravy--;
        }
    } while (lavy <= pravy);
    if (min < pravy)
    {
        descendingSort(min, pravy, table);
    }
    if (lavy < max)
    {
        descendingSort(lavy, max, table);
    }
}
