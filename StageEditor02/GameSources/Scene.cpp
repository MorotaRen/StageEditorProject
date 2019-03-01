
/*!
@file Scene.cpp
@brief �V�[������
*/

#include "stdafx.h"
#include "Project.h"

namespace basecross {

	//--------------------------------------------------------------------------------------
	///	�Q�[���V�[��
	//--------------------------------------------------------------------------------------

	void Scene::CreateResourses() {
		wstring DataDir;
		//�e�Q�[���͈ȉ��̂悤�Ƀf�[�^�f�B���N�g�����擾���ׂ�
		App::GetApp()->GetDataDirectory(DataDir);
		wstring strTexture = DataDir + L"plate.png";
		App::GetApp()->RegisterTexture(L"PLATE_TX", strTexture);
	}


	void Scene::OnCreate() {
		try {
			//���\�[�X�쐬
			CreateResourses();
			//�ŏ��̃A�N�e�B�u�X�e�[�W�̐ݒ�
			ResetActiveStage<GameStage>();
		}
		catch (...) {
			throw;
		}
	}

	void Scene::InsertNewObject(const StParams& param) {
		auto GameStagePtr = GetActiveTypeStage<GameStage>();
		GameStagePtr->InsertNewObject(param);
	}




}
//end basecross
