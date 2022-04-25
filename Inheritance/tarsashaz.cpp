#include "tarsashaz.h"
#include "alberlet.h"
#include <algorithm>

Tarsashaz::Tarsashaz(uint8_t maxLakas, uint8_t maxGarazs)
	:_maxLakas(maxLakas),
	_maxGarazs(maxGarazs),
	_counterGarazs(0),
	_counterLakas(0),
	_ingatlanok(std::vector<IIngatlan*>())
{
}

bool Tarsashaz::lakasHozzad(Lakas* lakas)
{
	if (_counterLakas <= _maxLakas)
	{
		_ingatlanok.push_back(lakas);
		_counterLakas++;
		return true;
	}
	return false;
}

bool Tarsashaz::garazsHozzad(Garazs* garazs)
{
	if (_counterGarazs <= _maxGarazs)
	{
		_ingatlanok.push_back(garazs);
		_counterGarazs++;
		return true;
	}
	return false;
}

uint8_t Tarsashaz::osszesLako() const
{
	uint8_t sum = 0;
	for (size_t i = 0; i < _ingatlanok.size(); i++)
	{
		if (dynamic_cast<Lakas*>(_ingatlanok[i]))
		{
			sum += dynamic_cast<Lakas*>(_ingatlanok[i])->lakokSzama();
		}
	}
	return sum;
}

uint64_t Tarsashaz::ingatlanErtek() const
{
	uint64_t sum = 0;
	for (size_t i = 0; i < _ingatlanok.size(); i++)
	{
		if (dynamic_cast<Lakas*>(_ingatlanok[i]))
		{

			if (dynamic_cast<Lakas*>(_ingatlanok[i])->lakokSzama() >= 1)
			{
				sum += dynamic_cast<Lakas*>(_ingatlanok[i])->osszesKoltseg();
			}

		}
		else if (dynamic_cast<Garazs*>(_ingatlanok[i]))
		{
			if (dynamic_cast<Garazs*>(_ingatlanok[i])->lefoglaltE() == true)
			{
				sum += dynamic_cast<Garazs*>(_ingatlanok[i])->osszesKoltseg();
			}
		}
	}
	return sum;
}

std::vector<IIngatlan*> Tarsashaz::getIngatlanok() const
{
	return _ingatlanok;
}
