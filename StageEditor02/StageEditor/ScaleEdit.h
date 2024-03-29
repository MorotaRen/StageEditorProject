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
	//実際座標変更に使われる
	float  m_ScaleX;
	float  m_ScaleY;
	float  m_ScaleZ;
	//sliderの数値保存用
	int m_SliderX;
	int m_SliderY;
	int m_SliderZ;
	//関数
	afx_msg void OnAppAbout();
	afx_msg void OnEnKillScaleEDIT();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//コントロール用
	CSliderCtrl SliderXCtrl;
	CSliderCtrl SliderYCtrl;
	CSliderCtrl SliderZCtrl;
	//テキストコントロール用
	CStatic Text_X;
	CStatic Text_Y;
	CStatic Text_Z;
	// テキストの内容格納変数	// テキストの内容格納変数
	CString Text_valueX;
	CString Text_valueY;
	CString Text_valueZ;
	//継承関数
	virtual BOOL OnInitDialog();
};
