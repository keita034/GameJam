#pragma once
#include "Util.h"
#include "DxLib.h"
#include"KeyBoardInput.h"

enum Pattern
{
	HeightUp,       // �c��
	HeightDown,     // �c��
	WidthL,         // ����
	WidthR,         // ���E
	UpperL,         // ���΂ߏ�
	UpperR,         // �E�΂ߏ�
	DiagonallyDownL,// ���΂߉�
	DiagonallyDownR,// �E�΂߉�
	Traking,        // �ǔ�
	Center,         // ���S��ʂ�
	TrakingEnemy,   // �O�ɂ���G�̌���ǔ�
	RareEnemy_,           // ���A�G
	None,           // �Ȃɂ��Ȃ�
};

enum DrawPattern
{
	Siratama,
	Yubi,
	Rare,
	Snake,
	SnakeBody
};

class Enemy
{
public:
	// �C���X�^���X
	Enemy();
	~Enemy();

	// �����o�[�֐�

	// �������֐�
	void Initialize(Pattern pattern,Vec2 pos,float speed,int hp_);

	// �X�V�֐�
	void Update(Vec2 playerNpos);

	// �`��֐�
	void Draw(Vec2 screen);

	bool IsDeath();

	Vec2 GetPos();

	int GetRadius();

	void Death();

	void HPSub(int subNum);

	void HPAdd(int addNum);

	void SetTrakingEnemyPos(Vec2 &enemyPos);

	void SetEnemyPos(Vec2& pos);

	void SetAngle(float angle_);

	bool GetDamageFlag();
private:
	// �����o�[�ϐ�
	Vec2 zeroVec = { 0.0f,0.0f };
	Vec2 MaxPos = { 700.0f,400.0f };
	Vec2 fieldSize = { 2560.0f ,1440.0f };
	Vec2 pos_;
	float speed_;
	Vec2 velocity_;
	float radius_;
	Vec2 playerPos_;
	bool isDeath_;
	//�_���[�W�C���^�[�o��
	int damageInterval = 0;
	int maxDamageInterval = 25;
	//�_���[�W�t���O
	bool damageFlag = true;
	// �G�l�~�[�̍s���p�^�[��
	Pattern pattern_;

	//�̗�
	int hp = 3;

	// �ЂƂO�ɂ���G�̈ʒu
	Vec2 tarkingEnemyPos = { 0,0 };

	// �ЂƂO�ɂ���G�Ƃ̃x�N�g���̒���
	Vec2 tarkingEnemyPosLength = { 0,0 };

	// ���̓G�ƑO�̓G�Ƃ̃x�N�g���̒���
	Vec2 tarkingEnemyPosLengthN = { 0,0 };



	// �p�x
	float angle = 0.0f;

	// �A�j���[�V�����^�C�}�[
	float animetionTimer = 0.0f;

	int  Siratamaflame = 0, Yubiflame = 0, RareEnemyFlame = 0, SnakeEnemyFlame = 0;

};

