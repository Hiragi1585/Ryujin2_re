#include "GameScene.h"
#include <DxLib.h>
#include "Macro.h"
#include "Background01.h"
#include "Background01spell.h"

const char* GameScene::ParameterTagStage = "ParameterTagStage";
const char* GameScene::ParameterTagLevel = "ParameterTagLevel";

GameScene::GameScene(IOnSceneChangeListener * impl, const Parameter & parameter) : AbstractScene(impl,parameter) {
	_level = parameter.get(ParameterTagLevel);
	_player = std::make_shared<Player>();
	_board = std::make_shared<Board>();
	_background = std::make_shared<Background01>();
	_backgroundspell = std::make_shared<Background01spell>();
	_enemyManager = std::make_shared<EnemyManager>();
}

void GameScene::update() {
	if (CheckHitKey(KEY_INPUT_Q)) {
		Parameter parameter;
		_implSceneChanged->onSceneChanged(eScene::Title, parameter, false);
	}
	_player->update();
	_board->update();
	_background->update();
	_enemyManager->update();
}

void GameScene::draw() const {
	_background->draw();
	_player->draw();
	_board->draw();
	_enemyManager->draw();
}
