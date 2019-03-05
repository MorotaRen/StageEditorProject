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
	enum { IDD = IDD_Scale };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	// XのScale値
	float  m_ScaleX;
	float  m_ScaleY;
	float  m_ScaleZ;
	afx_msg void OnAppAbout();
	afx_msg void OnBnClickedOk();
	afx_msg void ScaleEditXYZ();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBowDress(CWnd *pParent);
	//virtual BOOL OnIdle(LONG lCount);
	afx_msg void OnEnKillScaleEDIT_X();
	afx_msg void OnEnKillScaleEDIT_Y();
	afx_msg void OnEnKillScaleEDIT_Z();
};
