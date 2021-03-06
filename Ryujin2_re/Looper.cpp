#include "Looper.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "Error.h"
#include "Macro.h"
#include "Keyboard.h"
#include "Pad.h"
#include "Image.h"
using namespace std;


Looper::Looper() {
	Image::getIns()->load();

	Parameter parameter;
	_sceneStack.push(make_shared<TitleScene>(this, parameter));	//タイトルのシーンを作ってpush
}

/*!
@brief スタックのトップのシーンの処理をする
*/
bool Looper::loop() {
	Keyboard::getIns()->update();
	Pad::getIns()->update();
	_sceneStack.top()->update();	//トップスタックの更新
	_sceneStack.top()->draw();		//トップスタックの描画
	_fps.draw();
	_fps.wait();
	return true;
}

/*!
@brief シーン変更(各シーンからコールバックされる)
@param scene 変更するシーンのenum
@param parameter 前のシーンから引き継ぐパラメータ
@param stackClear 現在のシーンのスタックをクリアするか
*/
void Looper::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear)
{
	if (stackClear)						//もしスタック削除指定なら
		while (!_sceneStack.empty())	//スタックを空にする
			_sceneStack.pop();

	switch (scene)
	{
		case Title:
			_sceneStack.push(make_shared<TitleScene>(this, parameter));
			break;
		case Game:
			_sceneStack.push(make_shared<GameScene>(this, parameter));
			break;
		default:
			ERR("有るはずのないシーンが呼ばれました。");
			break;
	}
}