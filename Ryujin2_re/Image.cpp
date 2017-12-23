#include "Image.h"
#include <DxLib.h>

Image::Image() {
	_player = myLoadGraph("./dat/image/player/body/seishi0.png");
	_board = myLoadGraph("./dat/image/board/board.png");
	_backspell00 = myLoadGraph("./dat/image/background/01spell/00.png");
	_backspell01 = myLoadGraph("./dat/image/background/01spell/01.png");
	_fusuma = myLoadGraph("./dat/image/background/01/fusuma.png");
	_floor = myLoadGraph("./dat/image/background/01/floor.png");
}

/*!
@brief 今までロードした画像を開放する
*/
void Image::release(){
	const int size = _images.size();

	for (int i = 0; i < size; i++)
		DeleteGraph(_images[i]);
	
	_images.clear();
}

/*!
@brief プレイヤーの画像を取得する
*/
int Image::getPlayer() const
{
	return _player;
}

/*!
@brief ボードの画像を取得する
*/
int Image::getBoard() const
{
	return _board;
}

/*!
@brief Background00の画像を取得する
*/
int Image::getBackSpell00() const {
	return _backspell00;
}

/*!
@brief Background01の画像を取得する
*/
int Image::getBackSpell01() const {
	return _backspell01;
}

int Image::getFusuma() const{
	return _fusuma;
}

int Image::getFloor() const {
	return _floor;
}

/*!
@brief LoadGraphをして、かつそのハンドルをメンバ変数に追加する
*/
int Image::myLoadGraph(char * fileName)
{
	int ret = LoadGraph(fileName);
	_images.push_back(ret);
	return ret;
}

/*!
@brief LoadDivGraphをして、かつそのハンドルをメンバ変数に追加する
*/
int Image::myLoadDivGraph(char * fileName, int n, int xn, int yn, int w, int h, int * buf)
{
	int ret = LoadDivGraph(fileName, n, xn, yn, w, h, buf);

	for (int i = 0; i < n; i++)
		_images.push_back(buf[i]);
	
	return ret;
}
