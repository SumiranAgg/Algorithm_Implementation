//
//  Net.h
//  Cycle_Basis_PF
//
//  Created by Sumiran on 16/06/2014.
//  Copyright (c) 2014 NICTA. All rights reserved.
//

#ifndef Cycle_Basis_PF_Net_h
#define Cycle_Basis_PF_Net_h

#include <map>
#include "Arc.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Node.h"
#include "Path.h"
#include <assert.h>



using namespace std;

class Net{
public:
    

    double bMVA;
    /* Set of nodes */
    vector<Node*> nodes;
    /* Set of arcs */
    vector<Arc*> arcs;
    /* Set of generators */
    vector<Node*> gens;
    /* Mapping the arc to its source-destination */
    map<string, Arc*> lineID;
    /* Mapping the node id to its position in the vector, key = node id */
    map<int, Node*> nodeID;
    /* Vector of cycles forming a cycle basis */
    vector<Path*> cycle_basis;
    /* Horton subnetwork */
    Net* horton_net;
    /* structure for a new constraint */
    struct constraint{
        int cycle_index;
        /* it stors the gen node, the id of link tp next node, next node, id of link to prev node, prev node */
        int arr[5];
        double cnst;
    };
    /* vector of constraints bounding ratio os current magnitudes */
    vector<constraint> new_constraints;

    
    /* Constructors */
    
    Net();
    
    /* Destructors */
    
    ~Net();
    
    /* Erase Horton network */
    void clear_horton_net();
    
    /* Modifiers */
    
    void add_node(Node* n);
    
    /*  @brief Remove node and all incident arcs from the network
        @note Does not remove the incident arcs from the list of arcs in the network!
        @return the id of the node removed
     */
    int remove_end_node();
    
    void add_arc(Arc* a);
    
    vector<Arc*>::iterator remove_arc(Arc* a);

    /* Sort nodes in decreasing degree */
    void orderNodes(Net* net);
    
    /* Sort arcs in decreasing weight */
    void orderArcs(Net* net);
    
    void add_horton_nodes(Net* net);
    
    void add_horton_branches(Net* net);
    
    /* Accessors */
    
    Node* get_node(int id);

    /* Input Output */
    
    int readFile(string fname);
   
    void writeDAT(string name);
    
    /* Algorithms */
    
    /* Reset all distances to max value */
    void resetDistance();
    
    /* Computes and returns the shortest path between src and dest in net */
    Path* Dijkstra(Node* src, Node* dest, Net* net);
    
    /*  @brief Computes a spanning tree of minimal weight in horton's network, then adds the corresponding cycles to the original network by connecting to src
        @note Implements Kruskal’s greedy algorithm
     */
    void minimal_spanning_tree(Node* src, Net* net);

    /* Combines the src node with the path p to form a cycle */
    void combine(Node* src, Path* p);
    
    void Fast_Horton();
    
    void Fast_Horton(Net *net);
    
    /* adds decimal to an integer for precision */
    void precise(ofstream &myfile, float f);
    
    /* Cloning */
    
    Net* clone();
    
    /* finds arc paralel to the given arc and prints the self loop */
    int self_loops(ofstream &myfile, Arc* arc, int cycle_index);
    
    /* returns the Id of the arc formed by node ids n1 and n2 */
    Arc* arc(int n1, int n2);
    
    /* writes path p on myfile */
    void write(std::ofstream &myfile, Path* p, int cycle_index);
    
    /* returns true if an arc is already present between the given nodes */
    bool duplicate(int n1, int n2, int id1);
    
    /*identifies the generator bus in the cycle*/
    void s_flowIn_cycle(Path* p);
    
    /*checks neighbours of a gen bus if present in any cycle*/
    bool check_neighbour(Node* n);
    
    /* forms constraint for each cycle in the cycle basis */
    void Constraint();
    
    /* computes the constant for each gen node in each cycle */
    double compute_constant(Path* cycle);
    
    /* rearranges cycle according to gen node */
    Path* form_cycle(Node* n, Path* p);
    
    /* adds constraint to vector new_constraints */
    void addConstraint(int c, Path* cycle);
    
    /* sets the cycle member fo all odes to be false */
    void reset_nodeCycle();
    
    /* sets all nodesto unexplored */
    void reset_nodeExplored();
};
#endif
