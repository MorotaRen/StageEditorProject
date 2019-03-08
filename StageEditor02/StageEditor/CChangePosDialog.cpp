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
}


BEGIN_MESSAGE_MAP(CChangePosDialog, CDialogEx)
	ON_EN_UPDATE(IDC_EDITPOSX, &CChangePosDialog::OnEnUpdateEditposx)
	ON_EN_UPDATE(IDC_EDITPOSY, &CChangePosDialog::OnUpdateEditposy)
	ON_EN_UPDATE(IDC_EDITPOSZ, &CChangePosDialog::OnUpdateEditposz)
	ON_BN_CLICKED(IDOK, &CChangePosDialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CChangePosDialog::OnBnClickedCancel)
	ON_COMMAND(ID_32780, &CChangePosDialog::ChangePos)
END_MESSAGE_MAP()


// CChangePosDialog メッセージ ハンドラー


void CChangePosDialog::OnEnUpdateEditposx()
{
	UpdateData(TRUE);

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


//void CChangePosDialog::ChangePos_MS()
//{
//	CChangePosDialog dialog;
//	if (dialog.DoModal() == IDOK) {
//		;
//	}
//	// TODO: ここにコマンド ハンドラー コードを追加します。
//}
