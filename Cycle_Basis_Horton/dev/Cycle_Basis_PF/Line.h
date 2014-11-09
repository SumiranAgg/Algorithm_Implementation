//
//  Line.h
//  Cycle_Basis_PF
//
//  Created by Sumiran on 16/06/2014.
//  Copyright (c) 2014 NICTA. All rights reserved.
//

#ifndef Cycle_Basis_PF_Line_h
#define Cycle_Basis_PF_Line_h

class Line {
public:
    int id;
    double S;
    double ch;
    double tr;
    double as;
    double r;
    double x;
    double g;
    double b;
    int status;
    
    Line();
    
    void print();

};

#endif
