#include <string>

class Box
{
public:
    Box(std::string &id): id(id);

    std::string &getId() { return id; }
private:
    std::string id;
};
