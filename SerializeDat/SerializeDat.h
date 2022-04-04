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
	int Size() { return dataBuffer.size(); }
	Data& GetData(int index); // Returns an element from the data buffer
	Data& GetData(std::string node); // Returns an element from the data buffer by searching
	void LoadToBuffer(const char* path); // Fills the dataBuffer with the file's contents

	void ClearBuffer() { dataBuffer.clear(); } // Clear the buffer of all it's elements
	void AddToBuffer(Data data); // Add data to the back of the buffer
	void SaveDataBuffer(const char* path); // Save the data to a file

private:
	int lastType = 0;
	int currentIndex = -1;
	char previousDatChar = '0';

	std::vector<Data> dataBuffer;
};

