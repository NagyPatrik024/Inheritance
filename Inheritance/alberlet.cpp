#include "alberlet.h"
#include <sstream>

Alberlet::Alberlet(double terulet, uint8_t szobaSzam, uint64_t nmAr)
	:Lakas(terulet, szobaSzam, 0, nmAr),
	_honapSzam(0)
{}
bool Alberlet::bekoltozik(uint8_t bekoltozokszama)
{
	if ((_lakok + bekoltozokszama) / _szobaSzam <= 8 && _terulet / (_lakok + bekoltozokszama) >= 2)
	{
		_lakok += bekoltozokszama;
		return true;
	}
	return false;
}
uint64_t Alberlet::mennyibeKerul(uint8_t honapokszama) const
{
	if (_lakok < 1)
	{
		return 1;
	}
	return (osszesKoltseg() / _lakok) * honapokszama;

}
bool Alberlet::lefoglaltE() const
{
	if (_honapSzam < 1)
	{
		return false;
	}
	return true;
}
bool Alberlet::lefoglal(uint8_t honapokszama)
{
	if (!lefoglaltE())
	{
		_honapSzam = honapokszama;
		return true;
	}
	return false;
}

Alberlet::operator std::string() const
{
	std::ostringstream oss;
	oss << "Alberlet"<< std::endl;
	oss << Lakas::operator std::string() << std::endl;
	oss << "Honapok szama: " << (int)_honapSzam;
	return oss.str();
}
