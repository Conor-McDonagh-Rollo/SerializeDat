#include "SerializeDat.h"

Data& SerializeDat::GetData(int index)
{
    return dataBuffer.at(index);
}

Data& SerializeDat::GetData(std::string node)
{
    for (Data& d : dataBuffer)
    {
        if (d.node == node)
        {
            return d;
        }
    }
    return dataBuffer.at(0);
}

void SerializeDat::LoadToBuffer(const char* path)
{
    std::ifstream file;
    try {
        file.open(path); // open the file
        char currentChar;
        file.unsetf(std::ios_base::skipws);
        file >> currentChar; // begin to parse
        while (!file.eof()) // continue until we hit the EOF
        {
            if (currentChar == ':')
            {
                currentIndex++;
                Data d;
                dataBuffer.push_back(d);
                bool foundNode = false;
                while (!foundNode)
                {
                    file >> currentChar;
                    if (currentChar == ':')
                    {
                        foundNode = true;
                    }
                    else
                    {
                        dataBuffer.at(currentIndex).node.push_back(currentChar);
                    }
                }
            }
            else if (currentChar == '#')
            {
                previousDatChar = currentChar;
            }
            else if (previousDatChar == '#')
            {
                previousDatChar = currentChar;
            }
            else
            {
                if (previousDatChar == 'I')
                {
                    std::string str;
                    bool found = false;
                    while (!found)
                    {
                        str.push_back(currentChar);
                        file >> currentChar;
                        if (currentChar == '#') found = true;
                    }
                    dataBuffer.at(currentIndex).ints.push_back(std::stoi(str));
                    continue;
                }
                else if (previousDatChar == 'S')
                {
                    std::string str;
                    bool found = false;
                    while (!found)
                    {
                        str.push_back(currentChar);
                        file >> currentChar;
                        if (currentChar == '#') found = true;
                    }
                    dataBuffer.at(currentIndex).strings.push_back(str);
                    continue;
                }
                else if (previousDatChar == 'B')
                {
                    bool tf = false;
                    if (currentChar == '1') tf = true;
                    dataBuffer.at(currentIndex).bools.push_back(tf);
                }
            }

            file >> currentChar;
        }
        file.close();
    }
    catch (std::exception& e)
    {
        throw(e);
    }
}
