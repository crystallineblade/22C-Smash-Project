/* Originally written by Minchang Cai, altered by Julia Shuieh for the project
   Comments written by Julia Shuieh
*/

#pragma once
#include "Fighter.h"

struct HashTableEntry {
public:

	// Fighter object that contains data for the fighter character
	Fighter data;

	// integer representing the hash key of the node
	int key;

	// pointer to next HashTableEntry for linked list solution for collisions
	HashTableEntry* next;

	/*
	This default constructor sets the hash key to -1 and pointer for the next entry to NULL.
	Post: key is set to 0 and next is NULL
	*/
	HashTableEntry() {
		this->key = 0;
		next = NULL;
	}

	/*
	This constructor initializes the data and the key based on the parameters.
	Pre: data - Fighter object that contains the fighter data
		 key - the hash key of the entry
	Post: HashTableEntry is initialized with the entered data and key
	*/
	HashTableEntry(Fighter data, int key) {
		this->data = data;
		this->key = key;
		next = NULL;
	}

	/*
	This copy constructor initializes the data and key based on the entered HashTable.
	Pre: entry - an initialized HashTableEntry
	Post: HashTableEntry is initialized with the same attributes as the entered HashTableEntry
	*/
	HashTableEntry(const HashTableEntry &entry) {
		key = entry.key;
		data = entry.data;
		next = entry.next;
	}

	/*
	This default deconstructor 
	*/
	~HashTableEntry() {
		delete next;
		data.~Fighter();
	}
};