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
	int Scale_X;
	int Scale_Y;
	int Scale_Z;
};
