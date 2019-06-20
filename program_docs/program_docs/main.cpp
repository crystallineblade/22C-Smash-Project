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
LinkedList<LinkedList<Fighter>> list;

bool importDataFromFile(string fileName) {
	ifstream characterFile(fileName);
	if (!characterFile.is_open()) {
		cout << "Invalid file. Please try again." << endl;
		return false;
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
		
		bool foundSeries = false;
		for (int i = 1; i <= list.getCount(); i++) {
			if ((list.getData(i)).getListName() == series) {
				list.getData(i).insertLast(fighter);
			}
		}
		if (!foundSeries) {
			LinkedList<Fighter> newList(series);
			newList.insertFirst(fighter);
			list.insertFirst(newList);
		}
		characterCount++;
	}
	return true;
}

void printWithIndent(std::ostream &output, BSTNode<Fighter>* curr, int indent) {
	if (tree.height(curr) == 0) return;
	printWithIndent(output, curr->left, indent + 1);
	curr->data1.printWithIndent(output,indent);
	printWithIndent(output, curr->right, indent + 1);
}

void printMenu()
{
	cout << endl << "Print Menu" << endl << "====================" << endl;
	cout << "[1] Alphabetical" << endl;
	cout << "[2] Indented" << endl;
	cout << "[3] Key" << endl;

	int choice;
	cin >> choice;
	switch (choice) {
	case 1:
		cout;
		break;
	case 2:
		printWithIndent(cout, tree.getRoot(), 0);
		break;
	case 3:
		break;

	default:
		break;
	}
}

void addCharacter()
{
	string name, nSpecial, sSpecial, uSpecial, dSpecial, series;
	int rosterNum;

	cout << "Character name: ";
	cin >> name;
	cout << "Character neutral special: ";
	cin >> nSpecial;
	cout << "Character side special: ";
	cin >> sSpecial;
	cout << "Character up special: ";
	cin >> uSpecial;
	cout << "Character down special: ";
	cin >> dSpecial;
	cout << "Character roster number: ";
	cin >> rosterNum;
	cout << "Character series: ";
	cin >> series;

	Fighter newFighter(name, nSpecial, sSpecial, uSpecial, dSpecial, rosterNum, series);
	tree.insert(tree.getRoot(), newFighter);
	hashMap.Insert(newFighter);
	bool foundSeries = false;
	for (int i = 1; i <= list.getCount(); i++) {
		if ((list.getData(i)).getListName() == series) {
			list.getData(i).insertLast(newFighter);
		}
	}
	if (!foundSeries) {
		LinkedList<Fighter> newList(series);
		newList.insertFirst(newFighter);
		list.insertFirst(newList);
	}
	characterCount++;
}

/*
CHANGE THIS BITCH
*/
void deleteCharacter()
{
	string charName;
	string tString = "temp";
	int tInt = 0;

	cout << "What character would you like to delete? (Enter in character name): ";
	cin >> charName;
	Fighter temp(charName, tString, tString, tString, tString, tInt, tString);

	Fighter f = tree.remove(tree.getRoot(), temp)->data1;
	hashMap.deleteNode(temp);
	for (int i = 1; i <= list.getCount(); i++) {
		if (list.getData(i).getListName() == f.series) {
			int index = list.getData(i).search(f);
			list.getData(i).remove(index);
			if (list.getData(i).getCount() == 0) {
				list.remove(i);
				break;
			}
		}
	}
}

int main()
{
	string filename, choiceThree, charName;;
	int rNumber;
	bool isRunning = true;
	bool fileWorks = false;

	while (!fileWorks)
	{
		cout << "What file would you like to read from? ";
		cin >> filename;

		if (importDataFromFile(filename))
		{
			fileWorks = true;
		}
	}

	while (isRunning)
	{
		cout << "What option would you like to pick?" << endl;
		cout << "[1] Add" << endl;
		cout << "[2] Delete" << endl;
		cout << "[3] Search" << endl;
		cout << "[4] Print" << endl;
		cout << "[5] End" << endl;

		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			addCharacter();
			break;
		case 2:
			deleteCharacter();
			break;

		/*
		I NEED HELP BABEEEEEEE LOVE YOU BTW
		*/
		case 3:
			cout << "What is the name of the character you would like to search for? ";
			cin >> charName;
			cout << "What is the roster number of the character you would like to search for? ";
			cin >> rNumber;
			
			break;
		case 4:
			printMenu();
			break;
		case 5:
			isRunning = false;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}

