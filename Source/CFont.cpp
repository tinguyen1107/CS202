#include "../Header/CFont.h"

#include <iostream>

bool CFont::initFonts() {
	std::string path = "Resource/Font/Montserrat-";
	return Bold.loadFromFile(path + "Bold.ttf")
		&& SemiBold.loadFromFile(path + "SemiBold.ttf")
		&& Regular.loadFromFile(path + "Regular.ttf");
}

//CFont* CFont::getInstance() {
//	if (!instance) instance = new CFont;
//	return instance;
//}

CFont::CFont() {
	if (initFonts()) std::cout << "Load font success." << std::endl;
	else std::cout << "Load font failed" << std::endl;
}
