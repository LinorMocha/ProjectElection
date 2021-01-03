
#include "citizen.h"
#include "ElectionRound.h"


namespace proj
{
	/*citizen::citizen() : name(nullptr), ID(0), birthYear(0), vote(-1), state
	{

	}*/
	//ctor
	citizen::citizen(const char* _name, int id, State& _state, int _birthYear) : state(_state), ID(id), birthYear(_birthYear)
	{
		ElectionRound::countCitizen++;
		name = utils::my_strdup(_name);
		vote = -1;
	}
	//serialize constractor of citizen
	citizen::citizen(istream& in,State& sta): state(sta)
	{
		load(in);
	}
	//ctor
	citizen::citizen(const citizen& cit) :state(cit.state), ID(cit.ID), birthYear(cit.birthYear), vote(cit.vote)
	{

		name = utils::my_strdup(cit.name);

	}
	//dctor
	citizen::~citizen()
	{
		delete[] name;
	}
	
	const citizen& citizen::operator=(const citizen& input)
	{
		ID = input.ID;
		state = input.state;
		vote = input.vote;
		delete[] name;
		name = utils::my_strdup(input.name);
		return *this;
	}
	//This function returns the state's ID number
	int citizen::getStateId() const
	{
		return state.getNumId();
	}
	//This function returns the citizen's voting status
	int citizen::getVote() const
	{
		return vote;
	}
	//This function returns the birth year of the citizen
	int citizen::getBirthYear() const
	{
		return birthYear;
	}
	//This function returns the citizen's ID number
	int citizen::getId() const
	{
		return ID;
	}
	//This function returns the name of the citizen
	const char* citizen::getName() const
	{
		return name;
	}


	//This function sets the citizen's vote
	bool citizen::setvote(int _vote)
	{
		vote = _vote;
		return true;
	}
	//This function writes the citizen data to binary file
	bool citizen::save(ostream& out)const
	{
		if (!out) //checks if the file works properly
		{
			return false; 
		}
		int temp = state.getNumId();
		out.write(rcastcc(&temp), sizeof(int));
		out.write(rcastcc(&ID), sizeof(ID));
		out.write(rcastcc(&birthYear), sizeof(name));
		out.write(rcastcc(&vote), sizeof(vote));
		int len = utils::myStrlen(name);
		out.write(rcastcc(&len), sizeof(len));
		out.write(name,len);
		return(out.good()); //Checks if the writes operations to file performed properly
	}
	//This function reads the citizen data from binary file
	bool citizen::load(istream& in)
	{
		if (!in)//checks if the file works properly
		{
			return false;
		}
		in.read(rcastc(&ID), sizeof(ID));
		in.read(rcastc(&birthYear), sizeof(name));
		in.read(rcastc(&vote), sizeof(vote));
		int len;
		in.read(rcastc(&len), sizeof(len));
		if(!in.good())//check len reading from file
		{
			return false;
		}
		len++;
		name = new char[len];
		in.read(name, len-1);
		if (!in.good()) //check name reading from file
		{
			return false;
		}
		name[len - 1] = '\0';
		return true;
		
	}
	// This function prints the information of the curr citizen 
	ostream& operator<<(ostream& os, const citizen& Citizen)
	{
		os << "citizen name: " << Citizen.getName();
		os << "  ||  citizen ID: " << Citizen.getId();
		os << "  ||  birth year: " << Citizen.getBirthYear();
		os << "  ||  state: " << Citizen.getStateId() << endl;
		return os;
	}


}