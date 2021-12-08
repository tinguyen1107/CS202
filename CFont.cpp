#include "CFont.h"

void CFont::initFonts()
{
	if (SemiBold.loadFromFile(path + "SemiBold.ttf")) std::cout << "Success";
	else std::cout << "Fail";
}

CFont::CFont()
{
	initFonts();
}
