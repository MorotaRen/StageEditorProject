#pragma once

#include "Project.h"
#include "afxwin.h"
using namespace basecross;


struct StShapeWithStr {
	StShapeType m_StShapeType;
	wstring m_Str;
	StShapeWithStr() {}
	StShapeWithStr(StShapeType t, const wstring& s) :
		m_StShapeType(t),
		m_Str(s) {}
};

// CObjPropDlg ダイアログ

class CObjPropDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CObjPropDlg)
	bool m_IsNew;
public:
	CObjPropDlg(CWnd* pParent = NULL);   // 標準コンストラクター
	virtual ~CObjPropDlg();
	void SetNew(bool b) {
		m_IsNew = b;
	}
	vector<StShapeWithStr> m_StShapeWithStrVec;
// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_OBJ_PROP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_SelectObjCombo;
	virtual void OnOK();
	float m_ScaleX;
	float m_ScaleY;
	float m_ScaleZ;
	float m_RotateX;
	float m_RotateY;
	float m_RotateZ;
	float m_PositionX;
	float m_PositionY;
	float m_PositionZ;
	int m_ShapeIndex;
	CString m_ClsName;
};
