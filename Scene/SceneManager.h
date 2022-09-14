#pragma once
#include <DxLib.h>
#include"TitleScene.h"
#include"GameScene.h"
#include"ResultScene.h"
#include"Pause.h"
#include"Sound.h"


class SceneManager
{
public: // �����o�֐�
	/// <summary>
	/// �R���X�g�N���^
	/// </summary>
	SceneManager();

public:

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~SceneManager();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update(char* keys, char* oldkeys);

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// �Ó]�V�[��
	/// </summary>
	void Blackout();

	/// <summary>
	/// �^�C�g��
	/// </summary>
	void Title(char* keys, char* oldkeys);

	/// <summary>
	/// �`���[�g���A��
	/// </summary>
	void Tutorial(char* keys, char* oldkeys);

	/// <summary>
	/// �o�g���X�e�[�W
	/// </summary>
	void Stage();

	/// <summary>
	/// ���U���g
	/// </summary>
	void Result(char* keys, char* oldkeys);

	int GetFinish();

	enum class Scene {
		Blackout,//�Ó]�V�[��
		Title,//�^�C�g��
		Tutorial,//�`���[�g���A��
		Stage,//�o�g���X�e�[�W
		Result,//���U���g
		Initialize,//�������V�[��
	};

	void risetOrTitle(int x);

	//�e�X�g�p�֐�
	void TestMove();


private:

	//�t�F�[�Y
	Scene scene_ = Scene::Title;
	//���O�̃V�[�����L�^
	int justBefore = 1;

	//�^�C�g��
	TitleScene* titleScene_ = nullptr;
	//�Q�[���V�[��
	GameScene* gameScene_ = nullptr;
	//���U���g
	ResultScene* resultScene_ = nullptr;

	Pause* pause_ = nullptr;
	Sound* sound_ = nullptr;


	//�e�X�g�p
	int x = 300;
	int y = 300;

	int vx = 0;
	//�p�[�e�B�N��
	int pal = 0;
	int palTimer;

	//�Ó]�t���O
	int isBlackOut = 0;

	int isESC = 0;

	int isFinish = 0;

	int blackFlag = 0;

	int sceenSelect = 0;

	int escGh = 0;

	int unti = 0;
};

