#pragma once
#include <iostream>
#include"RepresentativeList.h"
#include "utils.h"
using namespace std;

namespace proj {

  
    //copy constractor 
    RepresentativeList::RepresentativeList(const RepresentativeList& input) 
    {
        RepList = input.RepList;
    }
    //distractor - defulte because the citizens is deleted by elecation round
    RepresentativeList::~RepresentativeList()
    {
    }
   
  

   
   //this function returns the haed of the list
    citizen* RepresentativeList::getHead()const {return *RepList.begin();}
    
   
    //operator = copy input list
   void RepresentativeList::operator=(const RepresentativeList& input)
   {
       RepList = input.RepList;
   }

   //this function prints the wining list using operator<<
   void RepresentativeList::printWininigList(int numOfNodeToPrint) const
   {
       auto itList = RepList.begin();
       int countToPrint = 0;
       while (itList != RepList.end() && countToPrint<= numOfNodeToPrint)
       {
           cout << (**itList) << endl;
       }
   }


  //this function saves the citizens' ID numbers
   void RepresentativeList::save(ostream& out) const
   {
       int temp=RepList.size();
       out.write(rcastcc(&temp), sizeof(int));
       auto itList = RepList.begin();
       while (itList != RepList.end())
       {
           temp = (*itList)->getId();
           out.write(rcastcc(&temp), sizeof(int));
       }
   }

  
   //this function loads the citizen list according to the citizens' ID
   void RepresentativeList::load(istream& in, const CitizenList& currList)
   {
       int size_list;
       in.read(rcastc(&size_list), sizeof(size_list));
       auto itList = RepList.begin();
       int temp;
       for (int i = 0; i < size_list; i++)
       {
           //reading citizen id
           in.read(rcastc(&temp), sizeof(temp));
           // need to think how to get the citizen from the currList
 
       }
   }

  ostream& operator<<(ostream& os, const RepresentativeList& List)
  {
      


      return os;
  }

}