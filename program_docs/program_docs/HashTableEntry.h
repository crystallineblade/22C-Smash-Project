#pragma once
#include "Fighter.h"

struct HashTableEntry {
public:
	Fighter data;
	int key;
	int key;
	HashTableEntry() {
		this->key = 0;
	}
	HashTableEntry(Fighter data, int key) {
		this->data = data;
		this->key = 0;
	}
};