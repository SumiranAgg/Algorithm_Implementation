//
//  Bus.cpp
//  Cycle_Basis_PF
//
//  Created by Sumiran on 17/06/2014.
//  Copyright (c) 2014 NICTA. All rights reserved.
//

#include "Bus.h"
#include <iostream>

Bus::Bus(){
    b_ID = -1;
    gen = false;
    sh_b = 0;
    sh_g = 0;
    kv_b = 0;
    lflow_p = 0;
    lflow_v = 0;
    Ql = 0;
    Pl = 0;
    Vmin = 0;
    Vmax = 0;
    Qmin = 0;
    Qmax = 0;
    Pg = 0;
    Qg = 0;
    theta = 0;
    c0 = 0;
    c1 = 0;
    c2 = 0;
}

void Bus::print(){
    if(gen)
        std::cout<< "Generator " << b_ID;
    else
        std::cout << "Bus " << b_ID;
    if(gen){
        std::cout << "; Pg = " << Pg;
        std::cout << "; Qg = " << Qg;
        std::cout << "; Pmin = " << Pmin;
        std::cout << "; Pmax = " << Pmax;
        std::cout << "; load_flow_p" << lflow_p;
        std::cout << "; c0 = " << c1;
        std::cout << "; c1 = " << c1;
        std::cout << "; c2 = " << c2;
    }
    else{
        std::cout << "; Pl = " << Pl;
        std::cout << "; Ql = " << Ql;
        std::cout << "; load_flow_v" << lflow_v;
    }
    std::cout << "; Vmin = " << Vmin;
    std::cout << "; Vmax = " << Vmax;
    std::cout << "; shunt_g = " << sh_g;
    std::cout << "; shunt_b = " << sh_b;
}