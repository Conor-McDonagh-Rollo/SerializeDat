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

void SerializeDat::Load(const char* path)
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
                else if (previousDatChar == 'V')
                {
                    std::string vec[2];
                    bool found = false;
                    bool foundFirst = false;
                    while (!found)
                    {
                        if (!foundFirst)
                        {
                            vec[0].push_back(currentChar);
                            file >> currentChar;
                            if (currentChar == ',') foundFirst = true;
                        }
                        else {
                            vec[1].push_back(currentChar);
                            file >> currentChar;
                            if (currentChar == '#') found = true;
                        }
                    }
                    dataBuffer.at(currentIndex).vector2s.push_back(Vec2(std::stoi(vec[0]), std::stoi(vec[1])));
                    continue;
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

void SerializeDat::Add(Data data)
{
    dataBuffer.push_back(data);
}

void SerializeDat::Save(const char* path)
{
    std::ofstream file(path, std::ofstream::out | std::ofstream::trunc);
    
    for (Data& d : dataBuffer)
    {
        file << ":" << d.node << ":";
        for (int i : d.ints)
        {
            file << "#I" << i;
        }
        for (std::string s : d.strings)
        {
            file << "#S" << s;
        }
        for (bool b : d.bools)
        {
            file << "#B" << b;
        }
        for (Vec2 v : d.vector2s)
        {
            file << "#V" << v.x << "," << v.y;
        }
        file << "#";
    }

    file.close();
}
