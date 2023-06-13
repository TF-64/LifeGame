//
//  field.hpp
//  gameoflife
//
//  Created by Ivan Fadeev on 13.06.2023.
//


class Field {
    int rows, cols, sleeptime;
    char** m;
    
    public:
        Field(int rows, int cols, int sleeptime);
        void generate(int seed);
        void print();
        void liveday();
        void livelife(int days);
};
