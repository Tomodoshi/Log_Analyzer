#include "startup.cpp"

int main()
{
    HashTable table(3557);
    setUp(table);
    table.print();
    return 0;
}