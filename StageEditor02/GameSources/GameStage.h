/*!
@file GameStage.h
@brief �Q�[���X�e�[�W
*/

#pragma once
#include "stdafx.h"
#include "Project.h"

namespace basecross {

struct StParams;

//--------------------------------------------------------------------------------------
//	�Q�[���X�e�[�W�N���X
//--------------------------------------------------------------------------------------
class GameStage : public Stage {
	//�r���[�̍쐬
	void CreateViewLight();
	//�^�C�����O�v���[�g�̍쐬
	void CreateTilingPlate();
	//���C���̍쐬
	void CreateActionLine();
	//�v���C���[�̍쐬
	void CreatePlayer();
	//�}�E�X�ʒu
	Point2D<int> m_MousePoint;
public:
	//�\�z�Ɣj��
	GameStage() :Stage(), m_MousePoint(0, 0) {}
	virtual ~GameStage() {}
	//������
	virtual void OnCreate()override;
	//�X�V
	virtual void OnUpdate()override;
	//�ȉ�Windows�A�v���Ƃ̃C���^�[�t�F�C�X
	void InsertNewObject(const StParams& param);
	//�}�E�X�ɂ��I�u�W�F�N�g�I���̃N���A
	void SelectClear();
	//�}�E�X�ƃJ�����̃��C�̎擾
	void GetMouseRay(Vec3& Near, Vec3& Far);
	//�}�E�X�̍��{�^��(�������u��)
	void OnLButtonEnter();
	//�}�E�X�̍��{�^��(������)
	void OnLButtonUp();
	//�}�E�X��L�{�^����������Ă��邩
	bool IsLButtonDown();

	shared_ptr<GameObject> m_SelectObj;

	shared_ptr<GameObject> GetSelectObj() {
		return m_SelectObj;
	}
};
}
//end basecross

