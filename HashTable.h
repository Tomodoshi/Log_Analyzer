#pragma once
#include <iostream>

template<typename T>

class HashTable
{
private:
    int size;
    int length;
    int * arr;
    int * statusArr;
public:
    HashTable(int size);
    void insert(T item);
    void del(T item);
    T search(T item);
    ~HashTable();
};