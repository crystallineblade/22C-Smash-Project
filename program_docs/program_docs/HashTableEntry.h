#pragma once
#include "Fighter.h"

struct HashTableEntry {
public:
	Fighter data;
	int key;
	HashTableEntry* next;
	HashTableEntry() {
		this->key = 0;
		next = NULL;
	}
	HashTableEntry(Fighter data, int key) {
		this->data = data;
		this->key = 0;
		next = NULL;
	}
	~HashTableEntry() {
		delete next;
		data.~Fighter();
	}
};