#include "SerializeDat.h"
#include <iostream>

int main()
{
	Serialize data;

	data.Load("test.dat");
	
	int test = 1;

	if (test == 1)
	{
		//data.Clear();

		Data newdata;
		newdata.node = "NewDataNode";
		newdata.vector2s.push_back(Vec2(25,25));

		data.Add(newdata);
		data.Save("test.dat");
	}

	return 0;
}