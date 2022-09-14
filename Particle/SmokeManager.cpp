#include"SmokeManager.h"

SmokeManager::SmokeManager() {
	siroGh = LoadGraph("Resources/haiiroMoku.png", true);
	isDeath = false;
}

SmokeManager* SmokeManager::GetInstance()
{
	static SmokeManager instance;
	return &instance;
}

void SmokeManager::Initialize() {

	std::unique_ptr<Smoke> smoke_;
	smoke_ = std::make_unique<Smoke>();

	smoke_->Initialize(siroGh);
	smokes_.push_back(std::move(smoke_));

	MakeSmoke();


}

void  SmokeManager::Updata(Vec2 pos) {
	for (std::unique_ptr<Smoke>& smoke_ : smokes_)
	{
		smoke_->Update(pos.x,pos.y);
		if (smoke_->IsDeath() == 1) {
			isDeath = true;
		}
	}
	smokes_.remove_if([](std::unique_ptr<Smoke>& smoke_)
		{
			return smoke_->IsDeath();
		});
}


void SmokeManager::Draw(Vec2 screen) {

	for (std::unique_ptr<Smoke>& smoke : smokes_)
	{
		smoke->Draw(screen);
	}

}

void SmokeManager::MakeSmoke() {

	for (std::unique_ptr<Smoke>& smoke_ : smokes_)
	{
		smoke_->MakeEnemySmoke();
	}
}

void SmokeManager::deathSmoke(Vec2 pos) {

	for (std::unique_ptr<Smoke>& smoke_ : smokes_)
	{
		smoke_->DieSmoke(pos.x,pos.y);
	}

}

bool SmokeManager::IsDeath() {
	return isDeath;
}
