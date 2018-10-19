
// calculatorDlg.h : 標頭檔
//

#pragma once


// CcalculatorDlg 對話方塊
class CcalculatorDlg : public CDialogEx
{
// 建構
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CString mmm;


	void cal(int action);
	CString m_num1, m_num2;
	int m_p , m_q, m_action = 0, m_preaction;
public:
	afx_msg void OnBnClickedButton1();
	
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButtonequal();
	afx_msg void OnBnClickedButtonplus();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButtonmuti();
	afx_msg void OnBnClickedButtondivide();
	afx_msg void OnBnClickedButtoncancle();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButtonminus();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
};
