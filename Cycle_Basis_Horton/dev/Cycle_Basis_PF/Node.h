//
//  Node.h
//  Cycle_Basis_PF
//
//  Created by Sumiran on 17/06/2014.
//  Copyright (c) 2014 NICTA. All rights reserved.
//

#ifndef Cycle_Basis_PF_Node_h
#define Cycle_Basis_PF_Node_h
#include "Bus.h"
#include <vector>
#include "Line.h"


class Path;
class Arc;
class Net;

class Node : public Bus {
public:
    /* marks the node if it has been explored or not */
    bool explored;
    /* true if node is in cycle */
    bool cycle;
    /* if node in cycle and power flows in the cycle through this node */
    bool cg;
    int ID;
    Node* predecessor;
    int distance;
    std::vector<Arc*> branches;
    
    Node();
    Node* clone();
    
    /* number of incident lines */
    int degree();
    
    /*
     @brief Adds a to the list of incident arcs
     */
    void addArc(Arc* a);

    /*
     @brief Find and remove incident arc from list of branches
     @return 0 if a was found and removed, -1 otherwise
     */
    int removeArc(Arc* a);
    
    /*
     @brief Removes first incident arc from list of branches
     @return 0 if the list contains at least one arc, -1 otherwise
     */
    std::vector<Arc*>::iterator removeFirstArc();
    
    void print();

};

#endif
