/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;

void synth_and(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a);
void synth_or(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a);
void synth_xor(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a);
void synth_add(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a, string sig_carry);
void synth_sub(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a, string sig_carry);
void synth_mult(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a, string sig_carry);
void synth_eq(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a);
string creer_porte(string operateur, list<string> portes_util, string type_source_a);

void synth_porte(string source_a,string operateur,string source_b, string destination, string path_portes_interm, list<string> portes_util, string path_signaux_interm,list<string> &liste_nom,list<string> &liste_type)
{
    string type_source_a;
    string nom_porte;
    string tempo;
    //test sur source_a pour savoir si c'est bit ou bit_vector
    nom_porte=creer_porte(operateur,portes_util, type_source_a);
    
    if(operateur=="and")
    {
        synth_and(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a);
    }

    if(operateur=="or")
    {
        synth_or(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a);
    }
   
    if(operateur=="xor")
    {
        synth_xor(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a);
    }
    
    if(operateur=="+")
    {
        tempo=creer_sig_int(path_signaux_interm,liste_nom,liste_type);
        synth_add(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a,tempo);
    }
    
    if(operateur=="-")
    {
        tempo=creer_sig_int(path_signaux_interm,liste_nom,liste_type);
        synth_sub(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a,tempo);
    }
    
    if(operateur=="*")
    {
        tempo=creer_sig_int(path_signaux_interm,liste_nom,liste_type);
        synth_mult(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a,tempo);
    }
    
    if(operateur=="=")
    {
        synth_eq(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a);
    }
}

string creer_porte(string operateur, list<string> portes_util, string type_source_a)
{
    stringstream nom_porte;
    stringstream tempo;
    list<string>::iterator it;
    nom_porte.clear();
    bool existe=false;
    int nb;
    
    if(type_source_a=="std_logic")
    {
        tempo<<operateur<<"_bit_";
    }
    if(type_source_a=="std_logic_vector")
    {
        tempo<<operateur<<"_vector_";
    }
    while(existe==true)
    {
        nom_porte.clear();
        nom_porte<<tempo;
        nom_porte<<nb;
        for(it=portes_util.begin();it!=portes_util.end();it++)
        {
            if(*it==nom_porte.str())
            {
                existe=true;
            }
            else
            {
                existe=false;
            }
        }
        nb++;
    }
    portes_util.push_back(nom_porte.str());  
    return nom_porte.str();
}


void synth_and(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a)
{
    stringstream a_ecrire;
    a_ecrire.clear();
    a_ecrire<<nom_porte<<" : "<<"and_2";
    if(type_source_a=="std_logic_vector")
    {
        a_ecrire<<"_vec";
    }
    a_ecrire<<" port map ("<<endl;
    a_ecrire<<"    a => "<<source_a<<","<<endl;
    a_ecrire<<"    b => "<<source_b<<","<<endl;
    a_ecrire<<"    c => "<<destination<<");"<<endl<<endl;
    fct_append_file(a_ecrire.str(),path_portes_interm);
    a_ecrire.clear();    
}

void synth_or(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a)
{
    stringstream a_ecrire;
    a_ecrire.clear();
    a_ecrire<<nom_porte<<" : "<<"or_2";
    if(type_source_a=="std_logic_vector")
    {
        a_ecrire<<"_vec";
    }
    a_ecrire<<" port map ("<<endl;
    a_ecrire<<"    a => "<<source_a<<","<<endl;
    a_ecrire<<"    b => "<<source_b<<","<<endl;
    a_ecrire<<"    c => "<<destination<<");"<<endl<<endl;
    fct_append_file(a_ecrire.str(),path_portes_interm);
    a_ecrire.clear();    
}

void synth_xor(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a)
{
    stringstream a_ecrire;
    a_ecrire.clear();
    a_ecrire<<nom_porte<<" : "<<"xor_2";
    if(type_source_a=="std_logic_vector")
    {
        a_ecrire<<"_vec";
    }
    a_ecrire<<" port map ("<<endl;
    a_ecrire<<"    a => "<<source_a<<","<<endl;
    a_ecrire<<"    b => "<<source_b<<","<<endl;
    a_ecrire<<"    c => "<<destination<<");"<<endl<<endl;
    fct_append_file(a_ecrire.str(),path_portes_interm);
    a_ecrire.clear();    
}

void synth_add(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a, string sig_carry)
{
    stringstream a_ecrire;
    a_ecrire.clear();
    a_ecrire<<nom_porte<<" : "<<"add";
    a_ecrire<<" port map ("<<endl;
    a_ecrire<<"    A => "<<source_a<<","<<endl;
    a_ecrire<<"    B => "<<source_b<<","<<endl;
    a_ecrire<<"    R => "<<destination<<","<<endl;
    a_ecrire<<"    c_out => "<<sig_carry<<");"<<endl<<endl;
    fct_append_file(a_ecrire.str(),path_portes_interm);
    a_ecrire.clear();    
}

void synth_sub(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a, string sig_carry)
{
    stringstream a_ecrire;
    a_ecrire.clear();
    a_ecrire<<nom_porte<<" : "<<"sub";
    a_ecrire<<" port map ("<<endl;
    a_ecrire<<"    A => "<<source_a<<","<<endl;
    a_ecrire<<"    B => "<<source_b<<","<<endl;
    a_ecrire<<"    R => "<<destination<<","<<endl;
    a_ecrire<<"    c_out => "<<sig_carry<<");"<<endl<<endl;
    fct_append_file(a_ecrire.str(),path_portes_interm);
    a_ecrire.clear();    
}

void synth_mult(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a, string sig_carry)
{
    stringstream a_ecrire;
    a_ecrire.clear();
    a_ecrire<<nom_porte<<" : "<<"mult";
    a_ecrire<<" port map ("<<endl;
    a_ecrire<<"    A => "<<source_a<<","<<endl;
    a_ecrire<<"    B => "<<source_b<<","<<endl;
    a_ecrire<<"    R => "<<destination<<","<<endl;
    a_ecrire<<"    c_out => "<<sig_carry<<");"<<endl<<endl;
    fct_append_file(a_ecrire.str(),path_portes_interm);
    a_ecrire.clear();    
}

void synth_eq(string source_a,string operateur,string source_b, string destination, string path_portes_interm, string nom_porte, string type_source_a)
{
    stringstream a_ecrire;
    a_ecrire.clear();
    a_ecrire<<nom_porte<<" : "<<"eq";
    if(type_source_a=="std_logic_vector")
    {
        a_ecrire<<"_vec";
    }
    a_ecrire<<" port map ("<<endl;
    a_ecrire<<"    a => "<<source_a<<","<<endl;
    a_ecrire<<"    b => "<<source_b<<","<<endl;
    a_ecrire<<"    c => "<<destination<<");"<<endl<<endl;
    fct_append_file(a_ecrire.str(),path_portes_interm);
    a_ecrire.clear();    
}