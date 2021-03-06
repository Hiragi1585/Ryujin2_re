#include <DxLib.h>
#include "TitleScene.h"
#include "GameScene.h"
#include "Define.h"
#include "Keyboard.h"
#include "Pad.h"

TitleScene::TitleScene(IOnSceneChangeListener* impl, const Parameter & parameter) : AbstractScene(impl,parameter) {
	str_x = 100;
	str_y = 100;
}

void TitleScene::update() {
	if (Pad::getIns()->get(ePad::shot) == 1) {
		Parameter parameter;
		parameter.set(GameScene::ParameterTagLevel, Define::eLevel::Easy);
		const bool stackClear = false;
		_implSceneChanged->onSceneChanged(eScene::Game, parameter, stackClear);
	}

	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_N) == 1) {
		Parameter parameter;
		parameter.set(GameScene::ParameterTagLevel, Define::eLevel::Normal);
		const bool stackClear = false;
		_implSceneChanged->onSceneChanged(eScene::Game, parameter, stackClear);
	}

	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_R) == 1) {
		Parameter parameter;
		parameter.set(GameScene::ParameterTagLevel, Define::eLevel::Normal);
		const bool stackClear = false;
		_implSceneChanged->onSceneChanged(eScene::Result, parameter, stackClear);
	}
}

void TitleScene::draw() const {
	DrawString(str_x, str_y, "TitleScreen",GetColor(255, 255, 255));
}
