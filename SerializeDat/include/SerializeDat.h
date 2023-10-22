#ifndef SERIALIZE_DAT_H
#define SERIALIZE_DAT_H

#include <vector>
#include <string>
#include <fstream>
#include <ios>
#include <iostream>

struct Vec2 {
    int x = 0;
    int y = 0;

    Vec2() = default;
    Vec2(int _x, int _y) : x(_x), y(_y) {}

    std::string serialize() const {
        return std::to_string(x) + "," + std::to_string(y);
    }

    static Vec2 deserialize(const std::string& data) {
        size_t pos = data.find(',');
        if (pos == std::string::npos) {
            throw std::runtime_error("Invalid Vec2 format");
        }
        int _x = std::stoi(data.substr(0, pos));
        int _y = std::stoi(data.substr(pos + 1));
        return Vec2(_x, _y);
    }
};

struct Data {
    std::string node;
    std::vector<int> ints;
    std::vector<std::string> strings;
    std::vector<bool> bools;
    std::vector<Vec2> vector2s;

    void serializeTo(std::ostream& os) const {
        os << ":" << node << ":";
        for (const auto& i : ints) os << "#I" << i;
        for (const auto& s : strings) os << "#S" << s;
        for (const auto& b : bools) os << "#B" << b;
        for (const auto& v : vector2s) os << "#V" << v.serialize();
        os << "#";
    }

};

typedef class SerializeDat {
public:
    int Size() const { return dataBuffer.size(); }
    const Data& GetData(std::size_t index) const; 
    const Data& GetData(const std::string& node) const; 

    void Clear() { dataBuffer.clear(); }
    void Add(const Data& data); 
    void Load(const char* path);
    void Save(const char* path) const;

private:
	std::string parseNode(std::ifstream& file);
	int parseInteger(std::ifstream& file);
	std::string parseString(std::ifstream& file);
	bool parseBool(std::ifstream& file);
	Vec2 parseVec2(std::ifstream& file);

    std::vector<Data> dataBuffer;
} Serialize;

const Data& SerializeDat::GetData(std::size_t index) const {
    if(index < dataBuffer.size()) {
        return dataBuffer.at(index);
    }
    throw std::runtime_error("Index out of bounds");
}

const Data& SerializeDat::GetData(const std::string& node) const {
    for (const auto& d : dataBuffer) {
        if (d.node == node) {
            return d;
        }
    }
    throw std::runtime_error("Node not found");
}

void SerializeDat::Add(const Data& data) {
    dataBuffer.push_back(data);
}

void SerializeDat::Load(const char* path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open the file");
    }
    
    char currentChar;
    file.unsetf(std::ios_base::skipws);
    
    while (file >> currentChar) {
        if (currentChar == ':') {
            Data d;
            d.node = parseNode(file);
            dataBuffer.push_back(d);
        } else if (currentChar == '#') {
            if (!(file >> currentChar)) {
                break;
            }
            
            switch (currentChar) {
                case 'I':
                    dataBuffer.back().ints.push_back(parseInteger(file));
                    break;
                case 'S':
                    dataBuffer.back().strings.push_back(parseString(file));
                    break;
                case 'B':
                    dataBuffer.back().bools.push_back(parseBool(file));
                    break;
                case 'V':
                    dataBuffer.back().vector2s.push_back(parseVec2(file));
                    break;
                default:
                    throw std::runtime_error("Unknown data type encountered");
            }
        }
    }

    file.close();
}

std::string SerializeDat::parseNode(std::ifstream& file) {
    char ch;
    std::string node;
    while (file >> ch && ch != ':') {
        node.push_back(ch);
    }
    return node;
}

int SerializeDat::parseInteger(std::ifstream& file) {
    std::string value;
    char ch;
    while (file >> ch && ch != '#') {
        value.push_back(ch);
    }
    return std::stoi(value);
}

std::string SerializeDat::parseString(std::ifstream& file) {
    std::string value;
    char ch;
    while (file >> ch && ch != '#') {
        value.push_back(ch);
    }
    return value;
}

bool SerializeDat::parseBool(std::ifstream& file) {
    char ch;
    if (!(file >> ch)) {
        throw std::runtime_error("Failed to read bool value");
    }
    return ch == '1';
}

Vec2 SerializeDat::parseVec2(std::ifstream& file) {
    return Vec2::deserialize(parseString(file));
}

void SerializeDat::Save(const char* path) const {
    std::ofstream file(path, std::ofstream::out | std::ofstream::trunc);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open the file");
    }
    for (const auto& d : dataBuffer) {
        d.serializeTo(file);
    }
    file.close();
}

#endif