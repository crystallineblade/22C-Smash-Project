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

   public:
	  int getCollisions();
      HashMapTable();
      int HashFunc(Fighter data);
      void Insert(Fighter data);
      int SearchKey(Fighter data);
	  HashTableEntry deleteNode(Fighter data);
      ~HashMapTable();
	  void printHashTable(std::ostream &output);
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
}
int HashMapTable::SearchKey(Fighter data) {
	int h = HashFunc(data);
	HashTableEntry* node = new HashTableEntry;
	node = &Htable[h];
	while (node != NULL && (*node).data.name != "") {
		if ((*node).data == data) {
			std::cout << "Data found: " << std::endl;
			std::cout << Htable[h].data << std::endl;
			if (node->data != Htable[h].data) {
				HashTableEntry newNode = Htable[h];
				
			}
			return h;
		}
		else {
			node = (*node).next;
		}
	}
	std::cout << "Invalid Data" << std::endl;
	return 0;
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
#endif