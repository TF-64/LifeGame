


#include <iostream>
#include "field.hpp"


int main() {
    std::cout << "columns, rows, days, generation seed, sleeping time" << std::endl;
    int cols, rows, days, seed, sleeptime;
    std::cin >> rows >> cols >> days >> seed >> sleeptime;
    
    
    
    Field colony(rows, cols, sleeptime);

    colony.generate(seed);

    colony.livelife(days);
}
