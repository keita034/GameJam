#include"Pause.h"
#include<math.h>

void Pause::Initialize(){
	// 画像などのリソースデータの変数宣言と読み込み
	nextGh = LoadGraph("push_space.png", true);
	untiGh = LoadGraph("unti.png", true);
	MenuGh = LoadGraph("Menu.png", true);
	GamePlayGh = LoadGraph("GamePlay.png", true);
	GraphicGh = LoadGraph("Graphic.png", true);
	SettingGh = LoadGraph("Setting.png", true);
	SoundGh = LoadGraph("Sound.png", true);
	EscGh = LoadGraph("Esc.png", true);
	ORGh = LoadGraph("OR.png", true);
	siroGh = LoadGraph("sirotama.png", true);
	BackGh = LoadGraph("Back.png", true);
	Back2Gh = LoadGraph("Back2.png", true);
}

void Pause::Update(char* keys, char* oldkeys){

	

}

void Pause::Move(){

}

void Pause::MenuSelect(char* keys, char* oldkeys){

}

void Pause::Draw(){

}

