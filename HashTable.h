#pragma once
#include <iostream>

class HashTable
{
private:
    int size;
    int length;
    int * arr;
    int * statusArr;
public:
    HashTable(int size);
    void insert(int hashIndex, const fileNode& item);
    void del(fileNode item);
    fileNode search(fileNode item);
    ~HashTable();
};

struct fileNode
{
    int count;
    std::string fileName;
};

typedef struct fileNode fileNode;
