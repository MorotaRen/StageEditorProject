/*!
@file Character.cpp
@brief �L�����N�^�[�Ȃǎ���
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross{

	//--------------------------------------------------------------------------------------
	///	���C��
	//--------------------------------------------------------------------------------------
	ActionLine::ActionLine(const shared_ptr<Stage>& StagePtr, const Vec3& StartPos,
		const Vec3&  EndPos, const Col4& col) :
		GameObject(StagePtr),
		m_StartPos(StartPos),
		m_EndPos(EndPos),
		m_Col(col),
		m_IsUpdate(true)
	{}


	//������
	void ActionLine::OnCreate() {
		auto PtrTrans = GetComponent<Transform>();
		PtrTrans->SetScale(Vec3(1.0f, 1.0f, 1.0f));
		Quat Qt;
		Qt.identity();
		PtrTrans->SetQuaternion(Qt);
		PtrTrans->SetPosition(Vec3(0.0f, 0.0f, 0.0f));

		//�`��R���|�[�l���g
		auto PtrDraw = AddComponent<PCStaticDraw>();

		vector<VertexPositionColor> vertices = {
			{ VertexPositionColor(m_StartPos,  m_Col) },
			{ VertexPositionColor(m_EndPos,  m_Col) }

		};
		vector<uint16_t> indices = {
			0, 1
		};

		auto MeshRes = MeshResource::CreateMeshResource(vertices, indices, true);
		MeshRes->SetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
		PtrDraw->SetOriginalMeshResource(MeshRes);
		PtrDraw->SetOriginalMeshUse(true);

		m_IsUpdate = false;

	}

	void ActionLine::OnUpdate() {
		if (m_IsUpdate) {

			auto PtrDraw = GetComponent<PCStaticDraw>();
			const vector<VertexPositionColor>& BackupVec = PtrDraw->GetOriginalMeshResource()->GetBackupVerteces<VertexPositionColor>();
			vector<VertexPositionColor> new_vec;
			VertexPositionColor new_v;
			new_v = BackupVec[0];
			new_v.position = m_StartPos;
			new_vec.push_back(new_v);

			new_v = BackupVec[1];
			new_v.position = m_EndPos;
			new_vec.push_back(new_v);

			PtrDraw->UpdateVertices(new_vec);

			m_IsUpdate = false;
		}
	}

	//�\�z�Ɣj��
	TilingPlate::TilingPlate(const shared_ptr<Stage>& StagePtr, const Vec3& Scale, const Quat& Qt, const Vec3& Position,
		float m_UPic, float m_VPic) :
		GameObject(StagePtr),
		m_Scale(Scale),
		m_Qt(Qt),
		m_Position(Position),
		m_UPic(m_UPic),
		m_VPic(m_VPic)
	{
	}

	TilingPlate::~TilingPlate() {

	}
	//������
	void TilingPlate::OnCreate() {
		auto PtrTrans = GetComponent<Transform>();
		PtrTrans->SetScale(m_Scale);
		PtrTrans->SetQuaternion(m_Qt);
		PtrTrans->SetPosition(m_Position);
		AddComponent<CollisionRect>();

		vector<VertexPositionNormalTexture> vertices;
		vector<uint16_t> indices;
		MeshUtill::CreateSquare(1.0f, vertices, indices);
		float UCount = m_Scale.x / m_UPic;
		float VCount = m_Scale.y / m_VPic;
		for (size_t i = 0; i < vertices.size(); i++) {
			if (vertices[i].textureCoordinate.x >= 1.0f) {
				vertices[i].textureCoordinate.x = UCount;
			}
			if (vertices[i].textureCoordinate.y >= 1.0f) {
				vertices[i].textureCoordinate.y = VCount;
			}
		}
		//�`��R���|�[�l���g�̒ǉ�
		auto PtrDraw = AddComponent<BcPNTStaticDraw>();
		//�`��R���|�[�l���g�Ɍ`��i���b�V���j��ݒ�
		PtrDraw->CreateOriginalMesh(vertices, indices);
		PtrDraw->SetOriginalMeshUse(true);
		PtrDraw->SetFogEnabled(true);
		//�����ɉe���f�肱�ނ悤�ɂ���
		PtrDraw->SetOwnShadowActive(true);
		//�`��R���|�[�l���g�e�N�X�`���̐ݒ�
		PtrDraw->SetTextureResource(L"PLATE_TX");
		//�^�C�����O�ݒ�
		PtrDraw->SetSamplerState(SamplerState::LinearWrap);

		//��������
		SetAlphaActive(true);
		//�`�惌�C���[�͌��ɂ���
		SetDrawLayer(5);

	}

	//--------------------------------------------------------------------------------------
	//	�z�u�����I�u�W�F�N�g
	//--------------------------------------------------------------------------------------
	//�\�z�Ɣj��
	StageObject::StageObject(const shared_ptr<Stage>& StagePtr):
		GameObject(StagePtr)
		,m_StParams()
		,m_Selected(false)
	{}
	StageObject::~StageObject() {}

	void StageObject::OnCreate() {
		//�N���G�C�g���͉����s��Ȃ�
	}

	void StageObject::OnUpdate() {
		auto StagePtr = GetTypeStage<GameStage>();
		if (m_Selected && StagePtr->IsLButtonDown()) {
			Vec3 Near, Far;
			StagePtr->GetMouseRay(Near, Far);
			auto PtrDraw = GetComponent<BcPNTStaticDraw>();
			TRIANGLE tri;
			Vec3 HitPoint;
			auto Pos = GetComponent<Transform>()->GetPosition();
			auto SpanPos = Pos - m_SelectPoint;

			if (PtrDraw->HitTestStaticMeshSegmentTriangles(Near, Far, HitPoint, tri)) {
				Pos = HitPoint + SpanPos;
				GetComponent<Transform>()->SetPosition(Pos);
				m_SelectPoint = HitPoint;
			}
		}
	}


	void StageObject::SetParamaters(const StParams& param){
		m_StParams = param;
		auto PtrTrans = GetComponent<Transform>();
		PtrTrans->SetScale(m_StParams.m_Scale);
		PtrTrans->SetRotation(m_StParams.m_Rotation);
		PtrTrans->SetPosition(m_StParams.m_Position);

		//�`��R���|�[�l���g�̐ݒ�
		auto PtrDraw = AddComponent<BcPNTStaticDraw>();
		PtrDraw->SetFogEnabled(true);
		//�`�悷�郁�b�V����ݒ�
		switch (m_StParams.m_ShapeType) {
			case StShapeType::Square:
				PtrDraw->SetMeshResource(L"DEFAULT_SQUARE");
				break;
			case StShapeType::Cube:
				PtrDraw->SetMeshResource(L"DEFAULT_CUBE");
				break;
			case StShapeType::Sphere:
				PtrDraw->SetMeshResource(L"DEFAULT_SPHERE");
				break;
			case StShapeType::Capsule:
				PtrDraw->SetMeshResource(L"DEFAULT_CAPSULE");
				break;
			case StShapeType::Cylinder:
				PtrDraw->SetMeshResource(L"DEFAULT_CYLINDER");
				break;
			case StShapeType::Cone:
				PtrDraw->SetMeshResource(L"DEFAULT_CONE");
				break;
			case StShapeType::Torus:
				PtrDraw->SetMeshResource(L"DEFAULT_TORUS");
				break;
			case StShapeType::Tetrahedron:
				PtrDraw->SetMeshResource(L"DEFAULT_TETRAHEDRON");
				break;
			case StShapeType::Octahedron:
				PtrDraw->SetMeshResource(L"DEFAULT_OCTAHEDRON");
				break;
			case StShapeType::Dodecahedron:
				PtrDraw->SetMeshResource(L"DEFAULT_DODECAHEDRON");
				break;
			case StShapeType::Icosahedron:
				PtrDraw->SetMeshResource(L"DEFAULT_ICOSAHEDRON");
				break;
			default:
				break;
		}
		//��������
		SetAlphaActive(true);
	}

	void StageObject::SetSelected(bool b) {
		m_Selected = b;
		auto PtrDraw = AddComponent<BcPNTStaticDraw>();
		if (b) {
			PtrDraw->SetEmissive(Col4(1.0f, 1.0f, 0, 0));
		}
		else {
			PtrDraw->SetEmissive(Col4(0.0f, 0.0f, 0, 0));
		}

	}


	bool StageObject::IsHitSegmentTriangles(const Vec3& StartPos, const Vec3& EndPos, Vec3& HitPoint) {
		auto PtrDraw = GetComponent<BcPNTStaticDraw>();
		TRIANGLE tri;
		if (PtrDraw->HitTestStaticMeshSegmentTriangles(StartPos, EndPos, HitPoint, tri)) {
			m_SelectPoint = HitPoint;
			return true;
		}
		else {
			m_SelectPoint = Vec3(0);
			return false;
		}
	}


}
//end basecross
