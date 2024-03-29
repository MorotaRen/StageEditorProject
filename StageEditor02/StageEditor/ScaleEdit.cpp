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
//----------------------------------------------
//	コンストラクタ
//----------------------------------------------
ScaleEdit::ScaleEdit(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChangeScale, pParent)
	, m_ScaleX(1.0f)
	, m_ScaleY(1.0f)
	, m_ScaleZ(1.0f)
	, Text_valueY(_T("")), Text_valueZ(_T(""))
{
	//StaticTextに値を反映
	Text_valueX.Format(_T("%.2f"), m_ScaleX);
	Text_valueY.Format(_T("%.2f"), m_ScaleY);
	Text_valueZ.Format(_T("%.2f"), m_ScaleZ);

}

//----------------------------------------------
//	デストラクタ
//----------------------------------------------
ScaleEdit::~ScaleEdit()
{
}

//----------------------------------------------
//	サブから開く時に使用
//----------------------------------------------
void ScaleEdit::OnAppAbout() {

}

//----------------------------------------------
//	ウィンドウが生成されたら起動する関数
//----------------------------------------------
BOOL ScaleEdit::OnInitDialog() {

	CDialogEx::OnInitDialog();
	SliderXCtrl.SetRange(1, 100);
	SliderXCtrl.SetPos((int)m_ScaleX);
	SliderYCtrl.SetRange(1, 100);
	SliderYCtrl.SetPos((int)m_ScaleY);
	SliderZCtrl.SetRange(1, 100);
	SliderZCtrl.SetPos((int)m_ScaleZ);
	UpdateData(FALSE);
	return TRUE;
}

//----------------------------------------------
//	リソースIDとの関連付け
//----------------------------------------------
void ScaleEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ScaleEDIT_X, m_ScaleX);
	DDX_Text(pDX, IDC_ScaleEDIT_Y, m_ScaleY);
	DDX_Text(pDX, IDC_ScaleEDIT_Z, m_ScaleZ);

	DDX_Text(pDX, IDC_STATIC_X, Text_valueX);
	DDX_Text(pDX, IDC_STATIC_Y, Text_valueY);
	DDX_Text(pDX, IDC_STATIC_Z, Text_valueZ);


	DDX_Control(pDX, IDC_STATIC_X, Text_X);
	DDX_Control(pDX, IDC_STATIC_Y, Text_Y);
	DDX_Control(pDX, IDC_STATIC_Z, Text_Z);

	DDX_Control(pDX, IDC_SLIDER_SCALE_X, SliderXCtrl);
	DDX_Control(pDX, IDC_SLIDER_SCALE_Y, SliderYCtrl);
	DDX_Control(pDX, IDC_SLIDER_SCALE_Z, SliderZCtrl);

}

//----------------------------------------------
//	メッセージマップの宣言
//	UPDATE：リアルタイム更新
//	HSCROLL：横slider実装
//----------------------------------------------
BEGIN_MESSAGE_MAP(ScaleEdit, CDialogEx)
	ON_EN_UPDATE(IDC_ScaleEDIT_X, &ScaleEdit::OnEnKillScaleEDIT)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

//----------------------------------------------
//	入力された数値を反映
//----------------------------------------------
void ScaleEdit::OnEnKillScaleEDIT() {
	UpdateData(TRUE);
	auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
	auto SeleObj = stage->GetSelectObj();
	StParams params;
	params.m_Scale.x = m_ScaleX;
	params.m_Scale.y = m_ScaleY;
	params.m_Scale.z = m_ScaleZ;
	SliderXCtrl.SetPos((int)params.m_Scale.x);
	SliderYCtrl.SetPos((int)params.m_Scale.y);
	SliderZCtrl.SetPos((int)params.m_Scale.z);
	Text_valueX.Format(_T("%2f"), params.m_Scale.x);
	Text_valueY.Format(_T("%2f"), params.m_Scale.y);
	Text_valueZ.Format(_T("%2f"), params.m_Scale.z);
	UpdateData(FALSE);
	if (SeleObj != NULL) {
		SeleObj->GetComponent<Transform>()->SetScale(params.m_Scale.x, params.m_Scale.y, params.m_Scale.z);
	}
}

//----------------------------------------------
//	スクロールが動いた時の数値反映
//----------------------------------------------
void ScaleEdit::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) {

	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
		auto stage = App::GetApp()->GetScene<Scene>()->GetActiveTypeStage<GameStage>();
		auto SeleObj = stage->GetSelectObj();
		StParams params;
		m_ScaleX = (float)SliderXCtrl.GetPos();
		m_ScaleY = (float)SliderYCtrl.GetPos();
		m_ScaleZ = (float)SliderZCtrl.GetPos();
		Text_valueX.Format(_T("%2f"), (float)m_ScaleX);
		Text_valueY.Format(_T("%2f"), (float)m_ScaleY);
		Text_valueZ.Format(_T("%2f"), (float)m_ScaleZ);
		UpdateData(FALSE);
		if (SeleObj) {
			SeleObj->GetComponent<Transform>()->SetScale(m_ScaleX, m_ScaleY, m_ScaleZ);
		}
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);

}