#pragma once
#include <DxLib.h>
#include"TitleScene.h"
#include"GameScene.h"
#include"ResultScene.h"
#include"Pause.h"
#include"Sound.h"


class SceneManager
{
public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	SceneManager();

public:

	/// <summary>
	/// デストラクタ
	/// </summary>
	~SceneManager();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update(char* keys, char* oldkeys);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// 暗転シーン
	/// </summary>
	void Blackout();

	/// <summary>
	/// タイトル
	/// </summary>
	void Title(char* keys, char* oldkeys);

	/// <summary>
	/// チュートリアル
	/// </summary>
	void Tutorial(char* keys, char* oldkeys);

	/// <summary>
	/// バトルステージ
	/// </summary>
	void Stage();

	/// <summary>
	/// リザルト
	/// </summary>
	void Result(char* keys, char* oldkeys);

	int GetFinish();

	enum class Scene {
		Blackout,//暗転シーン
		Title,//タイトル
		Tutorial,//チュートリアル
		Stage,//バトルステージ
		Result,//リザルト
		Initialize,//初期化シーン
	};

	void risetOrTitle(int x);

	//テスト用関数
	void TestMove();


private:

	//フェーズ
	Scene scene_ = Scene::Title;
	//直前のシーンを記録
	int justBefore = 1;

	//タイトル
	TitleScene* titleScene_ = nullptr;
	//ゲームシーン
	GameScene* gameScene_ = nullptr;
	//リザルト
	ResultScene* resultScene_ = nullptr;

	Pause* pause_ = nullptr;
	Sound* sound_ = nullptr;


	//テスト用
	int x = 300;
	int y = 300;

	int vx = 0;
	//パーティクル
	int pal = 0;
	int palTimer;

	//暗転フラグ
	int isBlackOut = 0;

	int isESC = 0;

	int isFinish = 0;

	int blackFlag = 0;

	int sceenSelect = 0;

	int escGh = 0;

	int unti = 0;
};

