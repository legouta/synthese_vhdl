/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <algorithm>
#include <string>
#include <iostream>
#include "tree.hh"
#include <list>
#include "fonction.h"

using namespace std;

tree<string> range_arbre(list<string> list_lexem)
{
   list<string>::iterator i=list_lexem.begin();
   tree<string> tr;
   tree<string>::iterator root,i_lib,i_use,i_entity,i_archi;
   string lexem;
   
   tr.clear();

    root=tr.begin();
    i_lib=tr.insert(root,"library");
    i_use=tr.insert(root,"use");
    i_entity=tr.insert(root,"entity");
    i_archi=tr.insert(root,"archi");
    
    
    for(i=list_lexem.begin();i!=(list_lexem.end());i++)
    {
        lexem=*i;
        
        if (lexem=="library")
        {
            i=range_library(i,tr,i_lib);
        }
        
        if (lexem=="use")
        {
            i=range_use(i,tr,i_use);
        }
        
        if (lexem=="entity")
        {
            i=range_entity(i,tr,i_entity);
        }
        
      /*  if (lexem=="architecture")
        {
            i=range_archi(i,tr,i_archi);
        }*/
        
       
    }
     
    
    return tr;
}