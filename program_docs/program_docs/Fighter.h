#pragma once
#include <string>
#include <iostream>

struct Fighter {
public:
	int rosterNumber;
	std::string name;
	std::string neutralSpecial;
	std::string sideSpecial;
	std::string upSpecial;
	std::string downSpecial;

	Fighter() {
		rosterNumber = -1;
		name = "";
		neutralSpecial = "";
		sideSpecial = "";
		upSpecial = "";
		downSpecial = "";
	}

	Fighter(std::string n, std::string ns, std::string ss, std::string us, std::string ds, int num) {
		name = n;
		neutralSpecial = ns;
		sideSpecial = ss;
		upSpecial = us;
		downSpecial = ds;
		rosterNumber = num;
	}

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