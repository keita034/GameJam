#pragma once
#include "Particle.h"

class HitPar
{
private:
	Vec2 pos;
	Vec2 vec;
	int max;
	bool flag = false;
	Particle* particle;
public:
	HitPar();
	~HitPar();
	void Initialize();
	void Update();
	void Draw();
	void SetFlag(bool flag);
	bool GetFlag();
	void SetPos(Vec2 pos);
	void SetVec(Vec2 Vec);
};