
// MainFrm.cpp : CMainFrame �N���X�̎���
//

#include "stdafx.h"
#include "StageEditor.h"

#include "MainFrm.h"
#include "Project.h"
#include "ScaleEdit.h"

using namespace basecross;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
END_MESSAGE_MAP()

// CMainFrame �R���X�g���N�V����/�f�X�g���N�V����

CMainFrame::CMainFrame()
{
	// TODO: �����o�[�������R�[�h�������ɒǉ����Ă��������B
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// �t���[���̃N���C�A���g�̈�S�̂��߂�r���[���쐬���܂��B
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW,
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("�r���[ �E�B���h�E���쐬�ł��܂���ł����B\n");
		return -1;
	}

	//�A�v���P�[�V�����N���X�ƃf�o�C�X�V�[���̍쐬
	try {
		((CStageEditorApp*)AfxGetApp())->CreateAppScene(m_wndView.GetSafeHwnd());
	}
	catch (BaseException& e) {
		AfxMessageBox(e.what_w().c_str());
		return -1;
	}
	catch (BaseMBException& e) {
		MessageBoxA(nullptr, e.what_m().c_str(), "�G���[", MB_OK);
		return -1;
	}
	catch (exception& e) {
		MessageBoxA(nullptr, e.what(), "�G���[", MB_OK);
		return -1;
	}
	catch (...) {
		//�����s�����s����
		AfxMessageBox(L"�����s���̃G���[�ł�");
		return -1;
	}

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B
	CRect rect = { 0, 0,1280, 800 };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, TRUE);
	cs.cx = rect.Width();
	cs.cy = rect.Height();

	//cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
	//	 | WS_THICKFRAME | WS_MINIMIZEBOX | WS_SYSMENU;

	cs.style = WS_OVERLAPPED | WS_CAPTION | FWS_ADDTOTITLE
		|  WS_MINIMIZEBOX | WS_SYSMENU;


	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	ScaleEdit* se = new ScaleEdit(this);
	se->Create(IDD_ChangeScale,this);
	se->ShowWindow(SW_SHOW);

	return TRUE;
}

// CMainFrame �f�f

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ���b�Z�[�W �n���h���[

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// �r���[ �E�B���h�E�Ƀt�H�[�J�X��^���܂��B
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// �r���[�ɍŏ��ɃR�}���h����������@���^���܂��B
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// ����ȊO�̏ꍇ�́A����̏������s���܂��B
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

