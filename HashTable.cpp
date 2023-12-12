#include <iostream>
#include <string.h>
#include "HashTable.h"


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

void HashTable::insert(fileNode& item)
{
    int hashIndex = hashFunc(item.fileName, size);
    uint16_t pcount = 0;
    uint16_t inc = 1;

    while(statusArr[hashIndex] == 1 && arr[hashIndex].fileName != item.fileName && pcount < size/2)
    {
        pcount++;
        hashIndex = (hashIndex % inc) % size;
        inc += 2;
    }

    if(statusArr[hashIndex] != 1)
    {
        arr[hashIndex].fileName = item.fileName;
        statusArr[hashIndex] = 1;
        length++;
    }

    else if (arr[hashIndex].fileName == item.fileName)
        item.count++;
    else
        std::cerr << "Error: The table is full. " << "Unable to resolve the collision" << std::endl;

}

int HashTable::getSize()
{
    return size;
}

void HashTable::del(fileNode item)
{
    //ask the prof about passing by value in the hash.H file
}

void HashTable::search(fileNode item, bool &found)
{
    int hashIndex = hashFunc(item.fileName, size);
    int pCount;
	int inc;

	pCount = 0;
	inc = 1;

	while (statusArr[hashIndex] != 0 && arr[hashIndex].fileName != item.fileName && pCount < size / 2)
	{
		pCount++;
		hashIndex = (hashIndex + inc ) % size;
		inc = inc + 2;
	}

	if (statusArr[hashIndex] == 1 && arr[hashIndex].fileName == item.fileName )
	{
		hashIndex = hashIndex;
		found = true;
	}
	else
		found = false;
}

void HashTable::print()
{

    fileNode maxNode;
    maxNode.count = 0;
    fileNode nodeArray[10];
    int x = 0;

    while(x < 10){
        for(int i = 0; i < size; i++)
        {
            if(statusArr[i])
                if(maxNode.count < arr[i].count && nodeArray[x].fileName != arr[i].fileName) maxNode = arr[i];
        }
        nodeArray[x] = maxNode;
        x++;
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << nodeArray[i].fileName << "\t : \t" << nodeArray[i].count << "\n";
    }
    
}




