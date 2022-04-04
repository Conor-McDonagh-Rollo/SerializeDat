#include "SerializeDat.h"
#include <iostream>

int main()
{
	SerializeDat data;

	data.LoadToBuffer("test.dat");
	
	bool done = false;
	int it = 0;
	while (!done)
	{
		std::cout << "Type 'done' to quit, else type 'cont'" << std::endl;
		std::string s;
		std::cin >> s;
		if (s == "done" && it == 0)
		{
			done = true;
			continue;
		}
		else if (s == "done")
		{
			done = true;
			data.SaveDataBuffer("test.dat");
			continue;
		}
		else if (s == "cont")
		{

			Data d;
			std::cout << "Node name: ";
			s.clear();
			std::cin >> s;
			d.node = s;

			bool doneAdding = false;
			while (!doneAdding)
			{
				std::cout << "What would you like to add?\n1) int\n2) string\n3) bool\n4) done\n";
				s.clear();
				std::cin >> s;
				if (s == "1")
				{
					int i;
					std::cin >> i;
					d.ints.push_back(i);
				}
				if (s == "2")
				{
					s.clear();
					std::cin >> s;
					d.strings.push_back(s);
				}
				if (s == "3")
				{
					int i;
					std::cin >> i;
					if (i == 1)
					{
						d.bools.push_back(true);
					}
					else if (i == 0)
					{
						d.bools.push_back(false);
					}
				}
				if (s == "4")
				{
					doneAdding = true;
				}
			}

			data.AddToBuffer(d);

			it++;
		}
	}

	for (int i = 0; i < data.Size(); i++)
	{
		Data& d = data.GetData(i);
		std::cout << d.node << std::endl;
		for (int i : d.ints)
		{
			std::cout << i << std::endl;
		}
		for (std::string s : d.strings)
		{
			std::cout << s << std::endl;
		}
		for (bool b : d.bools)
		{
			std::cout << b << std::endl;
		}
		std::cout << "\n\n";
	}
}