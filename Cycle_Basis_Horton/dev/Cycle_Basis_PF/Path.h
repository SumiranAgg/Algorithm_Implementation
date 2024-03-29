//
//  Path.h
//  Cycle_Basis_PF
//
//  Created by Sumiran on 17/06/2014.
//  Copyright (c) 2014 NICTA. All rights reserved.
//

#ifndef Cycle_Basis_PF_Path_h
#define Cycle_Basis_PF_Path_h
#include <list>
#include "Node.h"

class Path{
public:
    
    std::list<Node*> nodes;
    
    /* @brief Returns true if the pair (n1,n2) is a source-destination pair for this path */
    bool source_dest(Node* n1, Node* n2);
    
    /* Returns the length of the path */
    int length();
    
    /* Returns true if the path is a cycle */
    bool cycle();
    
    Path* clone();
};

#endif
