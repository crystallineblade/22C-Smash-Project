/* Written by Julia Shuieh
*/

#pragma once
#include <string>
#include <iostream>

struct Fighter {
public:
	//integer indicating Fighter's roster number
	int rosterNumber;

	//string for the Fighter's name
	std::string name;

	std::string series;

	//string for the Fighter's neutral special
	std::string neutralSpecial;

	//string for the Fighter's side special
	std::string sideSpecial;

	//string for the Fighter's up special
	std::string upSpecial;

	//string for the Fighter's down special
	std::string downSpecial;

	/*
	This default constructor initializes all the data for the fighters.
	Post: rosterNumber is set to -1 and the string datas are empty.
	*/
	Fighter() {
		rosterNumber = -1;
		name = "";
		neutralSpecial = "";
		sideSpecial = "";
		upSpecial = "";
		downSpecial = "";
		series = "";
	}

	Fighter(std::string n) {
		name = n;
		rosterNumber = -1;
		neutralSpecial = "";
		sideSpecial = "";
		upSpecial = "";
		downSpecial = "";
		series = "";
	}

	/*
	This constructor
	*/
	Fighter(std::string n, std::string ns, std::string ss, std::string us, std::string ds, int num, std::string s) {
		name = n;
		neutralSpecial = ns;
		sideSpecial = ss;
		upSpecial = us;
		downSpecial = ds;
		rosterNumber = num;
		series = s;
	}


	/*
	This deconstructor deletes the data assigned to the object.
	Post: Fighter object, with it's data, deleted
	*/
	~Fighter() {

	}

	/* This overloaded operator compares two Fighter objects.
	Pre: f1 - Fighter object for the first fighter
		 f2 - Fighter object of the second fighter
	Return: true if f1 and f2 are equal
	*/
	friend bool operator== (const Fighter &f1, const Fighter &f2);

	/* This overloaded operator compares two Fighter objects.
	Pre: f1 - Fighter object for the first fighter
		 f2 - Fighter object of the second fighter
	Return: true if f1 and f2 are NOT equal
	*/
    friend bool operator!= (const Fighter &f1, const Fighter &f2);

	/* This overloaded operator compares two Fighter objects.
	Pre: f1 - Fighter object for the first fighter
		 f2 - Fighter object of the second fighter
	Return: true if f1 is less than f2
	*/
	friend bool operator< (const Fighter &f1, const Fighter &f2);

	/* This overloaded operator compares two Fighter objects.
	Pre: f1 - Fighter object for the first fighter
		 f2 - Fighter object of the second fighter
	Return: true if f1 is greater than f2
	*/
	friend bool operator> (const Fighter &f1, const Fighter &f2);

	/* This overloaded output stream operator send data from each node to the output stream.
	Pre: out - ostream that the data is sent to
		 f - Fighter with generic datatype
	Post: out has the data from Fighter f
	Return: ostream object
	*/
	friend std::ostream & operator << (std::ostream &out, const Fighter &f);

	void printWithIndent(std::ostream &output, int numIndent);

};

bool operator==(const Fighter &f1, const Fighter &f2) {
	return f1.name == f2.name;
}

bool operator!=(const Fighter &f1, const Fighter &f2) {
	return f1.name != f2.name;
}

bool operator< (const Fighter &f1, const Fighter &f2) {
	return f1.name < f2.name;
}

bool operator> (const Fighter &f1, const Fighter &f2) {
	return f2.name > f2.name;
}

void Fighter::printWithIndent(std::ostream &output, int numIndent) {

	for (int i = 0; i < numIndent; i++) {
		output << "\t";
	}
	output << "#" << rosterNumber << " - " << name << std::endl;
}

std::ostream & operator << (std::ostream &out, const Fighter &f) {
	out << "#" << f.rosterNumber << " - " << f.name << " - " << f.series << std::endl;
	out << f.neutralSpecial << std::endl;
	out << f.upSpecial << std::endl;
	out << f.sideSpecial << std::endl;
	out << f.downSpecial << std::endl;
	return out;
}
