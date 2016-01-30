/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "fonction.h"
#include "tree.hh"
using namespace std;


list<string>::iterator range_instrcutions_sequentielles(list<string>::iterator i,tree<string>& tr, tree<string>::iterator i_process, list<string> liste)
{
    list<string>::iterator a,b,c;
    tree<string>::iterator i_liste_sensi;
    tree<string>::iterator i_menbre_liste;
    tree<string>::iterator i_declaration;
    tree<string>::iterator i_type_declaration;
    tree<string>::iterator i_nom_variable;
    tree<string>::iterator i_affectation;
    tree<string>::iterator i_range_instructions_sequentielles;
    tree<string>::iterator i_affectation_conditionnelle;
    a=i;
    b=i;
    if(a!=liste.end())
    {
        b++;
    }
    //cout<<"b vaut : "<<*b;
    if(*b=="(")
    {
        i_liste_sensi=tr.append_child(i_process,"liste_de_sensibilité");
        b++;
        while(*b!=")")
        {
            i_menbre_liste=tr.append_child(i_liste_sensi,*b);
            b++;
            if(*b==",")
            {
                b++;
            }
        }
    }
    else
    {
        cout << " erreur process manque liste de sensibilité"<<endl;
    }
   
     b++;
    // cout<<"on est avant begin du process, b vaut :"<<*b<<endl;
        if(*b !="begin")
        {   
           // cout<<"on detecte begin du process"<<endl;
            i_declaration=tr.append_child(i_process,"declaration");
            i_type_declaration=tr.append_child(i_declaration,*b);
           // cout << "apres declaration variable que vaut b ? :" << *b << endl;
            if(*b=="variable" )
            {
               // cout<<"on detecte declaration de variable"<<endl;
                c=b;
                if(b!=liste.end())
                {
                    c++;
                }
                while(*b=="variable")
                {
                    b++;
                    c=b;
                    if(b!=liste.end())
                    {
                        c++;
                    }

                    if(*c==":")
                    {
                        i_nom_variable=tr.append_child(i_type_declaration,*b);                                
                        b++;                                
                        b=range_variable(b,tr,i_nom_variable);
                        if(*b==";")
                        {
                            b++;
                        }
                        else
                        {
                            cout<<"erreur architecture, process : manque ';' dans la declaration des variables"<<endl;
                            return b;
                        }
                    }
                    else if (*c==",")
                    {                                    
                        b=range_multi_variables(b,tr,i_nom_variable,i_type_declaration, liste); //retourne le point virgule de la ligne sur laquelle il est
                        b++;
                    }
                } 
            }
        }
 //cout<<"avant instructions séquentielles (apres rangement variables), b vaut : "<<*b<<endl;       
 if(*b=="begin")
 {
     i_range_instructions_sequentielles=tr.append_child(i_process,"instructions_sequentielles");
     b++;
     c=b;
     if(b!=liste.end())
     {
        c++;
     }
     while((*b!="end" && *c!="process")) 
    {
         //cout<<"dans while range instruc seq : "<<*b<<" "<<*c<<endl;
         if(*b=="if")
         {
             i_affectation_conditionnelle=tr.append_child(i_range_instructions_sequentielles,"affectation_conditionnelle");
             b=range_affectation_seq_cond(b,tr,i_affectation_conditionnelle, liste);
         }
         else if(*b=="case")
         {
             
         }
        // cout<<"b :"<<*b<<"c :"<<*c<<endl;
         else if(*c=="<=" || *c==":=")
         {
            //cout<<"on range des affectations séquentielles"<<endl;
            i_affectation=tr.append_child(i_range_instructions_sequentielles,"affectation");
            b=range_affectation(b,tr,i_affectation);
         }
         
        b++;
        c=b;
        if(b!=liste.end())
        {
            c++;
        }
    }
   // cout <<" dans range instr seq b vaut: "<<*b<<endl;
    c++; // b sur point virgule
    c++;
 }
 else
 {
     cout<<"erreur : manque begin dans le process"<<endl;
 }    
    return c;
}