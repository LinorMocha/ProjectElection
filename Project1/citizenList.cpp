
#include "citizenList.h"
#include "utils.h"
#include "ElectionRound.h"
namespace proj
{
    //copy constractor 
    CitizenList::CitizenList(const CitizenList& input)
    {
        List = input.List;
    }

    //distractor - defulte because the citizens is deleted by elecation round
    CitizenList::~CitizenList()
    {
        auto itList = List.begin();
        auto temp=itList;
        while (temp != List.end())
        {
            temp++;
            delete (*itList);
            itList = temp;
        }
    }

    //operator = copy input list
    const CitizenList& CitizenList::operator=(const  CitizenList& input)  {
        List = input.List;
        return *this;
    }

    bool CitizenList::isEmpty()  { return List.empty();  }

    //this function add citizen to the end of the list
    void  CitizenList::addCitizenToListTail(const string _name, int id, State& citState, int _birthYear) {
         if (getCitizenById(id)!=nullptr)
            throw invalid_argument("the citizen is alredy exsict");
         citizen* newC;
         try {
             newC = new citizen(_name, id, citState, _birthYear);
         }
         catch (std::exception& ex) {
             throw ex;
         }
         List.push_back(newC);
   }

    //this function add citizen to the elected place in the list
    void  CitizenList::addCitizenAfter(const citizen* to_insert, citizen* input)  {
        auto itList = std::find(List.begin(), List.end(), to_insert);
        List.insert(itList, input);
    }

    //this func returns pointer to citizen according to given ID number
    citizen* CitizenList::getCitizenById(int _id)const  {
        
        //auto itList = List.begin();
        auto cit = utils::Find(List.begin(), List.end(), _id);

        if (cit != List.end())
            return *cit;
        
        /*int temp;
        while (itList != List.end())
        {
            temp = (*itList)->getId();
            if (_id == temp)
                return *itList;
        }*/
        return nullptr;
    }

    //this function returns the size of list
    int  CitizenList::getListSize() const { return List.size(); }

 

    //this function saves the citizens' ID numbers
    void  CitizenList::save(ostream& out) const  {
        int temp = List.size();
        out.write(rcastcc(&temp), sizeof(int));
        auto itList = List.begin();
        while (itList != List.end())
        {
            try {
                (*itList)->save(out);
            }
            catch (exception& ex) {
                throw ex;
            }
        
        }
    }

    //this function load the citizen
   
    void  CitizenList::load(istream& in, DynamicArray<State*>& current) {
        int size_list;
        in.read(rcastc(&size_list), sizeof(size_list));
        int tempIdState;
        citizen* newCit;
        for (int i = 0; i < size_list; i++)
        {
            in.read(rcastc(&tempIdState), sizeof(tempIdState));
            
            auto sta = utils::Find(current.begin(), current.end(), tempIdState);
            try {
                newCit = new citizen(in, (State&)sta);
            }
            catch (exception& ex)
            {
                throw ex;
            }
        }
    }

    //cheak if citizen is in the list
    void  CitizenList::isCitizenInList(const citizen& cit)  {
        auto it = utils::Find(List.begin(), List.end(), cit);
        if (it != List.end())
            throw invalid_argument("citizen is in list");
    }



    ostream& operator<<(ostream& os, const CitizenList& _List)  {
       
        auto itList = _List.List.begin();
        cout << "list size" << _List.getListSize() << endl;
        for (int i = 0; i < _List.getListSize(); i++)
        {
            cout << (**itList) << endl;
            itList++;
        }
        return os;
    }
}