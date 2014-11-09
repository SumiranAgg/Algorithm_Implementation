//
//  Bus.h
//  Cycle_Basis_PF
//
//  Created by Sumiran on 16/06/2014.
//  Copyright (c) 2014 NICTA. All rights reserved.
//

#ifndef Cycle_Basis_PF_Bus_h
#define Cycle_Basis_PF_Bus_h

class Bus {
public:
    
    int b_ID;
    bool gen;
    double Ql;
    double Pl;
    double sh_b;
    double sh_g;
    double kv_b;
    double lflow_v;
    double lflow_p;
    double Vmin;
    double Vmax;
    double Pmin;
    double Pmax;
    double Qmin;
    double Qmax;
    double Pg;
    double Qg;
    double theta;
    double c0;
    double c1;
    double c2;
    
    Bus();
    
    void print();
};

#endif
