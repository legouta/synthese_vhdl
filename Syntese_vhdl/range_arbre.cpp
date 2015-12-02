/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <algorithm>
#include <string>
#include <iostream>
#include "tree.hh"

using namespace std;

void range_arbre(string nom_fichier_clean)
{
   tree<string> tr;
   tree<string>::iterator top, one, two, loc, banana;

	top=tr.begin();
   one=tr.insert(top, "one");
   two=tr.append_child(one, "two");
	tr.append_child(two, "apple");
	banana=tr.append_child(two, "banana");
	tr.append_child(banana,"cherry");
	tr.append_child(two, "peach");
   tr.append_child(one,"three");
}