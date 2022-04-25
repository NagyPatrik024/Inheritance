#include "csaladiApartman.h"
#include <sstream>

CsaladiApartman::CsaladiApartman(double terulet, uint8_t szobaSzam, uint64_t nmAr)
	:Lakas(terulet, szobaSzam, 0, nmAr),
	_gyerekekSzama(0)
{}

bool CsaladiApartman::gyerekSzuletik()
{
	if (_lakok - _gyerekekSzama >= 2)
	{
		_gyerekekSzama++;
		_lakok++;
		return true;
	}
	return false;
}

bool CsaladiApartman::bekoltozik(uint8_t bekoltozokszama)
{
	uint8_t felnottek = _lakok - _gyerekekSzama;
	if ((_lakok + bekoltozokszama) / _szobaSzam <= 2 && _terulet / ((felnottek + bekoltozokszama) + (_gyerekekSzama * 0.5)) >= 10)
	{
		_lakok += bekoltozokszama;
		return true;
	}
	return false;
}

CsaladiApartman::operator std::string() const
{
	std::ostringstream oss;
	oss << "CsaladiApartman" << std::endl;
	oss << Lakas::operator std::string() << std::endl;
	oss << "Gyerekek szama: " << (int)_gyerekekSzama;
	return oss.str();
}
