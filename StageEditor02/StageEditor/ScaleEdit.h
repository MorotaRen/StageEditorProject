#pragma once


// ScaleEdit ダイアログ

class ScaleEdit : public CDialogEx
{
	DECLARE_DYNAMIC(ScaleEdit)

public:
	ScaleEdit(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~ScaleEdit();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ChangeScale
	};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	// XのScale値
	int m_Scale_X;
	int m_Scale_Y;
	int m_Scale_Z;
	float  m_ScaleX;
	float  m_ScaleY;
	float  m_ScaleZ;
	afx_msg void OnAppAbout();
	afx_msg void OnBnClickedOk();
	afx_msg void ScaleEditXYZ();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBowDress(CWnd *pParent);
	afx_msg void OnEnKillScaleEDIT_X();
	afx_msg void OnEnKillScaleEDIT_Y();
	afx_msg void OnEnKillScaleEDIT_Z();
	afx_msg void OnScale();
	CSliderCtrl SliderXCtrl;
	CStatic Text_X;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnInitDialog();

	CString Text_value;
};
