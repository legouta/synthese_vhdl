#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

#ifndef FONCTION_H
#define	FONCTION_H
#include "tree.hh"


int  principal_antoine();
int  principal_damien();
string fct_Maj_To_Min(string path_fichier);
void fct_write_file(string code_en_min);
void fct_lexem_endl(string nom_fichier_en_min);
void test_fct_lexem(string nom_fichier_lexem_endl);
void fct_suppr_double_endl(string nom_fichier_lexem_endl);
tree<string> range_arbre(list<string> list_lexem);
list<string> fct_liste_lexeme(string nom_fichier_clean);
list<string>::iterator range_library(list<string>::iterator, tree<string>&, tree<string>::iterator);
list<string>::iterator range_use(list<string>::iterator, tree<string>&, tree<string>::iterator);
list<string>::iterator range_entity(list<string>::iterator, tree<string>&, tree<string>::iterator);
list<string>::iterator range_archi(list<string>::iterator, tree<string>&, tree<string>::iterator);


#endif	/* FONCTION_H */

