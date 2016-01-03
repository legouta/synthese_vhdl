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
list<string>::iterator range_port(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_ports,string str_nom_port);
list<string>::iterator range_signal(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_nom_signal);
list<string>::iterator range_multi_signaux(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_nom_signal, tree<string>::iterator i_type_declaration);
list<string>::iterator range_instructions_concurentes(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_range_instructions_concurentes, string nom_archi);
list<string>::iterator range_instrcutions_sequentielles(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_range_instructions_sequentielles);
list<string>::iterator range_affectation(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_affectation);
list<string>::iterator detection_parenthese(list<string>::iterator i,tree<string>& tr);
list<string>::iterator range_source_A(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_source);
list<string>::iterator detection_parenthese_envers(list<string>::iterator i,tree<string>& tr);
list<string>::iterator range_source_B(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_source);



#endif	/* FONCTION_H */

