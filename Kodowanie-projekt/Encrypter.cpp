#include "stdafx.h"
#include "Encrypter.h"

void Encrypter::initMorseMap()
{
	morseMap['.'] = ' ';
	morseMap['-'] = '\t';
	morseMap[' '] = '\n';

	morseCode['A'] = applyMorseMutation(".-");
	morseCode['B'] = applyMorseMutation("-...");
	morseCode['C'] = applyMorseMutation("-.-.");
	morseCode['D'] = applyMorseMutation("-..");
	morseCode['E'] = applyMorseMutation(".");
	morseCode['F'] = applyMorseMutation("..-.");
	morseCode['G'] = applyMorseMutation("--.");
	morseCode['H'] = applyMorseMutation("....");
	morseCode['I'] = applyMorseMutation("..");
	morseCode['J'] = applyMorseMutation(".---");
	morseCode['K'] = applyMorseMutation("-.-");
	morseCode['L'] = applyMorseMutation(".-..");
	morseCode['M'] = applyMorseMutation("--");
	morseCode['N'] = applyMorseMutation("-.");
	morseCode['O'] = applyMorseMutation("---");
	morseCode['P'] = applyMorseMutation(".--.");
	morseCode['Q'] = applyMorseMutation("--.-");
	morseCode['R'] = applyMorseMutation(".-.");
	morseCode['S'] = applyMorseMutation("...");
	morseCode['T'] = applyMorseMutation("-");
	morseCode['U'] = applyMorseMutation("..-");
	morseCode['W'] = applyMorseMutation(".--");
	morseCode['V'] = applyMorseMutation("...-");
	morseCode['Y'] = applyMorseMutation("-.--");
	morseCode['Z'] = applyMorseMutation("--..");
	morseCode['X'] = applyMorseMutation("-..-");
	morseCode['0'] = applyMorseMutation(".----");
	morseCode['1'] = applyMorseMutation("..---");
	morseCode['2'] = applyMorseMutation("...--");
	morseCode['3'] = applyMorseMutation("....-");
	morseCode['4'] = applyMorseMutation(".....");
	morseCode['5'] = applyMorseMutation("-....");
	morseCode['6'] = applyMorseMutation("--...");
	morseCode['7'] = applyMorseMutation("---..");
	morseCode['8'] = applyMorseMutation("----.");
	morseCode['9'] = applyMorseMutation("-----");
	morseCode[' '] = applyMorseMutation(" ");
}

std::string Encrypter::applyMorseMutation(std::string morse)
{
	std::string output = "";
	for (char sign : morse)
		output += morseMap[sign];

	return output;
}

Encrypter::Encrypter()
{
	initMorseMap();
}

void Encrypter::loadFile(std::string filename)
{
	std::fstream file;
	std::stringstream ss;

	file.open(filename);

	if (!file.is_open())
	{
		std::cout << "Nie udalo sie otworzyc pliku" << std::endl;
		return;
	}

	std::string tmp;
	getline(file, fileData, '!');
	generateSeed();
}

void Encrypter::generateSeed()
{
	seed = 4;// (rand() % cesarVector.size()) + 1;
}

void Encrypter::applyCesarCipher()
{
	for (char sign : fileData)
	{
		int basePosition = std::find(cesarVector.begin(), cesarVector.end(), std::toupper(sign)) - cesarVector.begin();
		int newPosition = (basePosition + seed) % cesarVector.size();

		encrypted += cesarVector[newPosition];
	}
}

void Encrypter::applyMorseCipher()
{
	std::string output = "";

	for (char sign : encrypted)
	{
		output += morseCode[sign];
		output += char(0);
	}

	encrypted = output;
}

void Encrypter::saveToFile(std::string filename)
{
	std::ofstream of(filename, std::ofstream::trunc);
	of << encrypted;
	of.close();
}

int Encrypter::getKey()
{
	return seed;
}
