#pragma once
#include "Ingatlan.h"
#include <string>

class Lakas :public IIngatlan
{
public:
	Lakas(double terulet, uint8_t szobaSzam, uint8_t lakok, uint64_t nmAr);
	~Lakas() override = default;
	virtual double osszesKoltseg() const override;
	virtual bool bekoltozik(uint8_t bekoltozokszama) = 0;
	uint8_t lakokSzama() const;
	virtual operator std::string() const;

protected:
	double _terulet;
	uint8_t _szobaSzam;
	uint8_t _lakok;
	uint64_t _nmAr;
};

