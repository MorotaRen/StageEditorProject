/*!
@file Character.h
@brief �L�����N�^�[�Ȃ�
*/

#pragma once
#include "stdafx.h"

namespace basecross{

	//--------------------------------------------------------------------------------------
	///	�X�V�\�ȃ��C��
	//--------------------------------------------------------------------------------------
	class ActionLine : public GameObject {
		Vec3 m_StartPos;
		Vec3 m_EndPos;
		Col4 m_Col;
		bool m_IsUpdate;
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		@param[in]	StagePtr	�X�e�[�W
		@param[in]	StartPos	�X�^�[�g�̈ʒu
		@param[in]	EndPos	�G���h�ʒu
		@param[in]	col	���̐F

		*/
		//--------------------------------------------------------------------------------------
		ActionLine(const shared_ptr<Stage>& StagePtr, const Vec3& StartPos,
			const Vec3&  EndPos,const Col4& col);
		virtual ~ActionLine() {}
		//������
		virtual void OnCreate() override;
		//�X�V
		virtual void OnUpdate() override;
		//���̃X�^�[�g�ʒu�̎擾
		const Vec3& GetStartPos() const {
			return m_StartPos;
		}
		//���̃X�^�[�g�ʒu�̐ݒ�
		void SetStartObj(const Vec3& Pos) {
			m_StartPos = Pos;
			m_IsUpdate = true;
		}
		//���̃G���h�ʒu�̎擾
		const Vec3& GetEndPos() const {
			return m_EndPos;
		}
		//���̃G���h�ʒu�̐ݒ�
		void SetEndObj(const Vec3& Pos) {
			m_EndPos = Pos;
			m_IsUpdate = true;
		}
		//���̃X�^�[�g�ƃG���h�ʒu�̐ݒ�
		void ResetObject(const Vec3& StartPos, const Vec3& EndPos) {
			m_StartPos = StartPos;
			m_EndPos = EndPos;
			m_IsUpdate = true;
		}
	};

	//--------------------------------------------------------------------------------------
	//	�^�C�����O����v���[�g
	//--------------------------------------------------------------------------------------
	class TilingPlate : public GameObject {
		Vec3 m_Scale;
		Quat m_Qt;
		Vec3 m_Position;
		float m_UPic;
		float m_VPic;
	public:
		//�\�z�Ɣj��
		TilingPlate(const shared_ptr<Stage>& StagePtr, const Vec3& Scale,const Quat& Qt,const Vec3& Position,
			float m_UPic,float m_VPic);
		virtual ~TilingPlate();
		//������
		virtual void OnCreate() override;
		//����
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
	//	�z�u�����I�u�W�F�N�g
	//--------------------------------------------------------------------------------------
	class StageObject : public GameObject {
	private:
		bool m_Selected;
		StParams m_StParams;
		Vec3 m_SelectPoint;
	public:
		//�\�z�Ɣj��
		StageObject(const shared_ptr<Stage>& StagePtr);
		virtual ~StageObject();
		//������
		virtual void OnCreate() override;
		//�X�V
		virtual void OnUpdate()override;
		//����
		void SetParamaters(const StParams& param);
		void SetSelected(bool b);
		bool IsHitSegmentTriangles(const Vec3& StartPos, const Vec3& EndPos, Vec3& HitPoint);
	};




}
//end basecross
