/*
Team Project #: 5
Team Members: Julia Shuieh, Minchang Cai, Umer Sheikh, Justin Quan
Program Description:
*/

#include "BST.h"
#include "HashTable.h"
#include "LinkedList.h"
#include "Fighter.h"
#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int characterCount = 0;
BST<Fighter> tree;
HashMapTable hashMap;
LinkedList<Fighter> list;

void importDataFromFile(string fileName) {
	ifstream characterFile(fileName);
	if (!characterFile.is_open()) {
		cout << "Invalid file. Please try again." << endl;
		return;
	}
	string line;
	int num = 0;
	while (characterFile >> num) {
		string name, upSpecial, neutralSpecial, downSpecial, sideSpecial;
		getline(characterFile, name, ',');
		getline(characterFile, neutralSpecial, ',');
		getline(characterFile, sideSpecial, ',');
		getline(characterFile, upSpecial, ',');
		getline(characterFile, downSpecial, ',');
		Fighter fighter(name, neutralSpecial, sideSpecial, upSpecial, downSpecial, num);
		tree.insert(tree.getRoot(), fighter);
		hashMap.Insert(fighter);
		list.insertLast(fighter);
	}
}

int main()
{
	cout << "Please give us an A Manish Goel. Justin really needs it.";
	cout << "What option would you like to pick?";

	system("pause");
	return 0;
}