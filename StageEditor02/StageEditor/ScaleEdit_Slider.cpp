// ScaleEdit_Slider.cpp : 実装ファイル
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "StageEditor.h"
#include "ScaleEdit_Slider.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Project.h"

using namespace basecross;
// ScaleEdit_Slider ダイアログ

IMPLEMENT_DYNAMIC(ScaleEdit_Slider, CDialogEx)

ScaleEdit_Slider::ScaleEdit_Slider(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChangeScale, pParent)
	, m_Scale_X(1), m_Scale_Y(1), m_Scale_Z(1){
}

ScaleEdit_Slider::~ScaleEdit_Slider()
{
}
BOOL ScaleEdit_Slider::InitInstance() {
	SliderXCtrl = (CSliderCtrl*)GetDlgItem(IDC_SLIDER_SCALE_X);
	SliderXCtrl->SetRange(1,10);
	return TRUE;
}
void ScaleEdit_Slider::OnAppAbout() {
	ScaleEdit_Slider aboutDlg;
	aboutDlg.DoModal();
}
void ScaleEdit_Slider::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER_SCALE_X, m_Scale_X);
	DDX_Slider(pDX, IDC_SLIDER_SCALE_Y, m_Scale_Y);
	DDX_Slider(pDX, IDC_SLIDER_SCALE_Z, m_Scale_Z);
}


BEGIN_MESSAGE_MAP(ScaleEdit_Slider, CDialogEx)
	ON_EN_UPDATE(IDC_SLIDER_SCALE_X,&ScaleEdit_Slider::OnEnKillScaleEDIT_X)
	ON_EN_UPDATE(IDC_SLIDER_SCALE_Y,&ScaleEdit_Slider::OnEnKillScaleEDIT_Y)
	ON_EN_UPDATE(IDC_SLIDER_SCALE_Z,&ScaleEdit_Slider::OnEnKillScaleEDIT_Z)
END_MESSAGE_MAP()

void ScaleEdit_Slider::OnEnKillScaleEDIT_X() {
	UpdateData(TRUE);

	auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
	auto SeleObj = stage->GetSelectObj();
	StParams params;
	m_Scale_X = SliderXCtrl->GetPos();
	SeleObj->GetComponent<Transform>()->SetScale(params.m_Scale.x, params.m_Scale.y, params.m_Scale.z);

}
void ScaleEdit_Slider::OnEnKillScaleEDIT_Y() {
	UpdateData(TRUE);

	auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
	auto SeleObj = stage->GetSelectObj();
	StParams params;
	params.m_Scale.y = m_Scale_Y;
	SeleObj->GetComponent<Transform>()->SetScale(params.m_Scale.x, params.m_Scale.y, params.m_Scale.z);

}
void ScaleEdit_Slider::OnEnKillScaleEDIT_Z() {
	UpdateData(TRUE);

	auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
	auto SeleObj = stage->GetSelectObj();
	StParams params;
	params.m_Scale.z = m_Scale_Z;
	SeleObj->GetComponent<Transform>()->SetScale(params.m_Scale.x, params.m_Scale.y, params.m_Scale.z);

}

// ScaleEdit_Slider メッセージ ハンドラー
