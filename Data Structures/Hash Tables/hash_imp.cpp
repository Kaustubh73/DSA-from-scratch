#include <bits/stdc++.h>

using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    list<pair<int,int>> table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    void insert(int key, int value) {
        int index = hashFunction(key);
        table[index].push_back({key, value});
    }

    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); it++)
        {
            if (it->first == key)
            {
                table[index].erase(it);
                return;
            }
        }
    }

    int search(int key) {
        int index = hashFunction(key);
        for (const auto& pair : table[index])
        {
            if (pair.first == key) {
                return pair.second;
            }
        }
        return -1;
    }
};



int main()
{

    HashTable hashTable;

    hashTable.insert(5, 10);
    hashTable.insert(15, 20);
    hashTable.insert(25,30);

    cout << hashTable.search(15) << endl;

    hashTable.remove(15);

    cout << hashTable.search(15) << endl;
    return 0;
}