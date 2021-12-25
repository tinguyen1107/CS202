#include "..\Header\CPlayGround.h"

CPlayground* CPlayground::instance = nullptr;

CPlayground::CPlayground() {}

CPlayground& CPlayground::getInstance() {
	if (!instance) instance = new CPlayground;
	return *instance;
}

CPlayground::~CPlayground() {
	delete instance;
}