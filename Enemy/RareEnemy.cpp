#include "RareEnemy.h"
#include <math.h>

void RareEnemy::RareEnemyInit(Vec2 pos)
{
	rareEnemy = std::make_unique<Enemy>();

	InitPos = pos;
	rareEnemy->Initialize(None, { pos.x ,pos.y }, 3.0f);
}

void RareEnemy::RareEnemyUpdate(Player* player_)
{
	timer++;
	Vec2 Npos = rareEnemy.get()->GetPos();
	switch (situation_)
	{
	case MoveLeftRight:
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
		break;
	case TrakingPlayer:
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
		break;
	case StopInFrontOfThePlayer:
	{
		if (StopinitFlag == true)
		{
			
			vector = player_->GetPos() - StopEnemyPos;
			vector2 = vector.Normalized();
			vector2 *= -1;
			vector2 *= vector.Length();

			float Length = vector2.Length();

			// 回転の中心位置を取得
			center = rareEnemy.get()->GetPos() + vector2;

			// その時の中心点とエネミーの角度を取得
			angle = atan2(rareEnemy.get()->GetPos().y - center.y, rareEnemy.get()->GetPos().x - center.x);

			StopinitFlag = false;
		}
		
		if (angle >= 6.28 * 3)
		{
			StopEnemyPos = rareEnemy->GetPos();
			situation_ = Escape_;
		}
		// 回転
		angle += 0.05;
		Vec2 rotePos = { center.x + cos(angle) * vector2.Length(),center.y + sin(angle) * vector2.Length() };

		rareEnemy->SetEnemyPos({ rotePos });
		
	}
		break;
	case Escape_:
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
