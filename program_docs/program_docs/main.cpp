/*
Team Project #: 5
Team Members: Julia Shuieh, Minchang Cai, Umer Sheikh, Justin Quan
Program Description: This project will be receiving data from the Super Smash Bros. Ultimate Roster.
This data will include characters' names and their four unique special moves. The program will be
able to sort the data being entered, organize trees and lists when data is deleted,
search for specified data, compare two data, and print out data in alphabetical or indented order.
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
		string name, upSpecial, neutralSpecial, downSpecial, sideSpecial, series;
		getline(characterFile, name, ',');
		getline(characterFile, series, ',');
		getline(characterFile, neutralSpecial, ',');
		getline(characterFile, sideSpecial, ',');
		getline(characterFile, upSpecial, ',');
		getline(characterFile, downSpecial);
		Fighter fighter(name, neutralSpecial, sideSpecial, upSpecial, downSpecial, num, series);
		tree.insert(tree.getRoot(), fighter);
		hashMap.Insert(fighter);
		list.insertLast(fighter);
	}
}

void printWithIndent(std::ostream &output, BSTNode<Fighter>* curr, int indent) {
	if (tree.height(curr) == 0) return;
	printWithIndent(output, curr->left, indent + 1);
	curr->data1.printWithIndent(output,indent);
	printWithIndent(output, curr->right, indent + 1);
}


int main()
{
	cout << "What option would you like to pick?" << endl;
	cout << "[1] Add" << endl;
	cout << "[2] Delete" << endl;
	cout << "[3] Search" << endl;
	cout << "[4] Print" << endl;
	cout << "[5] Compare" << endl;
	cout << "[6] End" << endl;

	int choice;
	cin >> choice;
	switch (choice) {
	case 1: {

	}
	case 2: {

	}
	case 3: {

	}
	case 4: {

	}
	case 5: {

	}
	case 6:{
	}
	default: {

	}
	}

	system("pause");
	return 0;
}

