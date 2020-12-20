#include "utils.h"
#include "citizen.h"
#include"ElectionRound.h"

namespace proj
{
	/*citizen::citizen() : name(nullptr), ID(0), birthYear(0), vote(-1), state
	{

	}*/
	
	citizen::citizen(char* _name, int id, State& _state, int _birthYear) : state(_state), ID(id), birthYear(_birthYear)
	{
		ElectionRound::countCitizen++;
		name = utils::my_strdup(_name);
		vote = -1;
	}

	citizen::citizen(istream& in):
	{
		load(in);
	}

	citizen::citizen(const citizen& cit) :state(cit.state), ID(cit.ID), birthYear(cit.birthYear), vote(cit.vote)
	{

		name = utils::my_strdup(cit.name);

	}

	citizen::~citizen()
	{
		delete[] name;
	}

	void citizen::operator=(const citizen& input)
	{
		ID = input.ID;
		state = input.state;
		vote = input.vote;
		name = utils::my_strdup(input.name);
	}
	
	int citizen::getStateId() const
	{
		return state.getNumId();
	}

	int citizen::getVote() const
	{
		return vote;
	}

	int citizen::getBirthYear() const
	{
		return birthYear;
	}

	int citizen::getId() const
	{
		return ID;
	}
	char* citizen::getName() const
	{
		return name;
	}



	bool citizen::setvote(int _vote)
	{
		vote = _vote;
		return true;
	}

	void citizen::load(istream& in)
	{
		in.read(rcastc(&name), sizeof(name));
		in.read(rcastc(ID), sizeof(ID));
		in.read(rcastc(&birthYear), sizeof(name));
		in.read(rcastc(&vote), sizeof(vote));
		state.load(in);
	}
	void citizen::save(ostream& out)const
	{
		out.write(rcastcc(&name), sizeof(name));
		out.write(rcastcc(ID), sizeof(ID));
		out.write(rcastcc(&birthYear), sizeof(name));
		out.write(rcastcc(&vote), sizeof(vote));
		state.save(out);
	}

	ostream& operator<<(ostream& os, const citizen& Citizen)
	{
		os << "citizen name: " << Citizen.getName();
		os << "  ||  citizen ID: " << Citizen.getId();
		os << "  ||  birth year: " << Citizen.getBirthYear();
		os << "  ||  state: " << Citizen.getStateId() << endl;
		return os;
	}


}