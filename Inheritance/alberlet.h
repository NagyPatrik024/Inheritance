#pragma once
#include "lakas.h"
#include "Berelheto.h"

class Alberlet : public Lakas, IBerelheto
{
public:
	~Alberlet() override = default;
	Alberlet(double terulet, uint8_t szobaSzam, uint64_t nmAr);

	virtual bool bekoltozik(uint8_t bekoltozokszama) override;
	virtual operator std::string() const override;

	// Inherited via IBerelheto
	virtual uint64_t mennyibeKerul(uint8_t honapokszama) const override;
	virtual bool lefoglaltE() const override;
	virtual bool lefoglal(uint8_t honapokszama) override;

private:
	uint8_t _honapSzam;

	// Inherited via Lakas

};

