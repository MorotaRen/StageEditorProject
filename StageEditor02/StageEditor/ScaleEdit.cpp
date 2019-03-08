// ScaleEdit.cpp : 実装ファイル
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "StageEditor.h"
#include "ScaleEdit.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Project.h"

using namespace basecross;

// ScaleEdit ダイアログ

IMPLEMENT_DYNAMIC(ScaleEdit, CDialogEx)

ScaleEdit::ScaleEdit(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChangeScale, pParent)
	, m_ScaleX(1.0f)
	, m_ScaleY(1.0f)
	, m_ScaleZ(1.0f)
{

}

ScaleEdit::~ScaleEdit()
{
}

void ScaleEdit::OnAppAbout() {
	ScaleEdit aboutDlg;
	aboutDlg.DoModal();
}

void ScaleEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ScaleEDIT_X, m_ScaleX);
	DDX_Text(pDX, IDC_ScaleEDIT_Y, m_ScaleY);
	DDX_Text(pDX, IDC_ScaleEDIT_Z, m_ScaleZ);
	//UpdateData(TRUE);
}


BEGIN_MESSAGE_MAP(ScaleEdit, CDialogEx)
	ON_EN_UPDATE(IDC_ScaleEDIT_X, &ScaleEdit::OnEnKillScaleEDIT_X)
	ON_EN_UPDATE(IDC_ScaleEDIT_Y, &ScaleEdit::OnEnKillScaleEDIT_Y)
	ON_EN_UPDATE(IDC_ScaleEDIT_Z, &ScaleEdit::OnEnKillScaleEDIT_Z)
	ON_BN_CLICKED(IDOK, &ScaleEdit::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ScaleEdit::OnBnClickedCancel)
END_MESSAGE_MAP()


// ScaleEdit メッセージ ハンドラー
void ScaleEdit::OnBnClickedOk() {
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CDialogEx::OnOK();
}

void ScaleEdit::OnBnClickedCancel(){
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	CDialogEx::OnCancel();
}

void ScaleEdit::OnBowDress(CWnd *pParent) {

}
void ScaleEdit::OnEnKillScaleEDIT_X() {
	UpdateData(TRUE);

	auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
	auto SeleObj = stage->GetSelectObj();
	StParams params;
	params.m_Scale.x = m_ScaleX;
	params.m_Scale.y = m_ScaleY;
	params.m_Scale.z = m_ScaleZ;
	SeleObj->GetComponent<Transform>()->SetScale(params.m_Scale.x, params.m_Scale.y, params.m_Scale.z);

}
void ScaleEdit::OnEnKillScaleEDIT_Y() {
	UpdateData(TRUE);

	auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
	auto SeleObj = stage->GetSelectObj();
	StParams params;
	params.m_Scale.x = m_ScaleX;
	params.m_Scale.y = m_ScaleY;
	params.m_Scale.z = m_ScaleZ;
	SeleObj->GetComponent<Transform>()->SetScale(params.m_Scale.x, params.m_Scale.y, params.m_Scale.z);

}
void ScaleEdit::OnEnKillScaleEDIT_Z() {
	UpdateData(TRUE);

	auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
	auto SeleObj = stage->GetSelectObj();
	StParams params;
	params.m_Scale.x = m_ScaleX;
	params.m_Scale.y = m_ScaleY;
	params.m_Scale.z = m_ScaleZ;
	SeleObj->GetComponent<Transform>()->SetScale(params.m_Scale.x, params.m_Scale.y, params.m_Scale.z);

}



void ScaleEdit::OnScale() {
	ScaleEdit dialog;
	if (dialog.DoModal() == IDOK) {
		UpdateData(TRUE);

		auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
		auto SeleObj = stage->GetSelectObj();
		StParams params;
		params.m_Scale.x = m_ScaleX;
		params.m_Scale.y = m_ScaleY;
		params.m_Scale.z = m_ScaleZ;
		SeleObj->GetComponent<Transform>()->SetScale(params.m_Scale.x, params.m_Scale.y, params.m_Scale.z);

	}
}
