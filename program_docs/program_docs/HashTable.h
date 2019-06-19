#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<string>
#include<iostream>
#include "HashTableEntry.h"

class HashMapTable {
   private:
      HashTableEntry *Htable;
	  int collisions;
	  const int T_S = 200;

   public:
	  int getCollisions();
      HashMapTable();
      int HashFunc(Fighter data);
      void Insert(Fighter data);
      int SearchKey(Fighter data);
      ~HashMapTable();
};

HashMapTable::HashMapTable() {
	Htable = new HashTableEntry[T_S];
	collisions = 0;
}

int HashMapTable::HashFunc(Fighter data) {
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
}

void HashMapTable::Insert(Fighter data) {
	int h = HashFunc(data);
	int j = 0;
	if (Htable[h].data.name == "")
	{
		Htable[h].data = data;
		Htable[h].key = h;
	}
	else if (Htable[h].data.name != "")
	{
		while (Htable[h].data.name != "" && h < T_S)
		{
			collisions++;
			j++;
			h = (h + j) % T_S;
		}
		if (h < T_S)
		{
			Htable[h].data = data;
			Htable[h].key = h;
		}
	}
}
int HashMapTable::SearchKey(Fighter data) {
	int h = HashFunc(data);
	int j = 0;
	if (Htable[h].data == data)
	{
		std::cout << Htable[h].data << std::endl;
	}
	else
	{
		while (Htable[h].data != data && j < T_S)
		{
			j++;
			h = (h + j) % T_S;
		}
		if (j < T_S&&Htable[h].data == data)
		{
			std::cout << Htable[h].data << std::endl;
		}
		else
		{
			std::cout << "Invalid Data" << std::endl;
		}
	}
	return 0;
}
HashMapTable::~HashMapTable() {
	Htable = nullptr;
}
int HashMapTable::getCollisions()
{
	return collisions;
}
#endif