#pragma once

#include "Singleton.h"
#include <vector>

class Image final : public Singleton<Image> {
public:
	Image();
	~Image() = default;
	void load() {}
	void release();

	int getPlayer() const;
	int getBoard() const;
	int getBackSpell00() const;
	int getBackSpell01() const;
	int getFusuma() const;
	int getFloor() const;

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

};