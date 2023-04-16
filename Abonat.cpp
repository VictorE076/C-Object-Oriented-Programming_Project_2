#include "Abonat.h"

Abonat::Abonat()
{}
Abonat::Abonat(const int id, const std::string& nume, const std::string& cnp, const std::string& nr_telefon, Abonament* Ab)
	:Persoana(id, nume, cnp), nr_telefon(nr_telefon), x(Ab)
{
}
Abonat::Abonat(const Persoana& Pers, const std::string& nr_telefon, Abonament* x)
	:Persoana(Pers), nr_telefon(nr_telefon), x(x)
{
}
Abonat::Abonat(const Abonat& At)
{
	*this = At;
}
Abonat::~Abonat()
{
	if(this->check_heap)
		delete x;
	/// std::cout << "ABONAT Destroyed\n\n\n";
}
//////

void Abonat::Print() 
{
	Persoana::Print();
	std::cout << nr_telefon << "\n";
	x->Print();
}

float Abonat::get_sum_abonat()
{
	return (float)(this->x->get_total_sum());
}

const std::type_info& Abonat::get_type_Abonament() const
{
	return typeid(*x); // Returnam "typeid" pt. valoarea POINTERULUI "x" de tip "Abonament"
}


//// Supraincarcari de operatori:
Abonat& Abonat::operator=(const Abonat& Abt)
{
	this->id = Abt.id;
	this->nume = Abt.nume;
	this->cnp = Abt.cnp;
	this->nr_telefon = Abt.nr_telefon;
	if (typeid(*(Abt.x)) == typeid(Abonament))
		this->x = Abt.x;
	else
		if (dynamic_cast<Abonament_Premium*>(Abt.x) != nullptr)
			this->x = (Abonament_Premium*)Abt.x;
		else
			std::cout << "CANNOT perform CAST!\n";
	return *this;
}

std::istream& operator>>(std::istream& in, Abonat& Abt)
{
	std::cout << "ID-ul abonatului: ";
	in >> Abt.id;
	std::cout << "Numele abonatului: ";
	in >> Abt.nume;
	std::cout << "CNP-ul abonatului: ";
	in >> Abt.cnp;
	std::cout << "Telefon abonat: ";
	in >> Abt.nr_telefon;
	unsigned short choice;
	std::cout << "\n\nDATI INFO DESPRE TIPUL DE ABONAMENT ALES\n";
	std::cout << "APASATI 1 pentru un abonat cu abonament(normal), respectiv 2 pentru un abonat cu abonament(premium): ";
	in >> choice;
	std::cout << "\n";
	if (choice == 1)
	{
		Abt.x = new Abonament();
		in >> *Abt.x;
		Abt.check_heap = true;
		std::cout << "\n\n";
		return in;
	}	
	else if (choice == 2)
	{
		Abt.x = new Abonament_Premium();
		if(dynamic_cast<Abonament_Premium*>(Abt.x) != nullptr)
			in >> *(Abonament_Premium*)Abt.x;
		else
			std::cout << "CANNOT perform CAST!\n";
		Abt.check_heap = true;
		std::cout << "\n\n";
		return in;
	}	
	else
	{
		std::cout << "INVALID INPUT\n";
		throw choice;
	}
}

std::ostream& operator<<(std::ostream& out, const Abonat& Abt)
{
	out << "Abonatul:\n";
	out << "ID: " << Abt.id << ", Nume: " << Abt.nume << ", CNP: " << Abt.cnp << ", Telefon: " << Abt.nr_telefon;
	std::cout << "\n\nINFORMATII DESPRE TIPUL DE ABONAMENT ALES:\n";
	if (typeid(*(Abt.x)) == typeid(Abonament))
		out << *(Abt.x);
	else
		if (dynamic_cast<Abonament_Premium*>(Abt.x) != nullptr)
			out << *(Abonament_Premium*)Abt.x;
		else
			out << "CANNOT perform CAST!\n";
	return out;
}