
// calculatorDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg 對話方塊



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	, mmm(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mmm);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CcalculatorDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcalculatorDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTONEqual, &CcalculatorDlg::OnBnClickedButtonequal)
	ON_BN_CLICKED(IDC_BUTTONPlus, &CcalculatorDlg::OnBnClickedButtonplus)
	ON_EN_CHANGE(IDC_EDIT1, &CcalculatorDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTONMUTI, &CcalculatorDlg::OnBnClickedButtonmuti)
	ON_BN_CLICKED(IDC_BUTTONDIVIDE, &CcalculatorDlg::OnBnClickedButtondivide)
	ON_BN_CLICKED(IDC_BUTTONCANCLE, &CcalculatorDlg::OnBnClickedButtoncancle)
	ON_BN_CLICKED(IDC_BUTTON5, &CcalculatorDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTONMINUS, &CcalculatorDlg::OnBnClickedButtonminus)
	ON_BN_CLICKED(IDC_BUTTON6, &CcalculatorDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON3, &CcalculatorDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CcalculatorDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON7, &CcalculatorDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CcalculatorDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CcalculatorDlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CcalculatorDlg 訊息處理常式

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CcalculatorDlg::cal(int action)
{
	m_num2 = mmm;
	double num1, num2;
	double num = 0;
	num1 = _tstof(m_num1);
	num2 = _tstof(m_num2);
	switch (action)
	{
	case 1:
		num = num1 + num2;
		break;
	case 2:
		num = num1 - num2;
		break;
	case 3:
		num = num1*num2;
		break;
	case 4:
		if (num2 == 0)
		{
			mmm = "除数不能为0";
			m_q = 1;
		}
		else
			num = num1 / num2;
		break;
	default:break;
	}
	if (m_q == 1)
	{
		UpdateData(FALSE);
	}
	else
	{
		if (num - (int)num == 0)
			mmm.Format(_T("%.0f"), num);
		else
			mmm.Format(_T("%.2f"), num);
		UpdateData(FALSE);
	}
	m_preaction = 0;
}



void CcalculatorDlg::OnBnClickedButton1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	if (m_p == 1)
		mmm = '0';
	if (mmm != '0')
	{
		mmm += '1';
		m_p = 2;
	}
	else
	{
		mmm = '1';
		m_p = 2;
	}
	UpdateData(FALSE);

}



void CcalculatorDlg::OnBnClickedButton2()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	if (m_p == 1)
		mmm = '0';
	if (mmm != '0')
	{
		mmm += '2';
		m_p = 2;
	}
	else
	{
		mmm = '2';
		m_p = 2;
	}
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonequal()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	cal(m_action);
	m_p = 1;
}


void CcalculatorDlg::OnBnClickedButtonplus()
{
	if (m_preaction)
	{
		m_num2 = mmm;
		cal(m_action);
	}
	m_action = 1;
	m_preaction = m_action;
	m_num1 = mmm;
	mmm = '0';
	// TODO: 在此加入控制項告知處理常式程式碼
}


void CcalculatorDlg::OnEnChangeEdit1()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
}




void CcalculatorDlg::OnBnClickedButtonmuti()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	if (m_preaction)
	{
		m_num2 = mmm;
		cal(m_action);
	}
	m_action = 3;
	m_preaction = m_action;
	m_num1 = mmm;
	mmm = '0';
}


void CcalculatorDlg::OnBnClickedButtondivide()
{
	// TODO: 在此加入控制項告知處理常式程式碼	
	if (m_preaction)
	{
		m_num2 = mmm;
		cal(m_action);
	}
	m_action = 4;
	m_preaction = m_action;
	m_num1 = mmm;
	mmm = '0';
}


void CcalculatorDlg::OnBnClickedButtoncancle()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	mmm = '0';
	m_action = 0;
	m_preaction = 0;
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton5()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	if (m_p == 1)
		mmm = '0';
	if (mmm != '0')
	{
		mmm += '5';
		m_p = 2;
	}
	else
	{
		mmm = '5';
		m_p = 2;
	}
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonminus()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	if (m_preaction)
	{
		m_num2 = mmm;
		cal(m_action);
	}
	m_action = 2;
	m_preaction = m_action;
	m_num1 = mmm;
	mmm = '0';
}


void CcalculatorDlg::OnBnClickedButton6()
{

	
		// TODO: 在此加入控制項告知處理常式程式碼
		if (m_p == 1)
			mmm = '0';
		if (mmm != '0')
		{
			mmm += '6';
			m_p = 2;
		}
		else
		{
			mmm = '6';
			m_p = 2;
		}
		UpdateData(FALSE);
	
}


void CcalculatorDlg::OnBnClickedButton3()
{
	if (m_p == 1)
		mmm = '0';
	if (mmm != '0')
	{
		mmm += '3';
		m_p = 2;
	}
	else
	{
		mmm = '3';
		m_p = 2;
	}
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton4()
{
	if (m_p == 1)
		mmm = '0';
	if (mmm != '0')
	{
		mmm += '4';
		m_p = 2;
	}
	else
	{
		mmm = '4';
		m_p = 2;
	}
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton7()
{
	if (m_p == 1)
		mmm = '0';
	if (mmm != '0')
	{
		mmm += '7';
		m_p = 2;
	}
	else
	{
		mmm = '7';
		m_p = 2;
	}
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton8()
{
	if (m_p == 1)
		mmm = '0';
	if (mmm != '0')
	{
		mmm += '8';
		m_p = 2;
	}
	else
	{
		mmm = '8';
		m_p = 2;
	}
	UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButton9()
{
	if (m_p == 1)
		mmm = '0';
	if (mmm != '0')
	{
		mmm += '9';
		m_p = 2;
	}
	else
	{
		mmm = '9';
		m_p = 2;
	}
	UpdateData(FALSE);
	// TODO: 在此加入控制項告知處理常式程式碼
}


void CcalculatorDlg::OnBnClickedButton10()
{
	if (m_p == 1)
		mmm = '0';

	if (mmm != '0')
		mmm += '0';
	else
		mmm = '0';
	UpdateData(FALSE);
}
