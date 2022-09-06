#pragma once
#include <DxLib.h>
#include"TitleScene.h"
#include"GameScene.h"
#include"ResultScene.h"


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
	void Blackout(char* keys, char* oldkeys);

	/// <summary>
	/// タイトル
	/// </summary>
	void Title(char* keys, char* oldkeys);

	/// <summary>
	/// チュートリアル
	/// </summary>
	void Tutorial();

	/// <summary>
	/// バトルステージ
	/// </summary>
	void Stage();

	/// <summary>
	/// リザルト
	/// </summary>
	void Result();


	enum class Scene {
		Blackout,//暗転シーン
		Title,//タイトル
		Tutorial,//チュートリアル
		Stage,//バトルステージ
		Result,//リザルト
	};

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

	//パーティクル
	int pal = 0;
	int palTimer;

	//暗転フラグ
	int isBlackOut = 0;


};

