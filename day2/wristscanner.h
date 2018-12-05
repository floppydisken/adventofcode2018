#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "box.h"

class WristScanner 
{
private:
    std::vector<Box *> boxes;
    int64_t mTwoCounts;
    int64_t mThreeCounts;
    int64_t mChecksum;

public:
    WristScanner(): mTwoCounts(0), mThreeCounts(0), mChecksum(0) {};
    int64_t checksum();
    std::string findPrototypeBoxes();
    int64_t getTwoCounts() { return mTwoCounts; }
    int64_t getThreeCounts() { return mThreeCounts; }
    void scan(Box *box);
    void print();
};
