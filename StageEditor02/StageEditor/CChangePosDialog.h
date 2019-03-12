#pragma once


// CChangePosDialog ダイアログ

class CChangePosDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CChangePosDialog)

public:
	CChangePosDialog(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CChangePosDialog();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ChangePos };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnUpdateEditposx();
	afx_msg void OnAppAbout();
	float m_PosX;
	float m_PosY;
	float m_PosZ;
	afx_msg void OnUpdateEditposy();
	afx_msg void OnUpdateEditposz();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	//afx_msg void ChangePos_MS();
	afx_msg void ChangePos();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	CSliderCtrl m_TestSlider;
	afx_msg void OnUpdateIddChangepos(CCmdUI *pCmdUI);
};
