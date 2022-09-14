#pragma once
#include"DxLib.h"
#include"Vec2.h"
#include"KeyBoardInput.h"
#include"Ease.h"
#include<cmath>
#include"Sound.h"
#include"playerLevelUp.h"

class Enemy;

class Player
{
private:

	Sound* sound_ = nullptr;

	PlayerLevelUp* playerLevelUp_ = nullptr;


	//座標
	Vec2 pos{};
	//1フレーム前の座標
	Vec2 oldPos{};
	//半径
	int radius = 24;
	//角度
	float angle = 0.0f;
	//スピード
	float speed = 5.0f;
	//正面ベクトル
	Vec2 frontVec{};
	Vec2 moveBuff{};
	//体力
	int hp = 10;
	int playerImg = 0;;
	
	//フィールドサイズ
	Vec2 fieldSize = { 2560.0f ,1440.0f };
	Vec2 zero = { 0.0f,0.0f };

	//スクリーン座標
	Vec2 screen = { 760.0f,360.0f };
	Vec2 screenInit = { 520.0f,360.0f };

	//攻撃時間
	float attackTime = 0;
	float attackFrameTime = 0;
	int maxAttackTime = 60;
	//攻撃インターバル
	int attackInterval = 0;
	//最大攻撃インターバル
	int maxAttackInterval = 20;
	//攻撃距離
	int attackDistance = 640;;
	//攻撃フラグ
	bool attackFlag = false;
	bool attackStanceFlag = false;
	//1フレーム前の攻撃フラグ
	bool oldAttackFlag = false;
	//攻撃半径
	int attackRadius = 239;
	//攻撃威力
	int attackPower = 1;
	//攻撃しようとした座標
	Vec2 attackBeginPos;
	//攻撃しようとしたスクリーン座標
	Vec2 attackScreenBeginPos{};
	Vec2 attackScreenEndPos{};
	bool attackCameraFlag = false;
	//攻撃のレベル
	int level = 0;
	//攻撃した時に一番近い敵とのベクトル
	Vec2 attackEnemyToPlayerVec;
	//攻撃レベルが上がる距離
	float levelUpDistance = 179;
	//攻撃の方向ベクトル
	Vec2 attackDirectionVec{};
	bool finalLevel = false;

	//コンボ猶予時間
	float comboExtensionTime = 50 * 3;
	float maxComboExtensionTime = comboExtensionTime;
	bool comboExtensionFlag = false;
	int combo;

	float levelUpExtensionTime = 50 * 3.8;
	float maxLevelUpExtensionTime = levelUpExtensionTime;
	bool levelUpExtensionFlag = false;

	float attackStanceEffectFrameTime = 0;
	float attackStanceEffectTime = 0;
	int maxAttackStanceEffectTime = 25 ;
	bool attackStanceEffectFlag = false;
	bool attackStanceEffectTriggerFlag = false;
	float attackStanceEffectRadius = 0.0f;
	unsigned int attackStanceEffectColor = 0x2c080b;

	int playerFrameImg[5];

	int damageEffectImg = 0;
	int damageEffectTime = 0;

	int damagePlayerImg[5];
	
	int swordImg = 0;
	int swordAnimationImg[5];

	float swordMagnification = 0.91f;

	bool damageFlag = false;
public:

	Player();
	~Player() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	Vec2 GetPos();
	int GetRadius();

	Vec2 GetScreen();

	bool GetAttackFlag();

	int GetAttackRadius();

	void HPSub(int subNum);

	void HPAdd(int addNum);

	int GetAttackPower();

	int GetHp();

	int GetLevel();

	/// <summary>
	/// 攻撃
	/// </summary>
	void LevelUpdate(Vec2 vec, Enemy* enemy);

	void ComboUpdate();

	void MoveLimit();

	bool AttackTriggerFlag();
	void Attack();

	int GetCombo();
	void AddCombo();

	float GetAngle();

	bool DamageFlag();

private:
	void SwordDraw();
};

