#include "RareEnemy.h"
#include <math.h>

void RareEnemy::RareEnemyInit(Vec2 pos)
{
	rareEnemy = std::make_unique<Enemy>();

	InitPos = pos;
	rareEnemy->Initialize(None, { pos.x ,pos.y }, 3.0f,4);
}

void RareEnemy::RareEnemyUpdate(Player* player_)
{
	timer++;
	Vec2 Npos = rareEnemy.get()->GetPos();
	rareEnemy->Update(player_->GetPos());
	switch (situation_)
	{
	case MoveLeftRight:
		if (timer == 5 * 50)
		{
			situation_ = TrakingPlayer;
		}

		if (Npos.x <= 200)
		{
			MoveLeftRightFlag = false;
		}
		else if (Npos.x >= 2360)
		{
			MoveLeftRightFlag = true;
		}
		if (MoveLeftRightFlag == false)
		{
			Npos.x += Speed.x;
		}
		else if (MoveLeftRightFlag == true)
		{
			Npos.x -= Speed.x;
		}

		rareEnemy.get()->SetEnemyPos(Npos);
		break;
	case TrakingPlayer:
		RareEnemyCheckCollisions(player_);
		// �v���C���[�̌��݂̈ʒu���擾�ƃG�l�~�[�̈ʒu�Ńx�N�g�������
		velocity = player_->GetPos() - rareEnemy.get()->GetPos();
		NowVelocity = player_->GetPos() - rareEnemy.get()->GetPos();
		velocity = velocity.Normalized();

		if (NowVelocity.Length() >= limitVelocity.Length())
		{
			velocity *= Speed;
		}
		else
		{
			StopEnemyPos = rareEnemy.get()->GetPos();
			StopinitFlag = true;
			situation_ = StopInFrontOfThePlayer;
		}

		Npos += velocity;
		rareEnemy.get()->SetEnemyPos(Npos);

		break;
	case StopInFrontOfThePlayer:
	{
		RareEnemyCheckCollisions(player_);
		if (StopinitFlag == true)
		{
			
			vector = player_->GetPos() - StopEnemyPos;
			vector2 = vector.Normalized();

			// �v���C���[�̈ʒu�Ƃ̋t�x�N�g��
			vector2 *= -1;

			// ��]����͈�
			vector2 *= 78;
			
			float Length = vector2.Length();

			// ��]�̒��S�ʒu���擾
			center = rareEnemy.get()->GetPos() + vector2;

			// ���̎��̒��S�_�ƃG�l�~�[�̊p�x���擾
			angle = atan2(rareEnemy.get()->GetPos().y - center.y, rareEnemy.get()->GetPos().x - center.x);

			StopinitFlag = false;
		}
		
		if (angle >= 6.28 * 3.3)
		{
			StopEnemyPos = rareEnemy->GetPos();
			situation_ = Escape_;
		}
		// ��]
		
		Vec2 rotePos = { center.x + cos(angle) * (vector2.Length()),
						 center.y + sin(angle) * (vector2.Length()) };
		rareEnemy->SetEnemyPos({ rotePos });

		angle += 0.07;

	}
		break;
	case Escape_:
		RareEnemyCheckCollisions(player_);
		velocity = InitPos - StopEnemyPos;
		velocity = velocity.Normalized();
		velocity *= Speed;
		Npos = rareEnemy->GetPos();
		Npos += velocity;
		if ( Npos.y >= InitPos.y)
		{
			rareEnemy.get()->SetEnemyPos(Npos);
		}
		else
		{
			situation_ = MoveLeftRight;
		}
		
		break;
	default:
		break;
	}
	
}

void RareEnemy::RareEnemyDraw(Player* player_)
{
	rareEnemy.get()->Draw(player_->GetScreen());
}

void RareEnemy::RareEnemyCheckCollisions(Player* player_)
{
	//�G�Ǝ��@
	if (!player_->GetAttackFlag() && CheckSphere2Sphere(player_->GetPos(), player_->GetRadius(), rareEnemy->GetPos(), rareEnemy->GetRadius()))
	{
		player_->HPSub(1);
		rareEnemy->Death();
	}

	if (player_->GetAttackFlag())
	{
		//���@�̍U���ƓG
		if (CheckSphere2Sphere(player_->GetPos(), player_->GetAttackRadius(), rareEnemy->GetPos(), rareEnemy->GetRadius()))
		{
			if (rareEnemy->GetDamageFlag())
			{
				player_->AddCombo();
			}

			rareEnemy->HPSub(player_->GetAttackPower());

		}
	}
}

bool RareEnemy::IsDeath()
{
	return rareEnemy->IsDeath();
}
