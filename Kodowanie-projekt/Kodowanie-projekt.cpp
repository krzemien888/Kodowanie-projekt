// Kodowanie-projekt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Helper.h"
#include "Decrypter.h"
#include "Encrypter.h"
#include "Kodowanie-projekt.h"


using namespace std;
int main(int argc, char** argv)
{
	srand((unsigned int)time(NULL));

	if (argc < 3)
	{
		cout << "Program wymaga conajmniej 2 argumentow" << endl; 
	}
	else if (string(argv[1]) == ("help"))
	{
		Helper::printHelp(string(argv[2]));
	}
	else if (string(argv[1]) == ("decrypt"))
	{
		if (argc < 5)
		{
			cout << "Brak klucza" << endl;
			for (int i = 0; i < argc; i++)
				cout << string(argv[i]) << endl;
		}
		else {
			auto decrypter = Decrypter();
			decrypter.loadFile(string(argv[2]));
			decrypter.setKey(stoi(argv[3]));
			decrypter.decryptMorse();
			decrypter.decryptCesar();
			decrypter.saveToFile(string(argv[4]));
		}
	}
	else if (string(argv[1]) == ("encrypt"))
	{
		if (argc < 4)
			cout << "Niewystarczajaca liczba argumentow. Uzyj polecenia help encrypt" << endl;
		else {
			auto encrypeter = Encrypter();

			encrypeter.loadFile(string(argv[2]));
			encrypeter.applyCesarCipher();
			encrypeter.applyMorseCipher();
			encrypeter.saveToFile(string(argv[3]));
			cout << "Encryption key:" << encrypeter.getKey() << endl;
		}
	}

	system("pause");

    return 0;
}

