#include "HashTable.h"

template<typename T> 
HashTable<T>::HashTable(int size)
{
    this-> size = size;
    * arr = new int[size];
    * statusArr = new int[size];
    length = 0;
}

template<typename T>
HashTable<T>::~HashTable()
{
    delete arr;
    delete statusArr;
}

template<typename T>
void HashTable<T>::insert(T item)
{

}

template<typename T>
void HashTable<T>::del(T item)
{

}

template<typename T>
T HashTable<T>::search(T item)
{

}

// ------------------------------------- // Helper func

template<typename T>
int hashFunc(T item)
{
T is a string;
}
