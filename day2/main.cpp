#include "wristscanner.h"
#include "box.h"
#include <fstream>

void printPrototypes(WristScanner *scanner)
{
    std::string result = scanner->findPrototypeBoxes();
    std::cout << "Protoype is " << result << " size " << result.size() << std::endl;
}

void printChecksum(WristScanner *scanner)
{
    //wristscanner.print();
    std::cout << "twcounts = " << scanner->getTwoCounts() 
        << "\nthreecounts = " << scanner->getThreeCounts() << '\n';
    std::cout << "Checksum ended up being: " << scanner->checksum() << std::endl;
}

int main(int argc, char **argv)
{
    WristScanner wristscanner;
    std::ifstream file;
    file.open("input.txt");

    std::string line;
    while(std::getline(file, line) && file.is_open())
    {
        //std::cout << "Creating a box with " << line << '\n';
        wristscanner.scan(new Box(line));
    }
    file.close();

    printPrototypes(&wristscanner);

    return 0;
};
