#include <bits/stdc++.h>

using namespace std;

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    vector<pair<int,int>> table;
    vector<bool> isOccupied;

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE);
        isOccupied.resize(TABLE_SIZE, false);
    }

    void insert(int key, int value) {
        int index = hashFunction(key);

        while (isOccupied[index]) {
            index = (index + 1) % TABLE_SIZE;
        }
        table[index] = {key, value};
        isOccupied[index] = true;

    }

    void remove(int key) {
        int index = hashFunction(key);
        while (isOccupied[index]) {
            if (table[index].first == key) {
                isOccupied[index] = false;
                return;
            }

            index = (index + 1) % TABLE_SIZE;
        }
    }

    int search(int key) {
        int index = hashFunction(key);
        while (isOccupied[index]) {
            if (table[index].first == key)
            {
                return table[index].second;
            }

            index = (index + 1) % TABLE_SIZE;
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