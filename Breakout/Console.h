#pragma once
#include <string>

class Console
{
private:
	std::string name;

public:
	Console(std::string name);
	static void writeLine(std::string message);
};

