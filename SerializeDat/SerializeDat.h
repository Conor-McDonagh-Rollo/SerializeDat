#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <ios>

struct Vec2
{
	Vec2(int _x, int _y)
	{
		x = _x; y = _y;
	}
	int x = 0;
	int y = 0;
};

struct Data {
	std::string node;
	std::vector<int> ints;
	std::vector<std::string> strings;
	std::vector<bool> bools;
	std::vector<Vec2> vector2s;
};

class SerializeDat
{
public:
	int Size() { return dataBuffer.size(); }
	Data& GetData(int index); // Returns an element from the data buffer
	Data& GetData(std::string node); // Returns an element from the data buffer by searching
	void Load(const char* path); // Fills the dataBuffer with the file's contents

	void Clear() { dataBuffer.clear(); } // Clear the buffer of all it's elements
	void Add(Data data); // Add data to the back of the buffer
	void Save(const char* path); // Save the data to a file

private:
	int lastType = 0;
	int currentIndex = -1;
	char previousDatChar = '0';

	std::vector<Data> dataBuffer;
};

