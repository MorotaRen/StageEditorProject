// CompomentEdit.cpp : 実装ファイル
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "StageEditor.h"
#include "CompomentEdit.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Project.h"

// CompomentEdit ダイアログ

IMPLEMENT_DYNAMIC(CompomentEdit, CDialogEx)

CompomentEdit::CompomentEdit(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AddCompoment, pParent)
	, m_CompomentName(_T("")) {
}

CompomentEdit::~CompomentEdit()
{
}

BOOL CompomentEdit::OnInitDialog() {
	CDialog::OnInitDialog();
	m_CCompoment = (CComboBox *)GetDlgItem(IDC_AddCompoment);
	m_CCompoment->AddString(L"コンポーネント");
	m_CCompoment->AddString(L"コンポーネント");
	return TRUE;
}
void CompomentEdit::OnAppAbout() {
	CompomentEdit aboutDlg;
	aboutDlg.DoModal();
}
void CompomentEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_AddCompoment, m_CompomentName);
}


BEGIN_MESSAGE_MAP(CompomentEdit, CDialogEx)
END_MESSAGE_MAP()


// CompomentEdit メッセージ ハンドラー
