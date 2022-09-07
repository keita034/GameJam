#pragma once
#include "Util.h"
#include "DxLib.h"
#include"KeyBoardInput.h"
enum Pattern
{
	heightUp,       // 縦上
	heightDown,     // 縦下
	widthL,         // 横左
	widthR,         // 横右
	upperL,         // 左斜め上
	upperR,         // 右斜め上
	diagonallyDownL,// 左斜め下
	diagonallyDownR,// 右斜め下
	traking         // 追尾
};

class Enemy
{
public:
	// インスタンス
	Enemy();
	~Enemy();

	// メンバー関数

	// 初期化関数
	void Initialize(Pattern pattern,Vec2 pos,Vec2 speed);

	// 更新関数
	void Update(Vec2 playerNpos);

	// 描画関数
	void Draw();
private:
	// メンバー変数
	Vec2 pos_;
	Vec2 speed_;
	float radius_;
	Vec2 playerPos_;

	// エネミーの行動パターン
	Pattern pattern_;
};

