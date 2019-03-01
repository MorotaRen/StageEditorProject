// ObjPropDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "StageEditor.h"
#include "ObjPropDlg.h"
#include "afxdialogex.h"


// CObjPropDlg ダイアログ

IMPLEMENT_DYNAMIC(CObjPropDlg, CDialogEx)

CObjPropDlg::CObjPropDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLG_OBJ_PROP, pParent),
	m_IsNew(false)
	, m_ShapeIndex(0)
	, m_ScaleX(1.0f)
	, m_ScaleY(1.0f)
	, m_ScaleZ(1.0f)
	, m_RotateX(0)
	, m_RotateY(0)
	, m_RotateZ(0)
	, m_PositionX(0)
	, m_PositionY(0)
	, m_PositionZ(0)
	, m_ClsName(_T(""))
{
	m_StShapeWithStrVec =
	{
		{ StShapeType::Square,L"平面" },
		{ StShapeType::Cube,L"ボックス" },
		{ StShapeType::Sphere,L"球" },
		{ StShapeType::Capsule,L"カプセル" },
		{ StShapeType::Cylinder,L"シリンダー" },
		{ StShapeType::Cone,L"コーン" },
		{ StShapeType::Torus,L"トーラス" },
		{ StShapeType::Tetrahedron,L"正四面体" },
		{ StShapeType::Octahedron,L"正八面体" },
		{ StShapeType::Dodecahedron,L"正十二面体" },
		{ StShapeType::Icosahedron,L"正二十面体" },
	};

}

CObjPropDlg::~CObjPropDlg()
{
}

void CObjPropDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SELECTOBJ_COMBO, m_SelectObjCombo);
	DDX_Text(pDX, IDC_SCALE_X_EDIT, m_ScaleX);
	DDX_Text(pDX, IDC_SCALE_Y_EDIT, m_ScaleY);
	DDX_Text(pDX, IDC_SCALE_Z_EDIT, m_ScaleZ);
	DDX_Text(pDX, IDC_ROTATE_X_EDIT, m_RotateX);
	DDX_Text(pDX, IDC_ROTATE_Y_EDIT, m_RotateY);
	DDX_Text(pDX, IDC_ROTATE_Z_EDIT, m_RotateZ);
	DDX_Text(pDX, IDC_POSITION_X_EDIT, m_PositionX);
	DDX_Text(pDX, IDC_POSITION_Y_EDIT, m_PositionY);
	DDX_Text(pDX, IDC_POSITION_Z_EDIT, m_PositionZ);
	DDX_Text(pDX, IDC_CLASS_NAME_EDIT, m_ClsName);
}


BEGIN_MESSAGE_MAP(CObjPropDlg, CDialogEx)
END_MESSAGE_MAP()


// CObjPropDlg メッセージ ハンドラー


BOOL CObjPropDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO: ここに初期化を追加してください
	if (m_IsNew) {
		SetWindowText(L"新規");
	}
	else {
		SetWindowText(L"プロパティ");
	}

	for (size_t i = 0; i < m_StShapeWithStrVec.size(); i++) {
		m_SelectObjCombo.InsertString(i, m_StShapeWithStrVec[i].m_Str.c_str());
	}
	m_SelectObjCombo.SetCurSel(0);


	UpdateData(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 例外 : OCX プロパティ ページは必ず FALSE を返します。
}


void CObjPropDlg::OnOK()
{
	// TODO: ここに特定なコードを追加するか、もしくは基底クラスを呼び出してください。
	UpdateData(TRUE);

	m_ShapeIndex = m_SelectObjCombo.GetCurSel();

	CDialogEx::OnOK();
}
