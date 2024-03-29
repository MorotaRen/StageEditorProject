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
	, m_CompomentName(_T("")), m_CompomentText(_T("コンポーネントの説明文が表示されます")) {
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
	DDX_Text(pDX, IDC_STATICCompomentText, m_CompomentText);
}


BEGIN_MESSAGE_MAP(CompomentEdit, CDialogEx)
	ON_BN_CLICKED(IDOK, &CompomentEdit::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_AddCompoment, &CompomentEdit::OnCbnEditchangeAddcompoment)
END_MESSAGE_MAP()

void CompomentEdit::Update() {

}

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
			SeleObj->AddComponent<CollisionCapsule>();
			break;
		case 2:
			SeleObj->AddComponent<CollisionObb>();
			break;
		case 3:
			SeleObj->AddComponent<CollisionTriangles>();
			break;
		case 4:
			SeleObj->AddComponent<CollisionRect>();
			break;
		case 5:
			break;
		default:
			break;
		}
	}
}

void CompomentEdit::OnCbnEditchangeAddcompoment() {
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	int num = m_CCompoment->GetCurSel();
	switch (num) {
	case 0:
		m_CompomentText.Format((_T("%s"), L"Sphere型のCollision"));
		UpdateData(FALSE);
		break;
	case 1:
		m_CompomentText.Format((_T("%s"), L"Capsule型のCollision"));
		UpdateData(FALSE);
		break;
	case 2:
		m_CompomentText.Format((_T("%s"), L"Obb型のCollision"));
		UpdateData(FALSE);
		break;
	case 3:
		m_CompomentText.Format((_T("%s"), L"Triangles型のCollision"));
		UpdateData(FALSE);
		break;
	case 4:
		m_CompomentText.Format((_T("%s"), L"Rect型のCollision"));
		UpdateData(FALSE);
		break;
	case 5:
		m_CompomentText.Format((_T("%s"), L"重力を追加"));
		UpdateData(FALSE);
		break;
	default:
		m_CompomentText.Format((_T("%s"), L"コンポーネントの説明文が表示されます"));
		UpdateData(FALSE);
		break;
	}
}
