// CompomentEdit.cpp : 実装ファイル
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "StageEditor.h"
#include "CompomentEdit.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Project.h"
using namespace basecross;
// CompomentEdit ダイアログ

IMPLEMENT_DYNAMIC(CompomentEdit, CDialogEx)

CompomentEdit::CompomentEdit(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AddCompoment, pParent)
	, m_CompomentName(_T("")) {
}

CompomentEdit::~CompomentEdit()
{
}
//------------------------------------------
//	0	CollisionSphere
//	1	CollisionCapsule
//	2	CollisionObb
//	3	CollisionTriangles
//	4	CollisionRect
//	5	Gravity
//	6
//	7
//------------------------------------------
BOOL CompomentEdit::OnInitDialog() {
	CDialog::OnInitDialog();
	//リジットは初期でついてるようなので無視
	m_CCompoment = (CComboBox *)GetDlgItem(IDC_AddCompoment);
	m_CCompoment->AddString(L"CollisionSphere");
	m_CCompoment->AddString(L"CollisionCapsule");
	m_CCompoment->AddString(L"CollisionObb");
	m_CCompoment->AddString(L"CollisionTriangles");
	m_CCompoment->AddString(L"CollisionRect");
	m_CCompoment->AddString(L"Gravity");
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
	ON_BN_CLICKED(IDOK, &CompomentEdit::OnBnClickedOk)
END_MESSAGE_MAP()


// CompomentEdit メッセージ ハンドラー


void CompomentEdit::OnBnClickedOk() {
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CDialogEx::OnOK();
	auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
	auto SeleObj = stage->GetSelectObj();
	int num = m_CCompoment->GetCurSel();
	if (SeleObj) {
		switch (num) {
		case 0:
			SeleObj->AddComponent<CollisionSphere>();
			break;
		case 1:
			SeleObj->AddComponent< CollisionCapsule>();
			break;
		default:
			break;
		}
	}
}
