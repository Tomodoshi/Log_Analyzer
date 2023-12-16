#pragma once
#include <iostream>

#define MAXNAMELEN 50
typedef struct fileNode fileNode;

struct fileNode
{
    uint16_t count = 1;
    std::string fileName;
};


uint16_t hashFunc(const std::string& s, int size);

class HashTable
{
private:
    int size;
    int length;
    fileNode *arr;
    fileNode *maxNodes;
    int * statusArr;
public:
    HashTable(int size);
    void insert(fileNode& item);
    void search(fileNode item, bool &found );
    void print();
    int getSize();
    ~HashTable();
};


