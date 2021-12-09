#include "CFont.h"

#include <iostream>

using namespace std;

bool CFont::initFonts() {
	string path = "Resource/Font/Montserrat-";
	return Bold.loadFromFile(path + "Bold.ttf")
		&& SemiBold.loadFromFile(path + "SemiBold.ttf")
		&& Regular.loadFromFile(path + "Regular.ttf");
}

//CFont* CFont::getInstance() {
//	if (!instance) instance = new CFont;
//	return instance;
//}

CFont::CFont() {
	if (initFonts()) std::cout << "Load font success.";
}
