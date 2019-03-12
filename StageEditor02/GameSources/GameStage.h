/*!
@file GameStage.h
@brief ゲームステージ
*/

#pragma once
#include "stdafx.h"
#include "Project.h"

namespace basecross {

struct StParams;

//--------------------------------------------------------------------------------------
//	ゲームステージクラス
//--------------------------------------------------------------------------------------
class GameStage : public Stage {
	//ビューの作成
	void CreateViewLight();
	//タイリングプレートの作成
	void CreateTilingPlate();
	//ラインの作成
	void CreateActionLine();
	//プレイヤーの作成
	void CreatePlayer();
	//マウス位置
	Point2D<int> m_MousePoint;
public:
	//構築と破棄
	GameStage() :Stage(), m_MousePoint(0, 0) {}
	virtual ~GameStage() {}
	//初期化
	virtual void OnCreate()override;
	//更新
	virtual void OnUpdate()override;
	//以下Windowsアプリとのインターフェイス
	void InsertNewObject(const StParams& param);
	//マウスによるオブジェクト選択のクリア
	void SelectClear();
	//マウスとカメラのレイの取得
	void GetMouseRay(Vec3& Near, Vec3& Far);
	//マウスの左ボタン(押した瞬間)
	void OnLButtonEnter();
	//マウスの左ボタン(離した)
	void OnLButtonUp();
	//マウスのLボタンが押されているか
	bool IsLButtonDown();

	shared_ptr<GameObject> m_SelectObj;

	shared_ptr<GameObject> GetSelectObj() {
		return m_SelectObj;
	}
};
}
//end basecross

