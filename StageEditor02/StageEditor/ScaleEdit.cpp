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
	, m_Scale_X(1)
	, m_Scale_Y(1)
	, m_Scale_Z(1)
{
	Text_value.Format(_T("%.2f"), m_ScaleX);

}

ScaleEdit::~ScaleEdit()
{
}

void ScaleEdit::OnAppAbout() {

}

BOOL ScaleEdit::OnInitDialog() {

	CDialogEx::OnInitDialog();
	SliderXCtrl.SetRange(1, 100);
	SliderXCtrl.SetPos(m_ScaleX);
	UpdateData(FALSE);

	return TRUE;
}
void ScaleEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ScaleEDIT_X, m_ScaleX);
	DDX_Text(pDX, IDC_ScaleEDIT_Y, m_ScaleY);
	DDX_Text(pDX, IDC_ScaleEDIT_Z, m_ScaleZ);
	DDX_Slider(pDX, IDC_SLIDER_SCALE_X, m_Scale_X);
	DDX_Slider(pDX, IDC_SLIDER_SCALE_Y, m_Scale_Y);
	DDX_Slider(pDX, IDC_SLIDER_SCALE_Z, m_Scale_Z);
	DDX_Control(pDX, IDC_SLIDER_SCALE_X, SliderXCtrl);
	DDX_Control(pDX, IDC_STATIC_X, Text_X);
	DDX_Text(pDX, IDC_STATIC_X, Text_value);
}


BEGIN_MESSAGE_MAP(ScaleEdit, CDialogEx)
	ON_EN_UPDATE(IDC_ScaleEDIT_X, &ScaleEdit::OnEnKillScaleEDIT_X)
	ON_EN_UPDATE(IDC_ScaleEDIT_Y, &ScaleEdit::OnEnKillScaleEDIT_Y)
	ON_EN_UPDATE(IDC_ScaleEDIT_Z, &ScaleEdit::OnEnKillScaleEDIT_Z)
	ON_BN_CLICKED(IDOK, &ScaleEdit::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &ScaleEdit::OnBnClickedCancel)
	ON_WM_HSCROLL()

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
void ScaleEdit::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) {

	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	if (pScrollBar == (CScrollBar*)&SliderXCtrl) {
		auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
		auto SeleObj = stage->GetSelectObj();
		StParams params;
		m_Scale_X = SliderXCtrl.GetPos();
		Text_value.Format(_T("%f"), (float)m_Scale_X);
		UpdateData(FALSE);

		SeleObj->GetComponent<Transform>()->SetScale(m_Scale_X, params.m_Scale.y, params.m_Scale.z);
	}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

}

