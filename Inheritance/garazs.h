#pragma once
#include "Ingatlan.h"
#include "Berelheto.h"
#include <string>

class Garazs :public IIngatlan, IBerelheto
{
public:
	~Garazs() override = default;
	Garazs(double terulet, uint64_t nmAr, bool futottE);
	Garazs& autoKiBeAll();
	virtual operator std::string() const;

	// Inherited via IIngatlan
	virtual double osszesKoltseg() const override;

	// Inherited via IBerelheto
	virtual uint64_t mennyibeKerul(uint8_t honapokszama) const override;
	virtual bool lefoglaltE() const override;
	virtual bool lefoglal(uint8_t honapokszama) override;
private:
	double _terulet;
	uint64_t _nmAr;
	bool _futottE;
	uint8_t _honapSzam;
	bool _auto;

	
};

