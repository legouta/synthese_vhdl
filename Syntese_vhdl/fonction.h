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
void fct_write_file(string chaine_de_carac, string path);
void fct_append_file(string chaine_de_carac, string path);
void fct_lexem_endl(string nom_fichier_en_min,string path_cible);
void test_fct_lexem(string nom_fichier_lexem_endl);
void fct_suppr_double_endl(string nom_fichier_lexem_endl,string path_cible);
void range_arbre(list<string> list_lexem, tree<string> &tr);
void fct_liste_lexeme(string nom_fichier_clean, list<string> &liste_lexemes);
int test_syntaxe(list<string> a);

list<string>::iterator range_library(list<string>::iterator, tree<string> &tr, tree<string>::iterator);
list<string>::iterator range_use(list<string>::iterator, tree<string> &tr, tree<string>::iterator);
list<string>::iterator range_entity(list<string>::iterator, tree<string> &tr, tree<string>::iterator);
list<string>::iterator range_archi(list<string>::iterator, tree<string> &tr, tree<string>::iterator,list<string> list_lexem);
list<string>::iterator range_port(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_ports,string str_nom_port);
list<string>::iterator range_signal(list<string>::iterator i,tree<string> &tr, tree<string>::iterator i_nom_signal);
list<string>::iterator range_multi_signaux(list<string>::iterator i,tree<string> &tr, tree<string>::iterator i_nom_signal, tree<string>::iterator i_type_declaration, list<string> liste);
list<string>::iterator range_variable(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_nom_variable);
list<string>::iterator range_multi_variables(list<string>::iterator i,tree<string> &tr, tree<string>::iterator i_nom_variable, tree<string>::iterator i_type_declaration,list<string> liste);
list<string>::iterator range_instructions_concurentes(list<string>::iterator i,tree<string> &tr, tree<string>::iterator i_range_instructions_concurentes, string nom_archi,list<string> liste);
list<string>::iterator range_instrcutions_sequentielles(list<string>::iterator i,tree<string> &tr, tree<string>::iterator i_process, list<string> liste);
list<string>::iterator range_affectation(list<string>::iterator i,tree<string> &tr, tree<string>::iterator i_affectation);
list<string>::iterator detection_parenthese(list<string>::iterator i,tree<string> &tr);
list<string>::iterator range_source_A(list<string>::iterator i,tree<string> &tr, tree<string>::iterator i_source);
list<string>::iterator detection_parenthese_envers(list<string>::iterator i,tree<string> &tr);
list<string>::iterator range_source_B(list<string>::iterator i,tree<string> &tr, tree<string>::iterator i_source);
list<string>::iterator range_affectation_seq_cond(list<string>::iterator i,tree<string> &tr, tree<string>::iterator i_affectation_conditionnelle, list<string> liste);
list<string>::iterator while_conditionnel(list<string>::iterator i,tree<string> &tr, tree<string>::iterator i_else, list<string> liste);
void creer_liste(tree<string> &tr,list<string> &liste_nom,list<string> &liste_sous_type, list<string> &liste_type, list<string> &liste_taille);


void synthese(tree<string> &tr, string path_synthese, string path_signaux_interm,string path_portes_interm, list<string> &liste_nom, list<string> &liste_type);
void recopie_fichier(string path_cible, string path_source);
list<string>::iterator check_assignation(tree<string> &tr);
void synt_affec(tree<string> &tr, tree<string>::iterator it, string path_synthese, string path_signaux_interm,string path_portes_interm, list<string> portes_util,list<string> &liste_nom,list<string> &liste_type);
void synth_source_bis(tree<string> &tr, tree<string>::iterator it, string path_signaux_interm,string path_portes_interm, list<string> &portes_util,list<string> &liste_nom,list<string> &liste_type);
string creer_sig_int(string path_signaux_interm);
void synth_porte(string source_a,string operateur,string source_b, string destination, string path_portes_interm, list<string> portes_util, string path_signaux_interm,list<string> &liste_nom,list<string> &liste_type);
void fonction_opif;

void print_tree(const tree<string> &tr, tree<string>::pre_order_iterator it, tree<string>::pre_order_iterator end, string chemin_5);


#endif	/* FONCTION_H */

