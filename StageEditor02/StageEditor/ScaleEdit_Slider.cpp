// ScaleEdit_Slider.cpp : 実装ファイル
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "StageEditor.h"
#include "ScaleEdit_Slider.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Project.h"


// ScaleEdit_Slider ダイアログ

IMPLEMENT_DYNAMIC(ScaleEdit_Slider, CDialogEx)

ScaleEdit_Slider::ScaleEdit_Slider(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChangeScale, pParent)
	, Scale_X(0), Scale_Y(0), Scale_Z(0) {

}

ScaleEdit_Slider::~ScaleEdit_Slider()
{
}

void ScaleEdit_Slider::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Slider(pDX, IDC_SLIDER_SCALE_X, Scale_X);
	DDX_Slider(pDX, IDC_SLIDER_SCALE_Y, Scale_Y);
	DDX_Slider(pDX, IDC_SLIDER_SCALE_Z, Scale_Z);
}


BEGIN_MESSAGE_MAP(ScaleEdit_Slider, CDialogEx)
END_MESSAGE_MAP()


// ScaleEdit_Slider メッセージ ハンドラー
