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


	//���W
	Vec2 pos{};
	//1�t���[���O�̍��W
	Vec2 oldPos{};
	//���a
	int radius = 24;
	//�p�x
	float angle = 0.0f;
	//�X�s�[�h
	float speed = 5.0f;
	//���ʃx�N�g��
	Vec2 frontVec{};
	Vec2 moveBuff{};
	//�̗�
	int hp = 10;
	int playerImg = 0;;
	
	//�t�B�[���h�T�C�Y
	Vec2 fieldSize = { 2560.0f ,1440.0f };
	Vec2 zero = { 0.0f,0.0f };

	//�X�N���[�����W
	Vec2 screen = { 760.0f,360.0f };
	Vec2 screenInit = { 520.0f,360.0f };

	//�U������
	float attackTime = 0;
	float attackFrameTime = 0;
	int maxAttackTime = 60;
	//�U���C���^�[�o��
	int attackInterval = 0;
	//�ő�U���C���^�[�o��
	int maxAttackInterval = 20;
	//�U������
	int attackDistance = 640;;
	//�U���t���O
	bool attackFlag = false;
	bool attackStanceFlag = false;
	//1�t���[���O�̍U���t���O
	bool oldAttackFlag = false;
	//�U�����a
	int attackRadius = 239;
	//�U���З�
	int attackPower = 1;
	//�U�����悤�Ƃ������W
	Vec2 attackBeginPos;
	//�U�����悤�Ƃ����X�N���[�����W
	Vec2 attackScreenBeginPos{};
	Vec2 attackScreenEndPos{};
	bool attackCameraFlag = false;
	//�U���̃��x��
	int level = 0;
	//�U���������Ɉ�ԋ߂��G�Ƃ̃x�N�g��
	Vec2 attackEnemyToPlayerVec;
	//�U�����x�����オ�鋗��
	float levelUpDistance = 179;
	//�U���̕����x�N�g��
	Vec2 attackDirectionVec{};
	bool finalLevel = false;

	//�R���{�P�\����
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
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
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
	/// �U��
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

