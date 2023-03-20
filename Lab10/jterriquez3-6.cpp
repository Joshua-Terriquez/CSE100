#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// A Huffman tree node struct

struct Min_Heap_Node {

char data;

unsigned freq;

// Left and right child

Min_Heap_Node *left, *right;

Min_Heap_Node(char data, unsigned freq)

{

left = right = NULL;

this->data = data;

this->freq = freq;

}

};

// For comparison of two heap nodes

struct compare {

bool operator()(Min_Heap_Node* l, Min_Heap_Node* r)

{

return (l->freq > r->freq);

}

};

// Prints huffman codes from root

void printCodes(struct Min_Heap_Node* root, char ans , string str)

{

if (!root)

return;

if (root->data != '$'){
if(ans==root->data)
cout << root->data << ":" << str << "\n";
}

printCodes(root->left,ans, str + "0");

printCodes(root->right,ans, str + "1");

}

// The main function that builds a Huffman Tree and

// print codes by traversing the built Huffman Tree

void HuffmanCodes(char data[], int freq[], int size)

{

struct Min_Heap_Node *left, *right, *top;

// Create a min heap & inserts all characters of data[]

priority_queue<Min_Heap_Node*, vector<Min_Heap_Node*>, compare> minHeap;

for (int i = 0; i < size; ++i)

minHeap.push(new Min_Heap_Node(data[i], freq[i]));

// Iterate while size of heap doesn't become 1

while (minHeap.size() != 1) {

// Extract the two minimum freq items from min heap

left = minHeap.top();

minHeap.pop();

right = minHeap.top();

minHeap.pop();

// Create a new internal node with

// frequency equal to the sum of the

// two nodes frequencies. Make the

// two extracted node as left and right children

// of this new node. Add this node

// to the min heap '$' is a special value

// for internal nodes, not used

top = new Min_Heap_Node('$', left->freq + right->freq);

top->left = left;

top->right = right;

minHeap.push(top);

}

// Print Huffman codes using

// the Huffman tree built above

for(int i=0;i<6;++i){
printCodes(minHeap.top(),data[i], "");
}

}

// Test Function

int main()

{

char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F' };

int freq[6] ;

int size = sizeof(arr) / sizeof(arr[0]);

for(int i=0;i<size;i++)

cin>>freq[i];

HuffmanCodes(arr, freq, size);

return 0;

}