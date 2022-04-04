#pragma once
#include <vector>
#include <string>
#include <fstream>

struct Data {
	std::string node;
	std::vector<int> ints;
	std::vector<std::string> strings;
	std::vector<bool> bools;
};

class SerializeDat
{
public:
	Data GetData(int index); // Returns a copy from the data buffer
	void LoadToBuffer(const char* path); // Fills the dataBuffer with the file's contents

	std::vector<Data> dataBuffer;
private:
	int lastType = 0;
	int currentIndex = -1;
	char previousDatChar = '0';
};

