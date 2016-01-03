/* 
 * File:   main.cpp
 * Author: legouta
 *
 * Created on 8 octobre 2015, 14:05
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "fonction.h"
#include "tree.hh"

using namespace std;
void print_tree(const tree<std::string>& tr, tree<std::string>::pre_order_iterator it, tree<std::string>::pre_order_iterator end);

/*
 * 
 */
int principal_damien() {
//string    chemin_1 = "/.automount/nfs5176/exports/users1/phelma2014/legouta/Bureau/test.txt";
//string    chemin_2 = "/.automount/nfs5176/exports/users1/phelma2014/legouta/Bureau/fichier_en_min.txt";
string    chemin_1 = "/home/damien/Workspace/synthese_vhdl/fichier_test/test.txt";
string    chemin_2 = "/home/damien/Workspace/synthese_vhdl/fichier_test/fichier_en_min.txt";
string    chemin_3 = "/home/damien/Workspace/synthese_vhdl/fichier_test/lexem_endl.txt";
string    chemin_4 = "/home/damien/Workspace/synthese_vhdl/fichier_test/fichier_clean.txt";
list<string> a;
list<string>::const_iterator i=a.begin();
tree<string>::iterator loc;
tree<string> tr;


//cout << fct_Maj_To_Min("/.automount/nfs5176/exports/users1/phelma2014/legouta/Bureau/test.txt");
fct_write_file(fct_Maj_To_Min(chemin_1)); 
fct_lexem_endl(chemin_2);
fct_suppr_double_endl(chemin_3);
a=fct_liste_lexeme(chemin_4);
//for(i=a.begin();i!=a.end();i++)
//{cout<<*i<<endl;}
tr=range_arbre(a);
print_tree(tr,tr.begin(),tr.end());
  return 0;
}


void print_tree(const tree<string>& tr, tree<string>::pre_order_iterator it, tree<string>::pre_order_iterator end)
	{
	if(!tr.is_valid(it)) return;
	int rootdepth=tr.depth(it);
	cout << "-----" << endl<<"   ";
	while(it!=end) {
		for(int i=0; i<tr.depth(it)-rootdepth; ++i) 
			std::cout << "~ ";
		cout <<(*it) << endl << "   "<< flush;
		++it;
		}
	cout << "-----" << endl;
	}