#include <iostream>
#include <string>
#include <map>

class WristScanner 
{
public:
    void scan();

private:
    map<string, uint64_t> checksums;
}
