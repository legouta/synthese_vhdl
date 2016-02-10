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
string creer_porte(string operateur, list<string> &portes_util, string type_source_a);

void synth_porte(string source_a,string operateur,string source_b, string destination, string path_portes_interm, list<string> &portes_util, string path_signaux_interm,
        list<string> &liste_nom,list<string> &liste_type,list<string> &liste_taille)
{
    string type_source_a, taille_source_a;
    string nom_porte;
    string tempo, nom_operateur;
    list<string>::iterator itl,itl2;
    int rang_signal, rang_type;
    rang_signal=0;
    rang_type=0;
    
    itl=liste_nom.begin();
    while(*itl!=source_a)
    {
        rang_signal++;
        itl++;
    }
    
    itl=liste_type.begin();
    itl2=liste_taille.begin();
    while(rang_signal!=rang_type)
    {
        rang_type++;
        itl++;
        itl2++;
    }
    type_source_a=*itl;
    taille_source_a=*itl2;
    
    
    if(operateur=="and")
    {
        nom_porte=creer_porte(operateur,portes_util, type_source_a);
        synth_and(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a);
    }

    if(operateur=="or")
    {
        nom_porte=creer_porte(operateur,portes_util, type_source_a);
        synth_or(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a);
    }
   
    if(operateur=="xor")
    {
        nom_porte=creer_porte(operateur,portes_util, type_source_a);
        synth_xor(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a);
    }
    
    if(operateur=="+")
    {
        nom_operateur="add";
        nom_porte=creer_porte(nom_operateur,portes_util, type_source_a);
        tempo=creer_sig_int(path_signaux_interm,liste_nom,liste_type,"std_logic","0");//carry
        synth_add(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a,tempo);
    }
    
    if(operateur=="-")
    {
        nom_operateur="sub";
        nom_porte=creer_porte(nom_operateur,portes_util, type_source_a);
        tempo=creer_sig_int(path_signaux_interm,liste_nom,liste_type,"std_logic","0");//carry
        synth_sub(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a,tempo);
    }
    
    if(operateur=="*")
    {
        nom_operateur="mult";
        nom_porte=creer_porte(nom_operateur,portes_util, type_source_a);
        tempo=creer_sig_int(path_signaux_interm,liste_nom,liste_type,"std_logic","0");//carry
        synth_mult(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a,tempo);
    }
    
    if(operateur=="=")
    {
        nom_operateur="eq";
        nom_porte=creer_porte(nom_operateur,portes_util, type_source_a);
        synth_eq(source_a, operateur, source_b, destination, path_portes_interm, nom_porte, type_source_a);
    }
}

string creer_porte(string operateur, list<string> &portes_util, string type_source_a)
{
    stringstream nom_porte;
    string tempo;
    list<string>::iterator it;
    bool existe=true;
    int nb=0;
    
    
    tempo.clear();
    if(type_source_a=="std_logic")
    {
        tempo=operateur+"_bit_";
    }
    if(type_source_a=="std_logic_vector")
    {
        tempo=operateur+"_vector_";
    }
    //cout<<"tempo "<<tempo.str();
    while(existe==true)
    {
        nom_porte.str("");
        nom_porte<<"porte_";
        //cout<<"nb debut "<<nb<<endl;
        nom_porte<<nb;
        //cout<<"porte vaut "<<nom_porte.str()<<endl;

        existe=false;
        for(it=portes_util.begin();it!=portes_util.end();it++)
        {
            if(*it==nom_porte.str())
            {
                existe=true;
                
            }
        }
        nb=nb+1;
        //cout<<"nb fin"<<nb<<endl;
        
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