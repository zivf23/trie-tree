#include "trie.h"

TrieNode* getNode()
{
	return new TrieNode();
}


bool isLastNode(TrieNode* node)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (node->children[i] != nullptr)
		{
			return false;
		}
	}
	return true;
}

bool insertT(TrieNode* root, string key)
{
	if (searchT(root,key))
	{
		return false;
	}
	if (key.empty())
		return false;
	TrieNode* ptr = root;
	for (int i = 0; i < key.length(); i++)
	{
		if (searchC(ptr, key[i]))//if one char is found in the node
			{
			ptr = ptr->children[CHAR_TO_INDEX(key[i])];
			}
		else
		{
			ptr->children[CHAR_TO_INDEX(key[i])] = getNode();
			ptr = ptr->children[CHAR_TO_INDEX(key[i])];
		}
	}
	ptr->isWordEnd = true; //This is the final charter of the word
		return true;
}



bool delT(TrieNode* root, string key)

{
	if (!searchT(root, key))
		return false;
{
		delR(root, root->children[CHAR_TO_INDEX(key.front())], key.substr(1));
}
}



bool delR(TrieNode* prev, TrieNode* son, string key)
{
	int index = CHAR_TO_INDEX(key[0]);
	if (son->children[index] != nullptr && key.length() > 1) //going down in the tree
		delR(son, son->children[index], key.substr(1));

	if (key.length() <= 1) // working on the last node
	{
		
			son->children[index]->isWordEnd = false;
	}

	if(isLastNode(son->children[index]) && !son->children[index]->isWordEnd)
		{
			prev->children[index] = nullptr;
			delete prev->children[index];
		}

	return true;
}

bool searchT(TrieNode* root, string key)
{
	bool found = true;
	TrieNode* ptr = root;
	int i;

	while (key.length() != 0)
	{
		if (ptr->children[CHAR_TO_INDEX(key.front())] != nullptr)
		{
			ptr = ptr->children[CHAR_TO_INDEX(key.front())];
			key = key.substr(1);
		}
		else
			return false;
	}
	return ptr->isWordEnd;
}


bool searchC(TrieNode* root, char ch)
{
	//if the character is in the node
	if (root->children[CHAR_TO_INDEX(ch)] != nullptr)
		return true;
	else
		return false;
}

void suggestionsRec(TrieNode* root, string currPrefix)
{
	
}

int printAutoSuggestionsT(TrieNode* root, string currPrefix)
{
	if (searchT(root, currPrefix))
	{

		TrieNode* ptr = root;
		TrieNode* ptr2 = root;
		for (int i = 0; i < currPrefix.length(); i++)
		{
			ptr = ptr->children[CHAR_TO_INDEX(currPrefix[i])];
		}
		while (!isLastNode(ptr))
		{
			cout << currPrefix;
			ptr2 = ptr;
			for (int i = 0; i < ALPHABET_SIZE; i++)
			{
				if (ptr2->children[i] != nullptr)
				{
					cout << ptr2->children[i];// print the next char found
					ptr2 = ptr2->children[i];
					if (ptr2->isWordEnd == true)
					{
						cout << endl;
						if (!isLastNode(ptr2)) {
							cout << currPrefix;
							i = 0;
						}
						else
						{
							ptr2 = ptr;
						}
					}
				}
			}
		}
		return 1;
	}
	else
	{
		return 0; 
	}
}

void printT(TrieNode* node, string prefix)
{
	if (searchT(node, prefix)) {
		if (node->isWordEnd) {
			cout << prefix << endl;
		}
		for (int i = 0; i < ALPHABET_SIZE; i++) {
			if (node->children[i] != nullptr) {
				printT(node->children[i], prefix + (char)('a' + i));
			}
		}
	}
}
