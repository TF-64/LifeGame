//
//  field.cpp
//  gameoflife
//
//  Created by Ivan Fadeev on 13.06.2023.
//

#include "field.hpp"

#include <iostream>
#include <unistd.h>


Field::Field(int rows, int cols, int sleeptime) {
    this->rows = rows;
    this->cols = cols;
    this->sleeptime = sleeptime;
    m = new char*[rows];
      
    for(int i = 0; i < rows; i++) m[i] = new char[cols];
}


void Field::print() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
          std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
        
    }
    
    
}


void Field::liveday() {
    //cls();


      char** temp = m;

      for(int i = 0; i < rows; i++) for(int j = 0; j < cols; j++) {
        int neighboors = 0;
        
        // search for neighboors
        
        for(int n = -1; n <= 1; n++) for(int k = -1; k <= 1; k++) {
          if(!(n == 0 && k == 0) && i+n >= 0 && i+n < rows && j+k >= 0 && j+k < cols)
            if(m[i+n][j+k] == '*') neighboors++;
        }



        if(m[i][j] == '*' && (neighboors < 2 || neighboors > 3))  // alive
          temp[i][j] = ' ';
        

        else  //dead
            if(neighboors == 3) temp[i][j] = '*';
    }

    m = temp;
      
    print();

    usleep(sleeptime*1000);
    
}


void Field::livelife(int days) {
    for(int i = 0;i < days; i++) liveday();
    
}


void Field::generate(int seed) {
    
    for(int i = 0; i < rows; i++) for(int j = 0; j < cols; j++) {
        if(std::rand() % seed == 0)
            m[i][j] = '*';
        else
            m[i][j] = ' ';
    }
    
    
}
