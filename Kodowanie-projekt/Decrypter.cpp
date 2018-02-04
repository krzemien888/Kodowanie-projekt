#include "stdafx.h"
#include "Decrypter.h"


void Decrypter::initMorseMap()
{
	morseMap['.'] = ' ';
	morseMap['-'] = '\t';
	morseMap[' '] = '\n';

	std::map<char, std::string> reversedMap;

	reversedMap['A'] = applyMorseMutation(".-");
	reversedMap['B'] = applyMorseMutation("-...");
	reversedMap['C'] = applyMorseMutation("-.-.");
	reversedMap['D'] = applyMorseMutation("-..");
	reversedMap['E'] = applyMorseMutation(".");
	reversedMap['F'] = applyMorseMutation("..-.");
	reversedMap['G'] = applyMorseMutation("--.");
	reversedMap['H'] = applyMorseMutation("....");
	reversedMap['I'] = applyMorseMutation("..");
	reversedMap['J'] = applyMorseMutation(".---");
	reversedMap['K'] = applyMorseMutation("-.-");
	reversedMap['L'] = applyMorseMutation(".-..");
	reversedMap['M'] = applyMorseMutation("--");
	reversedMap['N'] = applyMorseMutation("-.");
	reversedMap['O'] = applyMorseMutation("---");
	reversedMap['P'] = applyMorseMutation(".--.");
	reversedMap['Q'] = applyMorseMutation("--.-");
	reversedMap['R'] = applyMorseMutation(".-.");
	reversedMap['S'] = applyMorseMutation("...");
	reversedMap['T'] = applyMorseMutation("-");
	reversedMap['U'] = applyMorseMutation("..-");
	reversedMap['W'] = applyMorseMutation(".--");
	reversedMap['V'] = applyMorseMutation("...-");
	reversedMap['Y'] = applyMorseMutation("-.--");
	reversedMap['Z'] = applyMorseMutation("--..");
	reversedMap['X'] = applyMorseMutation("-..-");
	reversedMap['0'] = applyMorseMutation(".----");
	reversedMap['1'] = applyMorseMutation("..---");
	reversedMap['2'] = applyMorseMutation("...--");
	reversedMap['3'] = applyMorseMutation("....-");
	reversedMap['4'] = applyMorseMutation(".....");
	reversedMap['5'] = applyMorseMutation("-....");
	reversedMap['6'] = applyMorseMutation("--...");
	reversedMap['7'] = applyMorseMutation("---..");
	reversedMap['8'] = applyMorseMutation("----.");
	reversedMap['9'] = applyMorseMutation("-----");
	reversedMap[' '] = applyMorseMutation(" ");


	for (std::map<char, std::string>::iterator i = reversedMap.begin(); i != reversedMap.end(); ++i)
		morseCode[i->second] = i->first;
}

std::string Decrypter::applyMorseMutation(std::string morse)
{
	std::string output = "";
	for (char sign : morse)
		output += morseMap[sign];

	return output;
}


Decrypter::Decrypter()
{
	initMorseMap();
}

void Decrypter::setKey(int key)
{
	seed = key;
}

void Decrypter::loadFile(std::string filename)
{
	std::ifstream file(filename);
	std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

	fileData = str;
}

void Decrypter::decryptCesar()
{
	std::string output = "";
	for (char sign : decrypted)
	{
		int basePosition = std::find(cesarVector.begin(), cesarVector.end(), std::toupper(sign)) - cesarVector.begin();
		int newPosition = basePosition - seed;
		if (newPosition < 0)
			newPosition = cesarVector.size() + newPosition;

		output += cesarVector[newPosition];
	}
	decrypted = output;
}

void Decrypter::saveToFile(std::string filename)
{
	std::ofstream of(filename, std::ofstream::trunc);
	of << decrypted;
	of.close();
}

void Decrypter::decryptMorse()
{
	std::string output = "";
	std::string morseCharacter = "";
	for (char sign : fileData)
	{
		if (sign == char(0))
		{
			output += morseCode[morseCharacter];
			morseCharacter = "";
		}
		else
		{
			morseCharacter += sign;
		}
	}

	decrypted = output;
}
