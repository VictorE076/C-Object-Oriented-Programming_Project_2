#pragma once
#include "Persoana.h"

class Abonat : public Persoana
{
private:
	bool check_heap = false;
	std::string nr_telefon;
	Abonament* x;
public:
	Abonat();
	Abonat(const int id, const std::string& nume, const std::string& cnp, const std::string& nr_telefon, Abonament* Ab);
	Abonat(const Persoana& Pers, const std::string& nr_telefon, Abonament* x);
	Abonat(const Abonat& At);
	~Abonat();
	//////
	void Print() override;
	float get_sum_abonat();
	const std::type_info& get_type_Abonament() const;

	//// Supraincarcari de operatori:
	Abonat& operator=(const Abonat& Abt);
	friend std::istream& operator>>(std::istream& in, Abonat& Abt);
	friend std::ostream& operator<<(std::ostream& out, const Abonat& Abt);
};
