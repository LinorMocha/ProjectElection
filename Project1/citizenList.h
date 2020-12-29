#pragma once
#include <iostream>
#include "citizen.h"
#include "StateArray.h"

using namespace std;
namespace proj
{
    struct node
    {
        citizen* value;
        node* next;
        node* prev;
    };
    

    class citizenList
    {
    private:
        node* head,*tail;
        int listSize;
    public:
        citizenList();
        ~citizenList();
        citizenList(const citizenList& input);
      
        void operator=(const citizenList& input);

        ///// GETERS ////
        citizen* getCitizenById(int _id) const;
        node* getHead()const;
        int getListSize()const;

      

        void addNodeToTail(citizen* input);
        void addNodeToHead(citizen* input);
        void printList()const ;
        void printList(int numOfNodeToPrint)const;
    
        bool save(ostream& out)const;
        bool load(istream& in, const StateArray& staecur);


        //// FOR REPRESENTATIVE LIST ///
        void loadById(istream& in, const citizenList& currList);
        void saveById(ostream& out) const;
       
    };
}