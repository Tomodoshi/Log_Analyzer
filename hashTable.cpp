#include <iostream>
#include "HashTable.h"
#include <string.h>


HashTable::HashTable(int size)
{
    length = 0;
    this-> size = size;
    arr = new char*[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new char[MAXNAMELEN];
    }
    
    statusArr = new int[size];

    for (int i = 0; i < size; i++) statusArr[i] = 0;
    
}

HashTable::~HashTable()
{
    delete arr;
    delete statusArr;
}

void HashTable::insert(int hashIndex, fileNode& item)
{
    uint16_t pcount = 0;
    uint16_t inc = 1;

    while(statusArr[hashIndex] == 1 &&  arr[hashIndex] != item.fileName && pcount < size/2)
    {
        pcount++;
        hashIndex = (hashIndex % inc) % size;
        inc += 2;
    }

    if(statusArr[hashIndex] != 1)
    {
        const char *charArray = (item.fileName).c_str();
        char *copyArray = new char[MAXNAMELEN + 1];
        strcpy(copyArray,charArray);
        arr[hashIndex] = copyArray;
        delete[] copyArray;
        statusArr[hashIndex] = 1;
        length++;
    }

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
