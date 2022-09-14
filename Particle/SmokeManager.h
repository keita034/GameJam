#pragma once
#include<memory>
#include<list>
#include"Smoke.h"

class SmokeManager {

public:
	static SmokeManager* GetInstance();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X���[�N�̍X�V
	/// </summary>
	void Updata(Vec2 pos);

	/// <summary>
	/// Draw����
	/// </summary>
	void Draw(Vec2 screen);

	/// <summary>
	/// ���܂ꂽ���̃X���[�N����
	/// </summary>
	void MakeSmoke();

	/// <summary>
	/// ���񂾂Ƃ��̃X���[�N����
	/// </summary>
	void deathSmoke(Vec2 pos);

	bool IsDeath();

private:
	SmokeManager();
	~SmokeManager() = default;

	std::list<std::unique_ptr<Smoke>>smokes_;

	int siroGh = 0;

	bool isDeath;
};