// This class acts as a way for objects to display information on the debug console

#include "Console.h"
#include <iostream>

using namespace std;

Console::Console(std::string name)
{
	//this->name = name;
}

// Writes a line in the console
void Console::writeLine(std::string line)
{
	cout << line << endl;
}
