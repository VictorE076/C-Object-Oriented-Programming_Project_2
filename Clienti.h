#pragma once
#include "Abonat.h"

class Clienti
{
private:
	bool check_heap_Cl = false;
	std::vector<Abonat*> abonati;
public:
	Clienti();
	Clienti(const Clienti& cli);
	Clienti(const std::vector<Abonat*>& abonati);
	virtual ~Clienti();
	//////
	//
	unsigned get_nr_Ab();
	unsigned get_nr_Ab_Premium();
	float total_sum_ab();
	//
	void Push_Abonat(Abonat* Abt);
	virtual void Print() const;

	//// Supraincarcari de operatori:
	Clienti& operator=(const Clienti& Cl);
	friend std::istream& operator>>(std::istream& in, Clienti& Cl);
	friend std::ostream& operator<<(std::ostream& out, const Clienti& Cl);
};
