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
	afx_msg void OnEnChangeEditposx();
	CString m_PosX;
	CString m_PosY;
	CString m_PosZ;
};
