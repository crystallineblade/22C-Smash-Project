#pragma once
#include <string>
#include <iostream>

struct Fighter {
public:
	//integer indicating Fighter's roster number
	int rosterNumber;

	//string for the Fighter's name
	std::string name;

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
	}

	/*
	This constructor
	*/
	Fighter(std::string n, std::string ns, std::string ss, std::string us, std::string ds, int num) {
		name = n;
		neutralSpecial = ns;
		sideSpecial = ss;
		upSpecial = us;
		downSpecial = ds;
		rosterNumber = num;
	}


	/*
	This deconstructor deletes the data assigned to the object.
	Post: Fighter object, with it's data, deleted
	*/
	~Fighter() {

	}

	friend bool operator== (const Fighter &f1, const Fighter &f2);
    friend bool operator!= (const Fighter &f1, const Fighter &f2);
	friend bool operator< (const Fighter &f1, const Fighter &f2);
	friend bool operator> (const Fighter &f1, const Fighter &f2);
	friend std::ostream & operator << (std::ostream &out, const Fighter &f);
	friend std::istream & operator >> (std::istream &in, Fighter &f);
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

std::ostream & operator << (std::ostream &out, const Fighter &f) {
	out << f.name << std::endl;
	out << f.neutralSpecial << std::endl;
	out << f.upSpecial << std::endl;
	out << f.sideSpecial << std::endl;
	out << f.downSpecial << std::endl;
	return out;
}

std::istream & operator >> (std::istream &in, Fighter &f) {
	in >> f.name >> f.neutralSpecial >> f.upSpecial >> f.sideSpecial >> f.downSpecial;
	return in;
}