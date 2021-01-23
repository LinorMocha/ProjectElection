
#include "citizen.h"
#include "ElectionRound.h"


namespace proj
{
	citizen::citizen(State* sta):state(*sta)
	{
	}
	//ctor
	citizen::citizen(const string _name, int id, State& _state, int _birthYear) :name(_name), state(_state), birthYear(_birthYear)
	{
		if (id < 100000000 || id>999999999)
			throw invalid_argument("id not valid ");
		ID = id;
		ElectionRound::countCitizen++;
		vote = -1;

	}

	//serialize constractor of citizen
	citizen::citizen(istream& in,State* sta): state(*sta)
	{
		load(in);
	}
	//ctor
	citizen::citizen(const citizen& cit) :name(cit.name),state(cit.state), ID(cit.ID), birthYear(cit.birthYear), vote(cit.vote){
		
	}
	
	//dctor
	citizen::~citizen(){  }
	
	const citizen& citizen::operator=(const citizen& input)
	{
		ID = input.ID;
		state = input.state;
		vote = input.vote;
		name = input.name;
		return *this;
	}
	bool citizen::operator==(int id)
	{
		return ID == id;
	}
	bool citizen::operator==(const citizen& input)
	{
		if (ID == input.ID && state == input.state && vote == input.vote &&
			name == input.name)
			return true;
		return false;
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
	const string citizen::getName() const
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
	void citizen::save(ostream& out)const
	{
		int temp = state.getNumId();
		out.write(rcastcc(&temp), sizeof(int));
		out.write(rcastcc(&ID), sizeof(ID));
		out.write(rcastcc(&birthYear), sizeof(name));
		out.write(rcastcc(&vote), sizeof(vote));
		int len = name.length();
		out.write(rcastcc(&len), sizeof(int));
		out.write(rcastcc(name.c_str()), len);
		
		if(!out.good()) //Checks if the writes operations to file performed properly
			throw invalid_argument("save citizen to file didn't preforemd proprtaly");

	}
	//This function reads the citizen data from binary file
	void citizen::load(istream& in)
	{
		in.read(rcastc(&ID), sizeof(ID));
		in.read(rcastc(&birthYear), sizeof(name));
		in.read(rcastc(&vote), sizeof(vote));
		int len;
		in.read(rcastc(&len), sizeof(len));
		if (!in.good())//check len reading from file
			throw invalid_argument("load citizen to file didn't preforemd proprtaly");
		
		name.resize(len);
		in.read((char*)&name[0], len);
		if(!in.good())
			throw invalid_argument("load citizen to file didn't preforemd proprtaly");
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