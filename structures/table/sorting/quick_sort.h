#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{
    /// <summary> Triedenie Quick sort. </summary>
    /// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
    /// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
    template <typename K, typename T>
    class QuickSort : public Sort<K, T>
    {
    public:
        /// <summary> Utriedi tabulku triedenim Quick sort. </summary>
        /// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
        void sort(UnsortedSequenceTable<K, T>& table) override;
    private:
        void quick(int min, int max, UnsortedSequenceTable<K, T>& table);
    };

    template<typename K, typename T>
    inline void QuickSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
    {
        quick(0, table.size() - 1, table);
    }

    template<typename K, typename T>
    inline void QuickSort<K, T>::quick(int min, int max, UnsortedSequenceTable<K, T>& table)
    {
        auto pivot = table.getItemAtIndex((min + max) / 2).getKey();
        int lavy = min;
        int pravy = max;
        do {
            while (table.getItemAtIndex(lavy).getKey() < pivot)
            {
                lavy++;
            }
            while (table.getItemAtIndex(pravy).getKey() > pivot)
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
            quick(min, pravy, table);
        }
        if (lavy < max)
        {
            quick(lavy, max, table);
        }
    }
}