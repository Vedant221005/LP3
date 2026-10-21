#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Node {
public:
    char value;
    int frequency;
    Node *left, *right;
    Node(char v = '\0', int f = 0) {
        value = v;
        frequency = f;
        left = right = NULL;
    }
};
class HuffmanEncoding {
private:
    vector<Node*> q;
    map<char, string> encoding;
    string str;
public:
    HuffmanEncoding(string s) {
        str = s;
    }
    void charFrequency() {
        map<char, int> count;
        for (char ch : str)
            count[ch]++;
        for (auto x : count) {
            q.push_back(new Node(x.first, x.second));
        }
        sort(q.begin(), q.end(),
             [](Node* a, Node* b) {
                 return a->frequency < b->frequency;
             });
    }
    void buildTree() {
        while (q.size() > 1) {
            Node* n1 = q[0];
            Node* n2 = q[1];
            q.erase(q.begin());
            q.erase(q.begin());
            Node* node = new Node('#', n1->frequency + n2->frequency);
            node->left = n1;
            node->right = n2;
            q.push_back(node);
            sort(q.begin(), q.end(),
                 [](Node* a, Node* b) {
                     return a->frequency < b->frequency;
                 });
        }
    }
    void helper(Node* node, string code = "") {
        if (!node)
            return;
        if (node->value != '#') {
            encoding[node->value] = code;
            return;
        }
        helper(node->left, code + "0");
        helper(node->right, code + "1");
    }
    void huffmanEncoding() {
        helper(q[0], "");
    }
    void printEncoding() {
        cout << "\nChar | Huffman Code\n";
        for (auto x : encoding) {
            cout << "  " << x.first << "   |   " << x.second << endl;
        }
    }
    void encode() {
        charFrequency();
        buildTree();
        huffmanEncoding();
        printEncoding();
    }
};
int main() {
    string str;
    cout << "Enter string to be encoded: ";
    cin >> str;
    HuffmanEncoding h(str);
    h.encode();
    return 0;
}
