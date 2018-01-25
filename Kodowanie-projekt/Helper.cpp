#include "stdafx.h"
#include "Helper.h"

void Helper::printHelp(std::string command)
{
		using namespace std;
		if (command.empty())
		{
			cout << "Here is your help" << endl;
			return;
		}
		else if (command.compare("decrypt"))
		{
			cout << "Here is decrypt help" << endl;
		}
		else if (command.compare("encrypt"))
		{
			cout << "Here is encrypt help" << endl;
		}
		else
		{
			cout << "unknown command. Try: " << endl;
			cout << "help encrypt" << endl;
			cout << "help decrypt" << endl;
		}
}
