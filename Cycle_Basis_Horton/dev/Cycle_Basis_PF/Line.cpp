//
//  Line.cpp
//  Cycle_Basis_PF
//
//  Created by Sumiran on 17/06/2014.
//  Copyright (c) 2014 NICTA. All rights reserved.
//

#include "Line.h"
#include <iostream>

Line::Line(){
    id = -1;
    ch = 0;
    tr = 0;
    as = 0;
    S = 0;
    r = 0;
    x = 0;
    g = 0;
    b = 0;
    status = -1;
}

void Line::print(){
    std::cout << "S = " << S;
    std::cout << "; r = " << r;
    std::cout << "; x = " << x;
    std::cout << "; charge = " << ch;
    std::cout << "; tr = " << tr;
    std::cout << "; as = " << as << std::endl;
}
