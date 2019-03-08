#pragma once


// ScaleEdit_Slider ダイアログ

class ScaleEdit_Slider : public CDialogEx
{
	DECLARE_DYNAMIC(ScaleEdit_Slider)

public:
	ScaleEdit_Slider(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~ScaleEdit_Slider();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ChangeScale };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL InitInstance();

	int m_Scale_X;
	int m_Scale_Y;
	int m_Scale_Z;
	afx_msg void OnEnKillScaleEDIT_X();
	afx_msg void OnEnKillScaleEDIT_Y();
	afx_msg void OnEnKillScaleEDIT_Z();
	afx_msg void OnAppAbout();
	CSliderCtrl* SliderXCtrl;
};
