
// calculatorDlg.h : ���Y��
//

#pragma once


// CcalculatorDlg ��ܤ��
class CcalculatorDlg : public CDialogEx
{
// �غc
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
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
