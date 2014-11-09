//
//  main.cpp
//  MP2DAT
//
//  Created by Hassan Hijazi on 14/01/13.
//  Copyright (c) 2013 NICTA. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include "Net.h"
#include <fstream>


/* returns name for the corresponding dat file */
string file_name(string word){
    string s, name = "";
    s = string ( word.rbegin(), word.rend() );
    string::iterator it = s.begin() + s.find('.') + 1;
    while (*it != '/') {
        name = name + *it;
        it++;
    }
    name = string ( name.rbegin(), name.rend() );
    name = name + "_CB.dat";
    return name;
}

int main (int argc, const char * argv[])
{
    /* reading file containing names of all m files */
    string fname = "file_names.txt";
    ifstream file(fname.c_str());
    string word;
    file >> word;
    /* convertig each m file to dat file */
    while (word.compare("end;")){
        Net Pnet;
        Pnet.readFile(word);
        Pnet.Fast_Horton();
        Pnet.writeDAT(file_name(word));
        file >> word;
    }
    return 0;
}

