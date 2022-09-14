#include "RareEnemy.h"
#include <math.h>

void RareEnemy::RareEnemyInit(Vec2 pos, int siroGh)
{
	rareEnemy = std::make_unique<Enemy>();

	sound_ = Sound::GetInstance();
	pause_ = new Pause();
	smoke_ = new Smoke();
	smoke_->Initialize(siroGh);
	smoke_->MakeEnemySmoke();
	smokeFlag = false;

	InitPos = pos;
	rareEnemy->Initialize(RareEnemy_, { pos.x ,pos.y }, 3.0f, 3, 0);
}

void RareEnemy::RareEnemyUpdate(Player* player_)
{
	timer++;
	Vec2 Npos = rareEnemy.get()->GetPos();
	smoke_->Update(rareEnemy->GetPos().x, rareEnemy->GetPos().y);

	switch (situation_)
	{
	case MoveLeftRight:
		rareEnemy->Update(player_->GetPos());
		if (timer == 25 * 50)
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

		rareEnemy->SetAngle(0);
		break;
	case TrakingPlayer:
		rareEnemy->Update(player_->GetPos());
		RareEnemyCheckCollisions(player_);
		// プレイヤーの現在の位置を取得とエネミーの位置でベクトルを作る
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

		rareEnemy->SetAngle(atan2(player_->GetPos().y - rareEnemy.get()->GetPos().y, player_->GetPos().x - rareEnemy.get()->GetPos().x) + 1.5708);
		
		break;
	case StopInFrontOfThePlayer:
	{
		rareEnemy->Update(player_->GetPos());
		RareEnemyCheckCollisions(player_);
		if (StopinitFlag == true)
		{
			
			vector = player_->GetPos() - StopEnemyPos;
			vector2 = vector.Normalized();

			// プレイヤーの位置との逆ベクトル
			vector2 *= -1;

			// 回転する範囲
			vector2 *= 78;
			
			float Length = vector2.Length();

			// 回転の中心位置を取得
			center = rareEnemy.get()->GetPos() + vector2;

			// その時の中心点とエネミーの角度を取得
			angle = atan2(rareEnemy.get()->GetPos().y - center.y, rareEnemy.get()->GetPos().x - center.x);

			StopinitFlag = false;
		}
		
		if (angle >= 6.28 * 3.3)
		{
			StopEnemyPos = rareEnemy->GetPos();
			situation_ = Escape_;
		}
		// 回転
		
		Vec2 rotePos = { center.x + cos(angle) * (vector2.Length()),
						 center.y + sin(angle) * (vector2.Length()) };
		rareEnemy->SetEnemyPos({ rotePos });

		angle += 0.07;

		rareEnemy->SetAngle(atan2(player_->GetPos().y - rareEnemy.get()->GetPos().y, player_->GetPos().x - rareEnemy.get()->GetPos().x) + 1.5708);
	}
		break;
	case Escape_:
		rareEnemy->Update(player_->GetPos());
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
		rareEnemy->SetAngle(atan2(InitPos.y - StopEnemyPos.y, InitPos.x - StopEnemyPos.x) + 1.5708);
		break;
	default:
		break;
	}
	
}

void RareEnemy::RareEnemyDraw(Player* player_)
{
	rareEnemy.get()->Draw(player_->GetScreen());
	smoke_->Draw(player_->GetScreen());
}

void RareEnemy::RareEnemyCheckCollisions(Player* player_)
{
	//敵と自機
	if (!player_->GetAttackFlag() && CheckSphere2Sphere(player_->GetPos(), player_->GetRadius(), rareEnemy->GetPos(), rareEnemy->GetRadius()))
	{
		player_->HPSub(1);
		rareEnemy->Death();
	}

	if (player_->GetAttackFlag())
	{
		//自機の攻撃と敵
		if (CheckSphere2Sphere(player_->GetPos(), player_->GetAttackRadius(), rareEnemy->GetPos(), rareEnemy->GetRadius()))
		{
			if (rareEnemy->GetDamageFlag())
			{
				player_->AddCombo();
				sound_->AttackHitUpdata();

				if (rareEnemy->GetisDie() <= 1)
				{
					smoke_->DieSmoke(rareEnemy.get()->GetPos().x, rareEnemy.get()->GetPos().y);
				}
			}
			
			rareEnemy->HPSub(player_->GetAttackPower());

		}
		else
		{
			if (!rareEnemy->GetDamageFlag())
			{
				rareEnemy->SetDamageFlag(true);
			}
		}
	}
}

bool RareEnemy::IsDeath()
{
	return rareEnemy->IsDeath();
}
