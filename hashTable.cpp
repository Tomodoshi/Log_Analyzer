#include <iostream>
#include "HashTable.h"
#include <string>

HashTable::HashTable(int size)
{
    length = 0;
    this-> size = size;
    * arr = new std::string[size];
    * statusArr = new int[size];

    for (int i = 0; i < size; i++) statusArr[i] = 0;
    
}

HashTable::~HashTable()
{
    delete arr;
    delete statusArr;
}

void HashTable::insert(int hashIndex, const fileNode& item)
{
    uint16_t pcount = 0;
    uint16_t inc = 1;

    while(statusArr[hashIndex] == 1 && arr[hashIndex] != item.fileName && pcount < size/2)
    {
        pcount++;
        hashIndex = (hashIndex % inc) % size;
        inc += 2;
    }

    if(statusArr[hashIndex] != 1)
    {
        arr[hashIndex] = item.fileName;
        statusArr[hashIndex] = 1;
        length++;
    }

    else if
}

void HashTable::del(fileNode item)
{

}

fileNode HashTable::search(fileNode item)
{

}

// ------------------------------------- // Helper func

unsigned long long hashFunc(const std::string& s) {
    unsigned long long hashValue = 0;

    for (size_t i = 0; i < s.length(); ++i) {
        // Multiply the ASCII value of the character by its position and add to the hash
        hashValue += static_cast<unsigned long long>(s[i]) * (i + 1);
    }

    return hashValue % 3557;
}
