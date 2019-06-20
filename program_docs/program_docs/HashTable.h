/* Originally written by Minchang Cai, altered by Julia Shuieh for the project
   Comments written by Julia Shuieh
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<string>
#include<iostream>
#include "HashTableEntry.h"

class HashMapTable {
   private:
      HashTableEntry *Htable;
	  int collisions;
	  const int T_S = 100;
	  int count = 0;
	  int currentSize = T_S;
	  const double loadFactor = 0.75;
	  
	  
   public:
	  
	  int getCollisions();
      HashMapTable();
	  void rehash();
      int HashFunc(Fighter data);
      void Insert(Fighter data);
      int SearchKey(Fighter data);
	  HashTableEntry deleteNode(Fighter data);
      ~HashMapTable();
	  void printHashTable(std::ostream &output);
	  int longestList();
	  double averageListLength();
};

HashMapTable::HashMapTable() {
	Htable = new HashTableEntry[T_S];
	collisions = 0;
}

int HashMapTable::HashFunc(Fighter data) {
	/*
	std::string name = "";
	for (int i = 0; i < data.name.size(); i++) {
		name += tolower(data.name.at(i));
	}
	int sum = 0;
	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] >= 'a' && name[i] <= 'z')
		{
			int num = name[i] - 'z';
			sum = sum + num;
		}
	}
	int index = 0;
	while (sum != 0)
	{
		index = index + (sum % 10);
		sum = sum / 10;
	}
	return index;
	*/
	return data.rosterNumber;
}

void HashMapTable::Insert(Fighter data) {
	int h = HashFunc(data);
	if (Htable[h].data.name == "")
	{
		Htable[h].data = data;
		Htable[h].key = h;
	}
	else if (Htable[h].data.name != "")
	{
		collisions++;
		HashTableEntry* node = new HashTableEntry;
		node = &(Htable[h]);
		while (Htable[h].next != NULL)
		{
			node = node->next;
		}
		HashTableEntry newNode(data, h);
		node->next = &newNode;
	}
	count++;
}
int HashMapTable::SearchKey(Fighter data) {
	int h = HashFunc(data);
	HashTableEntry* node = new HashTableEntry;
	node = &(Htable[h]);
	while (node != NULL && (*node).data.name != "") {
		if ((*node).data == data) {
			std::cout << "Data found: " << std::endl;
			std::cout << Htable[h].data << std::endl;
			if (node->data != Htable[h].data) {
				HashTableEntry removedNode = deleteNode(data);
				removedNode.next = &(Htable[h]);
				Htable[h] = removedNode;
			}
			return h;
		}
		else {
			node = (*node).next;
		}
	}
	throw "Invalid data.";
	return 0;
}
void HashMapTable::rehash() {
	if (count >= currentSize * loadFactor) {
		HashTableEntry* arr = new HashTableEntry[currentSize + T_S];
		for (int i = 0; i < currentSize; i++) {
			arr[i] = Htable[i];
		}
		Htable = arr;
		currentSize += T_S;
	}
}
HashTableEntry HashMapTable::deleteNode(Fighter data) {
	int h = HashFunc(data);
	HashTableEntry newNode;
	if (Htable[h].data.name == "") {
		throw "Fighter not in hash table.";
	}
	if (Htable[h].data == data) {
		HashTableEntry removedNode = Htable[h];
		Htable[h] = newNode;
		return removedNode;
	}
	else {
		HashTableEntry *node = &(Htable[h]);
		while (node->next != NULL) {
			if ((node->next)->data == data) {
				HashTableEntry removedNode = *(node->next);
				node->next = (node->next)->next;
				return removedNode;
			}
		}
		throw "Fighter not in hash table.";
	}
	return newNode;
}

HashMapTable::~HashMapTable() {
	Htable = nullptr;
}
int HashMapTable::getCollisions()
{
	return collisions;
}

void HashMapTable::printHashTable(std::ostream &output) {
	for (int i = 0; i < T_S; i++) {
		if (Htable[i].data.name != "") {
			HashTableEntry* node = new HashTableEntry;
			node = &(Htable[i]);
			while (node != NULL) {
				output << "Hash key #" << i << ":" << std::endl;
				output << (*node).data << std::endl;
				node = (*node).next;
			}
		}
	}
}

int HashMapTable::longestList() {
	int longest = 1;
	for (int i = 0; i < currentSize; i++) {
		int current = 1;
		if(Htable[i].data.name != "" && Htable[i].next != NULL) {
			HashTableEntry* node = &Htable[i];
			while (node->next != NULL) {
				current++;
				node = node->next;
			}
			if (current > longest) longest = current;
		}
	}
	return longest;
}

double HashMapTable::averageListLength() {
	double total = 0;
	for (int i = 0; i < currentSize; i++) {
		int current = 1;
		if (Htable[i].data.name != "" && Htable[i].next != NULL) {
			HashTableEntry* node = &Htable[i];
			while (node->next != NULL) {
				current++;
				node = node->next;
			}
		}
		total += current;
	}
	return total / count;
}
#endif