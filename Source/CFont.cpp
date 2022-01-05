#include "../Header/CFont.h"

#include <iostream>

CFont* CFont::instance = nullptr;

CFont::CFont() {
	if (initFonts()) std::cout << "LOAD FONT SUCCESS" << std::endl;
	else std::cout << "LOAD FONT FAILED" << std::endl;
}

bool CFont::initFonts() {
	std::string path = "Resource/Font/";
	std::string mon_path = path + "Montserrat-";
	return Bold.loadFromFile(mon_path + "Bold.ttf")
		&& SemiBold.loadFromFile(mon_path + "SemiBold.ttf")
		&& Regular.loadFromFile(mon_path + "Regular.ttf")
		&& ArialRounded.loadFromFile(path + "Arial Rounded MT Bold.ttf");
}

CFont* CFont::getInstance() {
	if (!instance) instance = new CFont;
	return instance;
}

CFont::~CFont() { delete instance; instance = nullptr; }