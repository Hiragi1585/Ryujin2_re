#include <DxLib.h>
#include "Define.h"
#include "Board.h"
#include "Image.h"

Board::Board()
{
	_x = Define::OUT_W;
	_y = 0;
}

bool Board::update()
{
	return true;
}

void Board::draw() const
{
	DrawGraph(_x, _y, Image::getIns()->getBoard(), true);
	DrawBox(Define::IN_X, Define::IN_Y, Define::OUT_W-Define::IN_X, Define::OUT_H-Define::IN_Y, GetColor(32, 64, 128), false);
}
