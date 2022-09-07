#pragma once
#include <DxLib.h>
#include"TitleScene.h"
#include"GameScene.h"
#include"ResultScene.h"
#include"Pause.h"

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
	void Blackout(char* keys, char* oldkeys);

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
	void Stage(char* keys, char* oldkeys);

	/// <summary>
	/// ���U���g
	/// </summary>
	void Result(char* keys, char* oldkeys);


	enum class Scene {
		Blackout,//�Ó]�V�[��
		Title,//�^�C�g��
		Tutorial,//�`���[�g���A��
		Stage,//�o�g���X�e�[�W
		Result,//���U���g
	};

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

	//�p�[�e�B�N��
	int pal = 0;
	int palTimer;

	//�Ó]�t���O
	int isBlackOut = 0;

	int isESC = 0;

};

