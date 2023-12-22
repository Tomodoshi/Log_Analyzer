#include <iostream>
#include "HashTable.h"
#include <string.h>
#include "sortingAlg.cpp"
#include <vector>


uint16_t hashFunc(const std::string& s, int size)
{
    uint16_t hashValue = 0;

    for (size_t i = 0; i < s.length(); i++) {
        hashValue += static_cast<unsigned long long>(s[i]) * (i + 1);
    }

    return hashValue % size;
}

HashTable::HashTable(int size)
{
    length = 0;
    this-> size = size;
    arr = new fileNode[size];
    statusArr = new int[size];

    for (int i = 0; i < size; i++) statusArr[i] = 0;
    
}

HashTable::~HashTable()
{
    delete[] arr;
    delete[] statusArr;
}

void HashTable::insert(fileNode &item)
{
    int hashIndex = hashFunc(item.fileName, size);
    uint16_t pcount = 0;
    uint16_t inc = 1;

    

    while (statusArr[hashIndex] == 1 && arr[hashIndex].fileName != item.fileName && pcount < size / 2)
    {
        pcount++;
        hashIndex = (hashIndex + inc) % size;
        inc += 2;
    }

    if (statusArr[hashIndex] != 1)
    {
        arr[hashIndex] = item;
        statusArr[hashIndex] = 1;
        length++;
        // Update the count in uMap
        uMap[item.fileName] = item;
    }
    else if (arr[hashIndex].fileName == item.fileName)
    {
        arr[hashIndex].count++;
        // Update the count in uMap
        //uMap[item.fileName].count++;
    }
    else
    {
        std::cerr << "Error: The table is full. " << "Unable to resolve the collision" << std::endl;    
    }
}

int HashTable::getSize(){ return size; }

void HashTable::print()
{
    fileNode toBeSorted[size];
    for (int i = 0; i < size; i++)
    {
        toBeSorted[i] = arr[i];
    }

    quickSort(toBeSorted, 0, size);

    for (int i = 0; i < 10; i++)
    {
        std::cout << toBeSorted[i].fileName << "\t : \t" << toBeSorted[i].count << "\n";
    }

}

