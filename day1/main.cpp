#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main(int argc, char** args)
{
    int64_t frequency = 0;
    std::vector<int64_t> freqHistory;
    bool seenTwice = false;

    std::string fileName = "input.txt";
    std::ifstream file;

    std::string line;

    while(!seenTwice)
    {

        file.open(fileName);
        while(file.is_open() && std::getline(file, line) && !seenTwice)
        {
            //std::cout << line << '\n';
            char operand;
            std::string number;

            for (auto c = line.begin(); c != line.end(); ++c)
            {
                //std::cout << *c << '\n';

                if (*c == '+' || *c == '-')
                    operand = *c;
                else
                    number += *c;
            }

            // Convert from string to int
            int n = std::stoi(number);

            if (operand == '+')
                frequency += n;
            else
                frequency -= n;

            for (auto i = freqHistory.begin(); i != freqHistory.end(); ++i)
            {
                if (*i == frequency)
                {
                    std::cout << "match! " << *i << " == " << frequency << '\n';
                    seenTwice = true;
                }
            }

            freqHistory.push_back(frequency);

            //std::cout << "Operand: " << operand << "number: " << number << '\n';
        }
        file.close();
        // continue untill seentwice
    }

    std::cout << "Frequency seen twice: " << frequency << std::endl;

    file.close();
    return 0;
}
