#pragma once
#include "Enemy.h"
#include "Player.h"
#include "Collision.h"
#include "Util.h"
#include<memory>
#include<list>
#include"Smoke.h"
#include"Sound.h"
#include"Pause.h"

// ���A�G�̓���
enum situation
{
	MoveLeftRight,           // ��ō��E�ɓ���
	TrakingPlayer,           // �v���C���[��ǔ�
	StopInFrontOfThePlayer,  // �v���C���[�̑O�Ɏ~�܂��ĉ��
	Escape_,                  // ������
};

class RareEnemy
{
public:
	// ������
	void RareEnemyInit(Vec2 pos,int siroGh);

	// �X�V����
	void RareEnemyUpdate(Player* player_);

	// �`�揈��
	void RareEnemyDraw(Player* player_);

	// �����蔻��
	void RareEnemyCheckCollisions(Player* player_);

	// ���S�t���O�̎擾
	bool IsDeath();

private:
	Vec2 InitPos = { 0,0 };
	Vec2 velocity;
	Vec2 A = { 0,0 }, B = { 200,0 };
	Vec2 limitVelocity = B - A;
	Vec2 NowVelocity;
	float angle;

	bool StopinitFlag = true;
	Vec2 StopEnemyPos = { 0,0 };
	Vec2 center;
	Vec2 vector;
	Vec2 vector2;

	// �X���[�N
	Smoke* smoke_ = nullptr;
	bool smokeFlag = false;

	// ���A�G
	std::unique_ptr<Enemy> rareEnemy;

	// �t�F�[�Y
	situation situation_ = MoveLeftRight;

	// �s���^�C�}�[
	int timer = 0;

	// �G�̃X�s�[�h
	Vec2 Speed = { 8,8 };

	// ���ړ��t���O
	bool MoveLeftRightFlag = false;

	//�����b�J
	Sound* sound_ = nullptr;
	Pause* pause_ = nullptr;
};

