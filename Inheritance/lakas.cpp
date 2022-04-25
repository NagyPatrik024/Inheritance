#include "lakas.h"
#include <sstream>

Lakas::Lakas(double terulet, uint8_t szobaSzam, uint8_t lakok, uint64_t nmAr)
	:_terulet(terulet),
	_szobaSzam(szobaSzam),
	_lakok(lakok),
	_nmAr(nmAr)
{};

double Lakas::osszesKoltseg() const
{
	return _terulet * _nmAr;
}

uint8_t Lakas::lakokSzama() const
{
	return _lakok;
}

Lakas::operator std::string() const
{
	std::ostringstream oss;
	oss << "Terulet: " << _terulet << std::endl;
	oss << "Szobak szama: " << (int)_szobaSzam << std::endl;
	oss << "Lakok szama: " << (int)_lakok << std::endl;
	oss << "nm Ar: " << _nmAr;
	return oss.str();
}

