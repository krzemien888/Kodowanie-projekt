#pragma once
class Encrypter
{
private:
	std::string fileData = "";
	std::string encrypted = "";

	std::vector<char> cesarVector = { ' ', '0', '1', '2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','W','V','X','Y','Z' };
	std::map<char, std::string> morseCode;
	std::map<char, char> morseMap;
	unsigned int seed = 0; 


	void initMorseMap();
	std::string applyMorseMutation(std::string morse);
public:
	Encrypter();
	~Encrypter() = default;

	void loadFile(std::string filename);

	void generateSeed();
	void applyCesarCipher();
	void applyMorseCipher();
	void saveToFile(std::string filename);
	int getKey();
};

