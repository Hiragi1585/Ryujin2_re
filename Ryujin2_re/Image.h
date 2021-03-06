#pragma once

#include "Singleton.h"
#include <vector>

class Image final : public Singleton<Image> {
public:
	Image();
	~Image() = default;
	void load() {}
	void release();

	int getPlayer() const { return _player; }
	int getBoard() const { return _board; }
	int getFusuma() const { return _fusuma; }
	int getFloor() const { return _floor; }
	int getBackSpell00() const { return _backspell00; }
	int getBackSpell01() const { return _backspell01; }
	const int* getEnemyNormal() const { return _enemyNormal; }

private:
	int myLoadGraph(char* fileName);
	int myLoadDivGraph(char *fileName, int n, int xn, int yn, int w, int h, int* buf);

	std::vector<int> _images;
	int _player;
	int _board;
	int _backspell00;
	int _backspell01;
	int _fusuma;
	int _floor;
	int _enemyNormal[9];

};