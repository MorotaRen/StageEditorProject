
// StageEditor.h : StageEditor �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CStageEditorApp:
// ���̃N���X�̎����ɂ��ẮAStageEditor.cpp ���Q�Ƃ��Ă��������B
//

class CStageEditorApp : public CWinApp
{
	HWND m_DxHWnd;
public:
	CStageEditorApp();
	void CreateAppScene(HWND hWnd);


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnIdle(LONG lCount);
	afx_msg void OnObjProp();
	afx_msg void OnSaveData();
};

extern CStageEditorApp theApp;
