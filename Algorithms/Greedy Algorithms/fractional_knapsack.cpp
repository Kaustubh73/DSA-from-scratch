#include <bits/stdc++.h>
using namespace std;

class Item {
    public:
        int value;
        int weight;
};

bool compareItems(const Item& item1, const Item& item2)
{
    double ratio1 = (double)item1.value / item1.weight;
    double ratio2 = (double)item2.value / item2.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const auto& item : items) {
        if (currentWeight + item.weight <= capacity) {
            totalValue += item.value;
            currentWeight += item.weight;
        }
        else
        {
            int remainingCapcity = capacity - currentWeight;
            totalValue += (double)item.value * remainingCapcity / item.weight;
            break;
        }
    }
    return totalValue;
}

int main() {
    int capacity = 50;
    vector<Item> items = {{60,10}, {100,20}, {120,30}};

    double maxTotalValue = fractionalKnapsack(capacity, items);

    cout << "Maximum value : " << maxTotalValue << endl;

    return 0;
}