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
	  // array that contains HashTableEntry objects
      HashTableEntry *Htable;
	  
	  // integer representing the total number of collisions
	  int collisions;

	  // constant integer representing the increasing size of the array
	  const int T_S = 100;

	  // integer representing the number of HashTableEntry objects
	  int count = 0;

	  // integer representing the current size of the array
	  int currentSize = T_S;

	  // double representing the load factor of the hash table
	  const double loadFactor = 0.75;
	  
	  
   public:
	   /*
	   This default constructor allocates memory for the array.
	   Post: HashMapTable is initialized
	   */
	   HashMapTable();

	  /*
	  This function returns the number of collisions in the hash table.
	  Return: integer
	  */
	  int getCollisions();

	  /* 
	  This function re-allocates more memory for the hash table.
	  Pre: the number of HashTableEntry objects are greater than the load factor (0.75*currentSize)
	  Post: memory is re-allocated more memory
	  */
	  void rehash();

	  /*
	  This function returns the hash key based on the data entered (based on roster number for Fighter).
	  Pre: the Fighter data is initialized correctly and has a valid roster number (greater than 0).
	  Return: an integer representing the hash key for the data
	  */
      int HashFunc(Fighter data);

	  /*
	  This function inserts the data into the hash table.
	  Pre: the Fighter data is initialized correctly and has a valid roster number (greater than 0).
	  Post: the data is added into the hash table
	  */
      void Insert(Fighter data);

	  /*
	  This function searches the hash table for the data.
	  Pre: the Fighter data is initialized correctly and has a valid roster number (greater than 0).
	  Return: integer representing the hash key of the data. 
	  */
      int SearchKey(Fighter data);

	  /*
	  This function deletes the data from the hash table.
	  Pre: the Fighter data is initialized correctly and has a valid roster number (greater than 0).
	  Post: the data is removed from the hash table
	  Return: the HashTableEntry object that contains the fighter data
	  */
	  HashTableEntry deleteNode(Fighter data);

	  /*
	  This default deconstructor deconstructs the HashMapTable object.
	  Post: the hash table is deconstructed
	  */
      ~HashMapTable();

	  /*
	  This function prints out each data from each HashTableEntry with its hash key.
	  Pre: output - an ostream object where the data is sent to
	  Post: the data is sent into the output stream
	  */
	  void printHashTable(std::ostream &output);

	  /*
	  This function calculates the longest linked list (from collisions) in the hash table.
	  Return: integer representing the length of the longest list
	  */
	  int longestList();

	  /*
	  This function calculates the averaged length of linked list (from collisions) in the hash table.
	  Return: double representing the average length of lists
	  */
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
	if (data.rosterNumber < 0 || data.rosterNumber >= currentSize) throw "Hash key is invalid.";
	return data.rosterNumber;
}

/*
Pseudocode:
Get hash key
if (no entry at key already) add data in the array at index key
else if (there is already an entry ie. collision)
	increment collisions variable
	create a pointer for HashTableEntry
	go through linked list until reaches NULL pointer
	insert new HashTableEntry
end if
increment count varible
*/
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
	rehash();
}

/*
Pseudocode:
Get hash key for data
Create pointer for HashTableEntry
loop(through linked list at key)
	if (data matches) print the data
	Move data to the front of the linked list
	return key
end loop
throw exception (if data is not found)
*/
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

/*
Pseudocode:
if (count is greater than loadFactor * currentSize)
	re-allocate more memory for the array
	loop (through the original array)
		copy the HashTableEntry data
	end loop
	set array to the new array
	adjust currentSize
end if 
*/
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

/*
Pseudocode: 
Get hash key
if (no entry at key) throw exception
if (first entry at key is data)
	remove entry from hash table
	return the removed entry
else
	loop (through collision linked list)
		if (entry data matches data) remove and return entry
	end loop
	throw exception (fighter is not in table)
end if
*/
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

/*
Pseudocode:
loop (through array)
	if (entry at key)
		loop (through collision linked list)
			print each entry data
		end loop
	end if
end loop
*/
void HashMapTable::printHashTable(std::ostream &output) {
	for (int i = 0; i < currentSize; i++) {
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

/*
Pseudocode:
set variable for longest length
loop (through array)
	if (there is collision linked list)
		increment length for each entry with loop
	end if
	if (length is greater than longest length) change longest length
end loop
*/
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

/*
Psuedocode:
set variable for total
loop (through array)
	loop (through collision linked list)
		increment length by one for each entry
	end loop
	add length to total
return total / count;
*/
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