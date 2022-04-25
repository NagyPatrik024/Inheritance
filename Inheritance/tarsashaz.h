#pragma once
#include <cstdint>
#include <vector>
#include "Ingatlan.h"
#include "lakas.h"
#include "garazs.h"

class Tarsashaz
{
public:
	Tarsashaz(uint8_t maxLakas, uint8_t maxGarazs);
	bool lakasHozzad(Lakas* lakas);
	bool garazsHozzad(Garazs* garazs);
	uint8_t osszesLako() const;
	uint64_t ingatlanErtek() const;
	std::vector<IIngatlan*> getIngatlanok() const;
private:
	std::vector<IIngatlan*> _ingatlanok;
	//std::vector<Lakas> _lakasok;
	//std::vector<Garazs> _garazsok;
	uint8_t _maxLakas;
	uint8_t _maxGarazs;
	uint8_t _counterLakas;
	uint8_t _counterGarazs;
};

