#include <iostream>
#include <fstream>
#include <sstream> 
#include "hazmester.h"
#include "tarsashaz.h"
#include "alberlet.h"
#include "csaladiApartman.h"

void Hazmester::karbantart(std::string path)
{
	auto t = new Tarsashaz(5, 2);

	std::ifstream inputFile(path);
	while (!inputFile.eof())
	{
		std::string line;
		std::getline(inputFile, line);
		auto pos = line.find(' ');
		const auto word = line.substr(0, pos);

		if (word == "Alberlet")
		{
			line = line.substr(pos + 1);
			std::vector<std::string> internal;
			std::stringstream ss(line); // Turn the string into a stream. 
			std::string tok;

			while (std::getline(ss, tok, ' ')) {
				internal.push_back(tok);
			}
			t->lakasHozzad(new Alberlet(static_cast<double>(stod(internal[0])), static_cast<uint8_t>(stoi(internal[1])), static_cast<uint64_t>(stoi(internal[2]))));
		}
		else if (word == "CsaladiApartman")
		{
			line = line.substr(pos + 1);
			std::vector<std::string> internal;
			std::stringstream ss(line); // Turn the string into a stream. 
			std::string tok;

			while (std::getline(ss, tok, ' ')) {
				internal.push_back(tok);
			}
			t->lakasHozzad(new CsaladiApartman(static_cast<double>(stod(internal[0])), static_cast<uint8_t>(stoi(internal[1])), static_cast<uint64_t>(stoi(internal[2]))));
		}
		else if (word == "Garazs")
		{
			line = line.substr(pos + 1);
			std::vector<std::string> internal;
			std::stringstream ss(line); // Turn the string into a stream. 
			std::string tok;

			while (std::getline(ss, tok, ' ')) {
				internal.push_back(tok);
			}

			t->garazsHozzad(new Garazs(static_cast<double>(stod(internal[0])), static_cast<uint64_t>(stoi(internal[1])), internal[2] == "futott" ? true : false));
		}

	}
	for (size_t i = 0; i < t->getIngatlanok().size(); i++)
	{
		if (dynamic_cast<Alberlet*>(t->getIngatlanok()[i]))
		{
		
			dynamic_cast<Alberlet*>(t->getIngatlanok()[i])->lefoglal(10);
			dynamic_cast<Alberlet*>(t->getIngatlanok()[i])->bekoltozik(2);
			std::cout << dynamic_cast<Alberlet*>(t->getIngatlanok()[i])->operator std::string() << std::endl;
			std::cout << "Lefolglalt?: " << (dynamic_cast<Alberlet*>(t->getIngatlanok()[i])->lefoglaltE() ? "Igen" : "Nem") << std::endl;
			std::cout << "Mennyibe kerul 3 honapra: " << (int)dynamic_cast<Alberlet*>(t->getIngatlanok()[i])->mennyibeKerul(3) << std::endl;
			std::cout << "Erteke: " << (int)dynamic_cast<Alberlet*>(t->getIngatlanok()[i])->osszesKoltseg() << std::endl;
			std::cout << std::endl;

		}
		else if (dynamic_cast<CsaladiApartman*>(t->getIngatlanok()[i]))
		{
			dynamic_cast<CsaladiApartman*>(t->getIngatlanok()[i])->bekoltozik(2);
			dynamic_cast<CsaladiApartman*>(t->getIngatlanok()[i])->gyerekSzuletik();
			std::cout << dynamic_cast<CsaladiApartman*>(t->getIngatlanok()[i])->operator std::string() << std::endl;
			std::cout << "Erteke: " << (int)dynamic_cast<CsaladiApartman*>(t->getIngatlanok()[i])->osszesKoltseg() << std::endl;
			std::cout << std::endl;

		}
		else if (dynamic_cast<Garazs*>(t->getIngatlanok()[i]))
		{
			dynamic_cast<Garazs*>(t->getIngatlanok()[i])->lefoglal(5);
			dynamic_cast<Garazs*>(t->getIngatlanok()[i])->autoKiBeAll();
			std::cout << dynamic_cast<Garazs*>(t->getIngatlanok()[i])->operator std::string() << std::endl;
			std::cout << "Mennyibe kerul 3 honapra?: " << dynamic_cast<Garazs*>(t->getIngatlanok()[i])->mennyibeKerul(3) << std::endl;
			std::cout << "Erteke: " << (int)dynamic_cast<Garazs*>(t->getIngatlanok()[i])->osszesKoltseg() << std::endl;
			std::cout << std::endl;
		}

	}
	std::cout << std::endl;
	std::cout << "Osszertek: " << t->ingatlanErtek();
}


