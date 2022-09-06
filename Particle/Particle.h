#pragma once
#include "Util.h"

class Particle
{
private:
	// �`���Ƃ̈ʒu
	Box box;
	Circle circle;

	// ����
	Vec2 vec;

	// ���x
	float speed;

	// �t���O
	bool isActive;

	// 1F���Ƃɔ��a���g�k���鐔�l
	float addRadius;

	// �`
	int shape;

	// �\�����Ԃ��v������^�C�}�[
	float displayTimer;

	// �\������
	float MaxDisplayTime;

public:
	// �`�̗񋓌^
	enum Shape
	{
		BOX = 1,
		CIRCLE
	};

public:
	// �R���X�g���N�^
	Particle();

	// �f�X�g���N�^
	~Particle();

	// ������
	void Initialize();

	// �X�V����
	void Update();

	// �`�揈��
	void Draw();

	void DrawGraphHandle(int r, int g, int b, int BlendNum, double ExRate, double Angle, int GraphhHandle, bool FillFlag);

	//-----�Z�b�^�[-----//

	// �ʒu�̐ݒ�
	void SetPos(Vec2& pos);

	// �傫���̐ݒ�
	void SetSize(float width, float height);

	// ���a�̐ݒ�
	void SetRadius(float radius);

	// �����̐ݒ�
	void SetVec(Vec2& vec);

	// ���x�̐ݒ�
	void SetSpeed(float speed);

	// �t���O�̐ݒ�
	void SetActive(bool isActive);

	// �g�k���l�̐ݒ�
	void SetAddRadius(float addRadius);

	// �`�̐ݒ�
	void SetShape(int shape);

	// �\�����Ԃ̐ݒ�
	void SetMaxDisplayTime(float MaxDisplayTime);

	//-----�Q�b�^�[-----//

	// �ʒu�̎擾
	float GetPosX();
	float GetPosY();

	// ���a�̎擾
	float GetRadius();

	// �t���O�̎擾
	bool GetActive();

	// �\�����Ԃ��擾����
	float GetDisPlayTimer();
};