#include "SerializeDat.h"
#include <iostream>

int main()
{
	SerializeDat data;
	data.LoadToBuffer("test.dat");

	std::cout << data.GetData(0).node << std::endl;
	for (int i : data.GetData(0).ints)
	{
		std::cout << i << std::endl;
	}
	for (std::string s : data.GetData(0).strings)
	{
		std::cout << s << std::endl;
	}
	for (bool b : data.GetData(0).bools)
	{
		std::cout << b << std::endl;
	}
}