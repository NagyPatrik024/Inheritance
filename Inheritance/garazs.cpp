#include "garazs.h"
#include <sstream>

Garazs::Garazs(double terulet, uint64_t nmAr, bool futottE)
	:_terulet(terulet),
	_nmAr(nmAr),
	_futottE(futottE),
	_auto(false),
	_honapSzam(0)
{}

Garazs& Garazs::autoKiBeAll()
{
	_auto = !_auto;
	return *this;
}

double Garazs::osszesKoltseg() const
{
	return _terulet * _nmAr;
}

uint64_t Garazs::mennyibeKerul(uint8_t honapokszama) const
{
	if (_futottE)
	{
		return osszesKoltseg() * honapokszama * 1.5;
	}
	return osszesKoltseg() * honapokszama;
}

bool Garazs::lefoglaltE() const
{
	return _honapSzam || _auto > 0 ? true : false;
}

bool Garazs::lefoglal(uint8_t honapokszama)
{
	if (!lefoglaltE())
	{
		_honapSzam = honapokszama;
		return true;
	}
	return false;
}

Garazs::operator std::string() const
{
	std::ostringstream oss;
	oss << "Garazs" << std::endl;
	oss << "Terulet: " << _terulet << std::endl;
	oss << "Futott-e: " << (_futottE? "Igen" : "Nem") << std::endl;
	oss << "nm Ar: " << _nmAr << std::endl;
	oss << "Bent all az auto?: " << (_auto ? "Igen" : "Nem") << std::endl;
	oss << "Honapok szama: " << (int)_honapSzam;
	return oss.str();
}
