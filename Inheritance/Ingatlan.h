#pragma once
#include <cstdint>

class IIngatlan
{
public:
	virtual ~IIngatlan() = default;
	virtual double osszesKoltseg() const = 0;
};