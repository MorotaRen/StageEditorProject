// CChangePosDialog.cpp : 実装ファイル
//

#include "stdafx.h"
#include "CChangePosDialog.h"
#include "afxdialogex.h"
#include "Project.h"
#include "StageEditor.h"


// CChangePosDialog ダイアログ

IMPLEMENT_DYNAMIC(CChangePosDialog, CDialogEx)

CChangePosDialog::CChangePosDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChangePos, pParent)
	, m_PosX(_T(""))
	, m_PosY(_T(""))
	, m_PosZ(_T(""))
{

}

CChangePosDialog::~CChangePosDialog()
{
}

void CChangePosDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITPOSX, m_PosX);
	DDX_Text(pDX, IDC_EDITPOSY, m_PosY);
	DDX_Text(pDX, IDC_EDITPOSZ, m_PosZ);
}


BEGIN_MESSAGE_MAP(CChangePosDialog, CDialogEx)
	ON_EN_CHANGE(IDC_EDITPOSX, &CChangePosDialog::OnEnChangeEditposx)
END_MESSAGE_MAP()


// CChangePosDialog メッセージ ハンドラー


void CChangePosDialog::OnEnChangeEditposx()
{
	// TODO: これが RICHEDIT コントロールの場合、このコントロールが
	// この通知を送信するには、CDialogEx::OnInitDialog() 関数をオーバーライドし、
	// CRichEditCtrl().SetEventMask() を関数し呼び出します。
	// OR 状態の ENM_CHANGE フラグをマスクに入れて呼び出す必要があります。

	// TODO: ここにコントロール通知ハンドラー コードを追加してください。
}
