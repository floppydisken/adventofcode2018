#include "wristscanner.h"


void WristScanner::scan(Box *box)
{
    std::cout << "------- STARTED -------" << '\n';
    std::map<char, int> alphabetCount;
    bool two = false;
    bool three = false;

    boxes.push_back(box);

    for (char c : box->getId())
    {

        alphabetCount[c] += 1;
        std::cout << c << " = " << alphabetCount[c] << '\n';
    }

    for (auto &p : alphabetCount)
    {
        if (p.second == 2)
        {
            two = true;
            std::cout << p.first << " = " << p.second << '\n';
        }

        if (p.second == 3)
        {
            three = true;
            std::cout << p.first << " = " << p.second << '\n';
        }
    }

    if (two)
    {
        std::cout << "Adding to two counts" << '\n';
        ++mTwoCounts;
    }
    if (three)
    {
        std::cout << "Adding to three counts" << '\n';
        ++mThreeCounts;
    }
    std::cout << "two threshhold: " << two << '\n';
    std::cout << "three threshhold: " << three << '\n';
    std::cout << "---------END---------" << std::endl;
}

std::string WristScanner::findPrototypeBoxes()
{
    bool found = false;

    std::stringstream result;

    for (auto box = boxes.begin(); box != boxes.end() && !found; ++box)
    {
        // Point to box id
        //std::string *boxId = &box.base()->getId();
        std::string *boxId = &(*box)->getId();
        std::cout << "\n\nChecking id " << *boxId << ":" << '\n';

        for (auto box2 = boxes.begin(); box2 != boxes.end() && !found; ++box2)
        {
            int failedMatch = 0;
            std::string *box2Id = &(*box2)->getId();

            std::cout << "\t" << *box2Id << '\n';

            for (auto i = 0; i < boxId->size() && i < box2Id->size() && failedMatch <= 1; ++i)
            {
                if ((*boxId)[i] != (*box2Id)[i])
                {
                    ++failedMatch;
                }
                else
                {
                    //result.append(&box2Id->at(i));
                    result << ((*box2Id)[i]);
                }
            }

            if (failedMatch == 1)
            {
                found = true;
            }
            else if (failedMatch > 1)
            {
                result.str(std::string());
                result.clear();
            }
        }

    }
    
    return result.str();
}

int64_t WristScanner::checksum()
{
    int64_t chkSum = mTwoCounts * mThreeCounts;
    return chkSum;
}


void WristScanner::print()
{
    for (auto &i : boxes)
    {
        std::cout << i->getId() << '\n';
    }
}
