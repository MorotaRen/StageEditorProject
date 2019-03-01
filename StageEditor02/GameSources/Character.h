/*!
@file Character.h
@brief キャラクターなど
*/

#pragma once
#include "stdafx.h"

namespace basecross{

	//--------------------------------------------------------------------------------------
	///	更新可能なライン
	//--------------------------------------------------------------------------------------
	class ActionLine : public GameObject {
		Vec3 m_StartPos;
		Vec3 m_EndPos;
		Col4 m_Col;
		bool m_IsUpdate;
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	コンストラクタ
		@param[in]	StagePtr	ステージ
		@param[in]	StartPos	スタートの位置
		@param[in]	EndPos	エンド位置
		@param[in]	col	線の色

		*/
		//--------------------------------------------------------------------------------------
		ActionLine(const shared_ptr<Stage>& StagePtr, const Vec3& StartPos,
			const Vec3&  EndPos,const Col4& col);
		virtual ~ActionLine() {}
		//初期化
		virtual void OnCreate() override;
		//更新
		virtual void OnUpdate() override;
		//線のスタート位置の取得
		const Vec3& GetStartPos() const {
			return m_StartPos;
		}
		//線のスタート位置の設定
		void SetStartObj(const Vec3& Pos) {
			m_StartPos = Pos;
			m_IsUpdate = true;
		}
		//線のエンド位置の取得
		const Vec3& GetEndPos() const {
			return m_EndPos;
		}
		//線のエンド位置の設定
		void SetEndObj(const Vec3& Pos) {
			m_EndPos = Pos;
			m_IsUpdate = true;
		}
		//線のスタートとエンド位置の設定
		void ResetObject(const Vec3& StartPos, const Vec3& EndPos) {
			m_StartPos = StartPos;
			m_EndPos = EndPos;
			m_IsUpdate = true;
		}
	};

	//--------------------------------------------------------------------------------------
	//	タイリングするプレート
	//--------------------------------------------------------------------------------------
	class TilingPlate : public GameObject {
		Vec3 m_Scale;
		Quat m_Qt;
		Vec3 m_Position;
		float m_UPic;
		float m_VPic;
	public:
		//構築と破棄
		TilingPlate(const shared_ptr<Stage>& StagePtr, const Vec3& Scale,const Quat& Qt,const Vec3& Position,
			float m_UPic,float m_VPic);
		virtual ~TilingPlate();
		//初期化
		virtual void OnCreate() override;
		//操作
	};

	enum class StShapeType {
		Square,
		Cube,
		Sphere,
		Capsule,
		Cylinder,
		Cone,
		Torus,
		Tetrahedron,
		Octahedron,
		Dodecahedron,
		Icosahedron,
	};

	struct StParams {
		wstring m_ClsName;
		StShapeType m_ShapeType;
		Vec3 m_Scale;
		Vec3 m_Rotation;
		Vec3 m_Position;
		float m_UPic;
		float m_VPic;
		wstring m_ModelFilename;
		StParams():
			m_ShapeType(StShapeType::Cube),
			m_Scale(1.0f),
			m_Rotation(0.0f),
			m_Position(0.0f),
			m_UPic(1.0f),
			m_VPic(1.0f),
			m_ModelFilename(L"")
		{}
	};

	//--------------------------------------------------------------------------------------
	//	配置されるオブジェクト
	//--------------------------------------------------------------------------------------
	class StageObject : public GameObject {
	private:
		bool m_Selected;
		StParams m_StParams;
		Vec3 m_SelectPoint;
	public:
		//構築と破棄
		StageObject(const shared_ptr<Stage>& StagePtr);
		virtual ~StageObject();
		//初期化
		virtual void OnCreate() override;
		//更新
		virtual void OnUpdate()override;
		//操作
		void SetParamaters(const StParams& param);
		void SetSelected(bool b);
		bool IsHitSegmentTriangles(const Vec3& StartPos, const Vec3& EndPos, Vec3& HitPoint);
	};




}
//end basecross
