// C++ program to demonstrate auto-complete feature 
// using Trie data ure. 
#include <iostream>
#include <string>
using namespace std;

// Alphabet size (# of symbols) 
#define ALPHABET_SIZE (26) 

// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

// trie node 
struct TrieNode
{
	TrieNode* children[ALPHABET_SIZE];
	TrieNode* parent;
	// isWordEnd is true if the node represents 
	// end of a word 
	bool isWordEnd;
};


TrieNode* getNode(void);
bool isLastNode(TrieNode* node);
bool insertT(TrieNode* root, string key);
bool delT(TrieNode* root, string key);
bool delR(TrieNode* prev, TrieNode* root, string key);
bool searchT(TrieNode* root, string key);
bool searchC(TrieNode* root, char ch);
void suggestionsRec(TrieNode* root, string currPrefix);
int printAutoSuggestionsT(TrieNode* root, string query);
void printT(TrieNode* t, string q);



class Trie
{
	TrieNode* root;

public:
	Trie() { root = getNode(); }
	bool insert(string wrd) { return insertT(root, wrd); }
	bool delW(string wrd) { return delT(root, wrd); }
	int printAutoSuggestions(string wrd) { return printAutoSuggestionsT(root, wrd); }
	bool search(string key) { return searchT(root, key); }
	void printTrie() { printT(root, ""); }

};


