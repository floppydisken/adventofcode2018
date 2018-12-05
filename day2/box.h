#pragma once
#include <string>

class Box
{
private:
    std::string id;
public:
    Box(std::string id): id(id) {};

    std::string &getId() { return id; }
};
