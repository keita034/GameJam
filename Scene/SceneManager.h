#pragma once
#include <DxLib.h>
#include"TitleScene.h"
#include"GameScene.h"
#include"ResultScene.h"


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
	void Tutorial();

	/// <summary>
	/// �o�g���X�e�[�W
	/// </summary>
	void Stage();

	/// <summary>
	/// ���U���g
	/// </summary>
	void Result();


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

	//�p�[�e�B�N��
	int pal = 0;
	int palTimer;

	//�Ó]�t���O
	int isBlackOut = 0;


};

