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
	
	/*
	if (searchT(root, key))
	{
		{// mark it as not a end word - "del it"
			TrieNode* ptr = root;
			
			 //* get to the final char of the word.
			
			for (int i = 0; i < key.length(); i++)
			{
				ptr = ptr->children[CHAR_TO_INDEX(key[i])];
			}
			//If he the last node - delete.
			if (!isLastNode(ptr)) 
			ptr->isWordEnd = false;
			else
			{
				
			}
		}
		return true;
	}
	else
	{
		return false;
	}*/
}



bool delR(TrieNode* prev, TrieNode* son, string key)
{
	if (key.length()==0)
	{
		
	}
	return false;
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

//
//for ( i = 0; i < key.length(); ++i)
//	{
//
//		if (!searchC(ptr, key[i]))
//		{
//			found = false;
//		}
//		if (found == false) {
//			return false;
//		}
//
//	}
//	if (i == key.length())
//	return true;
//}

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
}

int printAutoSuggestionsT(TrieNode* root, string query)
{
	return 0;
}

void printT(TrieNode* t, int level)
{
}
