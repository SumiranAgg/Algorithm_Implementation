//
//  Node.cpp
//  Cycle_Basis_PF
//
//  Created by Sumiran on 17/06/2014.
//  Copyright (c) 2014 NICTA. All rights reserved.
//

#include "Node.h"
#include "Net.h"
#include "Path.h"
#include <iostream>

Node::Node(){
    Bus::Bus();
    explored=false;
    cycle=false;
    cg=false;
    distance=INT_MAX;
    predecessor = NULL;
}


Node* Node::clone(){
    Node* copy = new Node();
    copy->ID = ID;
    return copy;
}


/* number of incident lines */
int Node::degree(){
    return (int)branches.size();
}


/*
 @brief Find and remove incident arc from list of branches
 @return 0 if a was found and removed, -1 oterwise 
 */
int Node::removeArc(Arc* a){
    vector<Arc*>::iterator it = branches.begin();
    while (it != branches.end()) {
        if((*it) == a){
            it = branches.erase(it);
            return 0;
        }
        it++;
    }
    return -1;
}

/*
 @brief Adds a to the list of incident arcs
 */
void Node::addArc(Arc* a){
    branches.push_back(a);
}

/*
 @brief Removes first incident arc from list of branches
 @return the next branch if any
 */
std::vector<Arc*>::iterator Node::removeFirstArc(){
    return branches.erase(branches.begin());
}


void Node::print(){
    if(gen)
        std::cout<< "Generator " << ID;
    else
        std::cout << "Bus " << ID;
    if(gen){
        std::cout << "; Pg = " << Pg;
        std::cout << "; Qg = " << Qg;
        std::cout << "; Pmin = " << Pmin;
        std::cout << "; Pmax = " << Pmax;
        std::cout << "; c1 = " << c1;
        std::cout << "; c2 = " << c2;
    }
    else{
        std::cout << "; Pl = " << Pl;
        std::cout << "; Ql = " << Ql;
    }
    std::cout << "; Vmin = " << Vmin;
    std::cout << "; Vmax = " << Vmax;
    std::cout << "; Number of Branches = " << branches.size();
    std::cout << "; Degree = " << degree()<< std::endl;
//    std::cout << "; Position = " << pos << std::endl;
}

