#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char data;
    int frequency;
    Node* left, * right;
    Node(char d, int f, Node* l = nullptr, Node* r = nullptr)
    {
        data = d;
        frequency = f;
        left = l;
        right = r;
    }
};

class compare {
public:
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

void generateCodes(Node* root, string code, map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        huffmanCodes[root->data] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

pair<Node *, string> buildHuffmanTree(string text) {
    map<char, int> frequencyMap;
    for (char ch : text) {
        frequencyMap[ch]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;

    for (auto pair : frequencyMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* newNode = new Node('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    map<char, string> huffmanCodes;
    Node* root = pq.top();
    string code = "";
    generateCodes(root, code, huffmanCodes);

    vector<pair<char, int>> sortedCodes;
    for (auto pair : huffmanCodes) {
        sortedCodes.push_back(make_pair(pair.first, frequencyMap[pair.first]));
    }

    sort(sortedCodes.begin(), sortedCodes.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    });

    cout << "Huffman Codes (sorted by frequency):\n";
    for (auto pair : sortedCodes) {
        cout << pair.first << " : " << pair.second << " : " << huffmanCodes[pair.first] << "\n";
    }

    string encodedString = "";
    for (char ch : text) {
        encodedString += huffmanCodes[ch];
    }

    // cout << "Encoded String: " << encodedString << endl;

    return {root, encodedString};
}

string decodeHuffman(string encodedString, Node * root) {
    Node * curr = root;
    string decode = "";
    for (char bit : encodedString) {
        if (bit == '0') {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
        
        if (curr->left == nullptr && curr->right == nullptr)
        {
            decode += curr->data;
            curr = root;
        }
    }
    return decode;
}


int main()
{
    string text = "Huffman coding is a data compression algorithm.";
    pair<Node *, string> pr = buildHuffmanTree(text);
    Node * root = pr.first;
    string encodedString = pr.second;
    string decodedString = decodeHuffman(encodedString, root);
    cout << encodedString << endl;
    cout << decodedString << endl;
    return 0;
}
