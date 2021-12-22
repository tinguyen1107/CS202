#include "../Header/CFont.h"

#include <iostream>

CFont* CFont::instance = nullptr;

CFont::CFont() {
	if (initFonts()) std::cout << "LOAD FONT SUCCESS" << std::endl;
	else std::cout << "LOAD FONT FAILED" << std::endl;
}

bool CFont::initFonts() {
	std::string path = "Resource/Font/Montserrat-";
	return Bold.loadFromFile(path + "Bold.ttf")
		&& SemiBold.loadFromFile(path + "SemiBold.ttf")
		&& Regular.loadFromFile(path + "Regular.ttf");
}

CFont* CFont::getInstance() {
	if (!instance) instance = new CFont;
	return instance;
}

CFont::~CFont() { delete instance; instance = nullptr; }