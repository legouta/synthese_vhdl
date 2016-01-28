#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;


void print_tree(const tree<string>& tr, tree<string>::pre_order_iterator it, tree<string>::pre_order_iterator end, string chemin_5)
{
    stringstream tempo;
    
    tempo.clear();
	if(!tr.is_valid(it)) return;
	int rootdepth=tr.depth(it);
        tempo.clear();
	tempo << "-----" << endl<<"   ";
        fct_write_file(tempo.str(),chemin_5);
	while(it!=end) {
            tempo.clear();
		for(int i=0; i<tr.depth(it)-rootdepth; ++i) 
                {
                    tempo << "~ "; 
                }
            tempo<<(*it) << endl << "   "<< flush;
                    fct_write_file(tempo.str(),chemin_5);
                                        
		++it;
		}
        tempo.clear();
	tempo << "-----" << endl;
        fct_write_file(tempo.str(),chemin_5);
        tempo.clear();
}