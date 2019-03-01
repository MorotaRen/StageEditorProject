/*!
@file GameStage.cpp
@brief ゲームステージ実体
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross {

	//--------------------------------------------------------------------------------------
	//	ゲームステージクラス実体
	//--------------------------------------------------------------------------------------
	//ビューとライトの作成
	void GameStage::CreateViewLight() {
		auto PtrView = CreateView<SingleView>();
		//ビューのカメラの設定
		auto PtrLookAtCamera = ObjectFactory::Create<LookAtCamera>();
		PtrView->SetCamera(PtrLookAtCamera);
		PtrLookAtCamera->SetEye(Vec3(0.0f, 5.0f, -5.0f));
		PtrLookAtCamera->SetAt(Vec3(0.0f, 0.0f, 0.0f));
		PtrLookAtCamera->SetMaxArm(100.0f);
		//シングルライトの作成
		auto PtrSingleLight = CreateLight<SingleLight>();
		//ライトの設定
		PtrSingleLight->GetLight().SetPositionToDirectional(-0.25f, 1.0f, -0.25f);
	}

	//ラインの作成
	void GameStage::CreateActionLine() {
		//X軸
		AddGameObject<ActionLine>(Vec3(-100.0f,0,0), Vec3(100.0f, 0.0f, 0.0f),Col4(0.0f,1.0f,0.0f,1.0f));
		//Y軸
		AddGameObject<ActionLine>(Vec3(0.0f, -100.0f, 0), Vec3(0.0f, 100.0f, 0.0f), Col4(1.0f, 0.0f, 0.0f, 1.0f));
		//Z軸
		AddGameObject<ActionLine>(Vec3(0.0f, 0.0f, -100.0f), Vec3(0.0f, 0.0f, 100.0f), Col4(0.0f, 0.0f, 1.0f, 1.0f));
	}

	//タイリングプレートの作成
	void GameStage::CreateTilingPlate() {
		Quat Qt;
		Qt.rotationRollPitchYawFromVector(Vec3(XM_PIDIV2, 0, 0));
		Vec3 Scale(200.0f, 200.0f, 1.0f);
		Vec3 Pos(0.0f, 0.0f, 0.0f);
		AddGameObject<TilingPlate>(Scale,Qt,Pos,1.0f,1.0f);
	}

	//プレイヤーの作成
	void GameStage::CreatePlayer() {
		//プレーヤーの作成
		auto PlayerPtr = AddGameObject<Player>();
		//シェア配列にプレイヤーを追加
		SetSharedGameObject(L"Player", PlayerPtr);
	}


	void GameStage::OnCreate() {
		try {
			//ビューとライトの作成
			CreateViewLight();
			//ラインの作成
			CreateActionLine();
			//タイリングプレートの作成
			CreateTilingPlate();
			//プレーヤーの作成
			CreatePlayer();
		}
		catch (...) {
			throw;
		}
	}

	//更新
	void GameStage::OnUpdate() {
		//キーボード（マウス）の取得
		auto KeyState = App::GetApp()->GetInputDevice().GetKeyState();
		m_MousePoint = KeyState.m_MouseClientPoint;
		if (KeyState.m_bPressedKeyTbl[VK_LBUTTON]) {
			OnLButtonEnter();
		}
		else if (KeyState.m_bUpKeyTbl[VK_LBUTTON]) {
			OnLButtonUp();
		}
	}


	void GameStage::InsertNewObject(const StParams& param) {
		auto Ptr = AddGameObject<StageObject>();
		Ptr->SetParamaters(param);
	}

	void GameStage::GetMouseRay(Vec3& Near, Vec3& Far) {
		Mat4x4 world, view, proj;
		world.affineTransformation(
			Vec3(1.0f, 1.0f, 1.0f),
			Vec3(0.0f, 0.0f, 0.0f),
			Vec3(0.0f, 0.0f, 0.0f),
			Vec3(0.0f, 0.0f, 0.0f)
		);
		auto PtrCamera = GetView()->GetTargetCamera();
		view = PtrCamera->GetViewMatrix();
		proj = PtrCamera->GetProjMatrix();
		auto viewport = GetView()->GetTargetViewport();

		Near = XMVector3Unproject(
			Vec3((float)m_MousePoint.x, (float)m_MousePoint.y, 0),
			viewport.TopLeftX,
			viewport.TopLeftY,
			viewport.Width,
			viewport.Height,
			viewport.MinDepth,
			viewport.MaxDepth,
			proj,
			view,
			world);

		Far = XMVector3Unproject(
			Vec3((float)m_MousePoint.x, (float)m_MousePoint.y, 1.0),
			viewport.TopLeftX,
			viewport.TopLeftY,
			viewport.Width,
			viewport.Height,
			viewport.MinDepth,
			viewport.MaxDepth,
			proj,
			view,
			world);
	}

	void GameStage::SelectClear() {
		for (auto& v : GetGameObjectVec()) {
			auto PsPtr = dynamic_pointer_cast<StageObject>(v);
			if (PsPtr) {
				PsPtr->SetSelected(false);
			}
		}
	}

	//マウスの左ボタン押した瞬間
	void GameStage::OnLButtonEnter() {
		SelectClear();
		auto PtrCamera = GetView()->GetTargetCamera();
		Vec3 Eye = PtrCamera->GetEye();

		vector<shared_ptr<StageObject>> ObjVec;
		Vec3 NearPos, FarPos;
		GetMouseRay(NearPos, FarPos);
		for (auto& v : GetGameObjectVec()) {
			auto PsPtr = dynamic_pointer_cast<StageObject>(v);
			if (PsPtr) {
				Vec3 HitPoint;
				if (PsPtr->IsHitSegmentTriangles(NearPos, FarPos, HitPoint)) {
					ObjVec.push_back(PsPtr);
				}
			}
		}
		if (ObjVec.size() > 0) {
			float MinSpan = 1000.0f;
			shared_ptr<StageObject> SelectObj = nullptr;
			for (auto& v : ObjVec) {
				float Span = length(v->GetComponent<Transform>()->GetPosition() - Eye);
				if (Span < MinSpan) {
					MinSpan = Span;
					SelectObj = v;
				}
			}
			if (SelectObj) {
				SelectObj->SetSelected(true);
			}
		}
	}


	//マウスの左ボタン(離した)
	void GameStage::OnLButtonUp() {
//		SelectClear();

	}

	bool GameStage::IsLButtonDown() {
		//キーボード（マウス）の取得
		auto KeyState = App::GetApp()->GetInputDevice().GetKeyState();
		if (KeyState.m_bPushKeyTbl[VK_LBUTTON]) {
			return true;
		}
		return false;
	}




}
//end basecross
