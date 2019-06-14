#pragma once
#include <string>

struct Fighter {
private:
	std::string name;
	std::string neutralSpecial;
	std::string sideSpecial;
	std::string upSpecial;
	std::string downSpecial;
public:
	Fighter() {

	}

	Fighter(std::string n, std::string ns, std::string ss, std::string us, std::string ds) {
		name = n;
		neutralSpecial = ns;
		sideSpecial = ss;
		upSpecial = us;
		downSpecial = ds;
	}

	~Fighter() {

	}
};