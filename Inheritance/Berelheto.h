#pragma once
#include <cstdint>

class IBerelheto
{

public:
	virtual ~IBerelheto() = default;
	virtual uint64_t mennyibeKerul(uint8_t honapokszama) const = 0;
	virtual bool lefoglaltE() const = 0;
	virtual bool lefoglal(uint8_t honapokszama) = 0;
};