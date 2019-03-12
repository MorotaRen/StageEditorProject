// CChangePosDialog.cpp : 実装ファイル
//

#include "stdafx.h"
#include "CChangePosDialog.h"
#include "afxdialogex.h"
#include "Project.h"
#include "StageEditor.h"
#include "MainFrm.h"
#include "afxwinappex.h"

using namespace basecross;

// CChangePosDialog ダイアログ

IMPLEMENT_DYNAMIC(CChangePosDialog, CDialogEx)

CChangePosDialog::CChangePosDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChangePos, pParent)
	, m_PosX(0.0f)
	, m_PosY(0.0f)
	, m_PosZ(0.0f)
{

	m_TestSlider.SetRange(-5, 5);
	m_TestSlider.SetPos(0);
}

CChangePosDialog::~CChangePosDialog()
{
}

void CChangePosDialog::OnAppAbout() {
	CChangePosDialog aboutDlg;
	aboutDlg.DoModal();
}



void CChangePosDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITPOSX, m_PosX);
	DDX_Text(pDX, IDC_EDITPOSY, m_PosY);
	DDX_Text(pDX, IDC_EDITPOSZ, m_PosZ);
	DDX_Control(pDX, IDC_SLIDER1, m_TestSlider);
}


BEGIN_MESSAGE_MAP(CChangePosDialog, CDialogEx)
	ON_EN_UPDATE(IDC_EDITPOSX, &CChangePosDialog::OnEnUpdateEditposx)
	ON_EN_UPDATE(IDC_EDITPOSY, &CChangePosDialog::OnUpdateEditposy)
	ON_EN_UPDATE(IDC_EDITPOSZ, &CChangePosDialog::OnUpdateEditposz)
	ON_BN_CLICKED(IDOK, &CChangePosDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CChangePosDialog::OnBnClickedCancel)
	ON_COMMAND(ID_32780, &CChangePosDialog::ChangePos)
	ON_WM_HSCROLL()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CChangePosDialog::OnNMCustomdrawSlider1)
	ON_UPDATE_COMMAND_UI(IDD_ChangePos, &CChangePosDialog::OnUpdateIddChangepos)
END_MESSAGE_MAP()


// CChangePosDialog メッセージ ハンドラー


void CChangePosDialog::OnEnUpdateEditposx()
{
	UpdateData(TRUE);
	m_TestSlider.SetRange(-5, 5);
	m_TestSlider.SetPos(m_PosX);

	auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
	auto SeleObj = stage->GetSelectObj();
	StParams params;
	params.m_Position.x = m_PosX;
	params.m_Position.y = m_PosY;
	params.m_Position.z = m_PosZ;
	SeleObj->GetComponent<Transform>()->SetPosition(params.m_Position.x, params.m_Position.y, params.m_Position.z);

}


void CChangePosDialog::OnUpdateEditposy()
{
	// TODO: これが RICHEDIT コントロールの場合、このコントロールが
	// この通知を送信するには、CDialogEx::OnInitDialog() 関数をオーバーライドし、
	// EM_SETEVENTMASK メッセージを、
	// OR 状態の ENM_UPDATE フラグを lParam マスクに入れて、このコントロールに送信する必要があります。

	// TODO: ここにコントロール通知ハンドラー コードを追加してください。
}


void CChangePosDialog::OnUpdateEditposz()
{
	// TODO: これが RICHEDIT コントロールの場合、このコントロールが
	// この通知を送信するには、CDialogEx::OnInitDialog() 関数をオーバーライドし、
	// EM_SETEVENTMASK メッセージを、
	// OR 状態の ENM_UPDATE フラグを lParam マスクに入れて、このコントロールに送信する必要があります。

	// TODO: ここにコントロール通知ハンドラー コードを追加してください。
}


void CChangePosDialog::OnBnClickedOk()
{
	UpdateData(true);
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CDialogEx::OnOK();
}


void CChangePosDialog::OnBnClickedCancel()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CDialogEx::OnCancel();
}


void CChangePosDialog::ChangePos()
{
	CChangePosDialog* dialog = new CChangePosDialog(this);
	dialog->Create(IDD_ChangePos, this);
	dialog->ShowWindow(SW_SHOW);
	//CChangePosDialog dialog;
	//if (dialog.DoModal() == IDOK) {
	//	UpdateData(TRUE);
	//	auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
	//	auto SeleObj = stage->GetSelectObj();
	//	StParams params;

	//}
	// TODO: ここにコマンド ハンドラー コードを追加します。
}


void CChangePosDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	if (pScrollBar == (CScrollBar*)&m_TestSlider) {

		UpdateData(true);
		m_PosX = m_TestSlider.GetPos();
		auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
		auto SeleObj = stage->GetSelectObj();
		StParams params;
		params.m_Position.x = m_PosX;
		params.m_Position.y = m_PosY;
		params.m_Position.z = m_PosZ;
		SeleObj->GetComponent<Transform>()->SetPosition(params.m_Position.x, params.m_Position.y, params.m_Position.z);

		UpdateData(true);
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

}


void CChangePosDialog::OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	*pResult = 0;
}


void CChangePosDialog::OnUpdateIddChangepos(CCmdUI *pCmdUI)
{
	UpdateData(TRUE);
	m_TestSlider.SetRange(-5, 5);
	m_TestSlider.SetPos(m_PosX);
	// TODO:ここにコマンド更新 UI ハンドラー コードを追加します。
}
