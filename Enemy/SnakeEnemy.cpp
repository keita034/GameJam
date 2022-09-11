#include "SnakeEnemy.h"
void SnakeEnemy::SnakeEnemyPop(Vec2 pos)
{
	snakeEnemy[0] = std::make_unique<Enemy>();
	snakeEnemy[0]->Initialize(Traking, { pos.x ,pos.y }, 3.0f,1);

	for (int i = 1; i < 5; i++)
	{
		snakeEnemy[i] = std::make_unique<Enemy>();
		int j = i - 1;
		Vec2 EPos = snakeEnemy[j].get()->GetPos();
		snakeEnemy[i].get()->SetTrakingEnemyPos(EPos);
		snakeEnemy[i]->Initialize(TrakingEnemy, { pos.x + 75 * i ,pos.y }, 3.0f,1);
	}
}

void SnakeEnemy::SnakeEnemyUpdate(Player* player_)
{
	for (int i = 0; i < 5 - deathNum; i++)
	{
		if (snakeEnemy[i]->IsDeath() == true)
		{
			deathNum++;
		}
	}

	snakeEnemy[0].get()->Update(player_->GetPos());
	for (int i = 1; i < 5 - deathNum; i++)
	{
		int j = i - 1;
		Vec2 EPos = snakeEnemy[j].get()->GetPos();
		snakeEnemy[i].get()->SetTrakingEnemyPos(EPos);
		snakeEnemy[i].get()->Update(player_->GetPos());
	}

	collisionTimer++;
	if (collisionTimer >= collisionInterval)
	{
		SnakeEnemyCheckCollisions(player_);
		collisionTimer = 0;
	}
	
}

void SnakeEnemy::SnakeEnemyDraw(Player* player_)
{
	for (int i = 0; i < 5 - deathNum; i++)
	{
		snakeEnemy[i].get()->Draw(player_->GetScreen());
	}
}

void SnakeEnemy::SnakeEnemyCheckCollisions(Player* player_)
{
	for (int i = 0; i < 5 - deathNum; i++)
	{
		//‚É‚å‚ë‚É‚å‚ë‚Ì‚©‚ç‚¾‚Ì‚Ç‚ê‚©‚ª‚ÆŽ©‹@“–‚½‚Á‚½‚çˆê”ÔŒã‚ë‚©‚çÁ‚·
		if (!player_->GetAttackFlag() && CheckSphere2Sphere(player_->GetPos(), player_->GetRadius(), snakeEnemy[i]->GetPos(), snakeEnemy[i]->GetRadius()))
		{
			// Œã‚ë‚©‚ç‡‚ÉÁ‚·ˆ—
			if (snakeEnemy[4]->IsDeath() == false)
			{
				player_->HPSub(1);
				snakeEnemy[4]->Death();
				break;
			}
			else if (snakeEnemy[3]->IsDeath() == false)
			{
				player_->HPSub(1);
				snakeEnemy[3]->Death();
				break;
			}
			else if (snakeEnemy[2]->IsDeath() == false)
			{
				player_->HPSub(1);
				snakeEnemy[2]->Death();
				break;
			}
			else if (snakeEnemy[1]->IsDeath() == false)
			{
				player_->HPSub(1);
				snakeEnemy[1]->Death();
				break;
			}
			else if (snakeEnemy[0]->IsDeath() == false)
			{
				player_->HPSub(1);
				snakeEnemy[0]->Death();
				break;
			}

		}

		if (player_->GetAttackFlag())
		{
			//Ž©‹@‚ÌUŒ‚‚Æ“G
   			if (CheckSphere2Sphere(player_->GetPos(), player_->GetAttackRadius(), snakeEnemy[i]->GetPos(), snakeEnemy[i]->GetRadius()))
			{
				if (snakeEnemy[4]->IsDeath() == false)
				{
					if (snakeEnemy[4]->GetDamageFlag())
					{
						player_->AddCombo();
					}
					snakeEnemy[4]->HPSub(player_->GetAttackPower());
				}
				else if (snakeEnemy[3]->IsDeath() == false)
				{
					if (snakeEnemy[3]->GetDamageFlag())
					{
						player_->AddCombo();
					}
					snakeEnemy[3]->HPSub(player_->GetAttackPower());
				}
				else if (snakeEnemy[2]->IsDeath() == false)
				{
					if (snakeEnemy[2]->GetDamageFlag())
					{
						player_->AddCombo();
					}
					snakeEnemy[2]->HPSub(player_->GetAttackPower());
				}
				else if (snakeEnemy[1]->IsDeath() == false)
				{
					if (snakeEnemy[1]->GetDamageFlag())
					{
						player_->AddCombo();
					}
					snakeEnemy[1]->HPSub(player_->GetAttackPower());
				}
				else if (snakeEnemy[0]->IsDeath() == false)
				{
					if (snakeEnemy[0]->GetDamageFlag())
					{
						player_->AddCombo();
					}
					snakeEnemy[0]->HPSub(player_->GetAttackPower());
				}
			}
		}
	}
}

int SnakeEnemy::GetDeathCount()
{
	return deathNum;
}
