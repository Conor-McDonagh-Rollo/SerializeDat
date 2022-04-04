#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <ios>

struct Data {
	std::string node;
	std::vector<int> ints;
	std::vector<std::string> strings;
	std::vector<bool> bools;
};

class SerializeDat
{
public:
	Data& GetData(int index); // Returns an element from the data buffer
	Data& GetData(std::string node); // Returns an element from the data buffer by searching
	void LoadToBuffer(const char* path); // Fills the dataBuffer with the file's contents

private:
	int lastType = 0;
	int currentIndex = -1;
	char previousDatChar = '0';

	std::vector<Data> dataBuffer;
};

