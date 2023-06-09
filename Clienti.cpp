#include "Clienti.h"

Clienti::Clienti(){}
Clienti::Clienti(const Clienti& cli)
{
	*this = cli;
}
Clienti::Clienti(const std::vector<Abonat*>& abonati)
	:abonati(abonati)
{}
Clienti::~Clienti()
{
	if (check_heap_Cl)
	{
		const unsigned temp_sz = abonati.size();
		for (int i = 0; i < temp_sz; i++)
		{
			delete abonati[i];
		}
	}
	/// std::cout << "CLIENTI Destroyed\n\n\n";
}

//
unsigned Clienti::get_nr_Ab()
{
	if (this->abonati.empty())
		return 0;
	return this->abonati.size() - get_nr_Ab_Premium();
}
unsigned Clienti::get_nr_Ab_Premium()
{
	if(this->abonati.empty())
		return 0;
	unsigned sz = this->abonati.size();
	unsigned nr_ab_premium = 0;
	for (int i = 0; i < sz; i++)
	{
		if (this->abonati[i]->get_type_Abonament() == typeid(Abonament_Premium))
		{
			nr_ab_premium++;
		}
	}
	return nr_ab_premium;
}
float Clienti::total_sum_ab()
{
	unsigned sz = this->abonati.size();
	float sum_ab = 0;
	for (int i = 0; i < sz; i++)
	{
		sum_ab += (float)(this->abonati[i]->get_sum_abonat());
	}
	return sum_ab;
}
//
//////

void Clienti::Push_Abonat(Abonat* Abt)
{
	abonati.push_back(Abt);
}

void Clienti::Print() const
{
	const unsigned sz = abonati.size();
	std::cout << "\n----------------AFISAREA TUTUROR ABONATILOR------------------\n\n";
	for (int i = 0; i < sz; i++)
	{
		std::cout << "ABONATUL nr." << (i + 1) << ":\n";
		abonati[i]->Print();
	}
}

Clienti& Clienti::operator=(const Clienti& Cl)
{
	this->abonati = Cl.abonati;
	return *this;
}

std::istream& operator>>(std::istream& in, Clienti& Cl)
{
	std::cout << "DATI NR. DE ABONATI: ";
	unsigned num;
	in >> num;
	std::cout << "\n\n";
	Cl.check_heap_Cl = true;
	Abonat* a;
	for (int i = 0; i < num; i++)
	{
		std::cout << "Abonatul nr. " << (i + 1) << ":\n";
		a = new Abonat();
		try
		{
			in >> *a;
		}
		catch (unsigned short chc)
		{
			std::cout << "ERROR: " << chc << " is NOT VALID (THE PROGRAM STOPPED)!\n\n";
			exit(-987);
		}
		catch (...)
		{
			std::cout << "ERROR: NOT A VALID CHOICE (THE PROGRAM STOPPED)!\n\n";
			exit(-404);
		}
		
		Cl.abonati.push_back(a);
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Clienti& Cl)
{
	const unsigned sz = Cl.abonati.size();
	out << "\n----------------OUTPUT ABONATI------------------\n\n";
	for (int i = 0; i < sz; i++)
	{
		out << "ABONATUL nr. " << (i + 1) << ":\n";
		out << *(Cl.abonati[i]);
	}
	return out;
}
