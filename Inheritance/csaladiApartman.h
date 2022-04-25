#pragma once
#include "lakas.h"

class CsaladiApartman : public Lakas
{
public:
	~CsaladiApartman() override = default;
	CsaladiApartman(double terulet, uint8_t szobaSzam, uint64_t nmAr);

	bool gyerekSzuletik();
	virtual bool bekoltozik(uint8_t bekoltozokszama) override;
	virtual operator std::string() const override;
private:
	uint8_t _gyerekekSzama;
};

