#pragma once


// CompomentEdit ダイアログ

class CompomentEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CompomentEdit)

public:
	CompomentEdit(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CompomentEdit();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AddCompoment };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnAppAbout();
	// コンポーネントの制御変数
	CComboBox* m_CCompoment;
	// コンポーネントの名前
	CString m_CompomentName;
	//継承関数
	virtual BOOL OnInitDialog();
	afx_msg void Update();
	afx_msg void OnBnClickedOk();
	// コンポーネントの説明文
	CString m_CompomentText;
	afx_msg void OnCbnEditchangeAddcompoment();
};
