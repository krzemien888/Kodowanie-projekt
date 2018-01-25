#pragma once
class Decrypter
{
	int seed;
	std::vector<char> cesarVector = { ' ', '0', '1', '2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','W','V','X','Y','Z' };
	std::string fileData = "";
	std::string decrypted = "";
	std::map<std::string, char> morseCode;
	std::map<char, char> morseMap;

	void initMorseMap();
	std::string applyMorseMutation(std::string morse);
public:
	Decrypter();
	~Decrypter() = default;


	void setKey(int key);
	void loadFile(std::string filename);
	void decryptCesar();
	void saveToFile(std::string filename);
	void decryptMorse();
};

