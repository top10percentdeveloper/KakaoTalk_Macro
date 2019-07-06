
// KakaoTalk MacroDlg.cpp : implementation file
//

#include "stdafx.h"
#include "KakaoTalk Macro.h"
#include "KakaoTalk MacroDlg.h"
#include "afxdialogex.h"

#include <Windows.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKakaoTalkMacroDlg dialog



CKakaoTalkMacroDlg::CKakaoTalkMacroDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_KAKAOTALKMACRO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKakaoTalkMacroDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ChatRoom);
}

BEGIN_MESSAGE_MAP(CKakaoTalkMacroDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_LOGIN, &CKakaoTalkMacroDlg::OnBnClickedLogin)
END_MESSAGE_MAP()


// CKakaoTalkMacroDlg message handlers

BOOL CKakaoTalkMacroDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_font.CreateFont(40, // nHeight 
		0, // nWidth 
		0, // nEscapement 
		0, // nOrientation 
		FW_BOLD, // nWeight 
		0, // bItalic 
		0, // bUnderline 
		0, // cStrikeOut 
		DEFAULT_CHARSET, // nCharSet 
		OUT_DEFAULT_PRECIS, // nOutPrecision 
		0,                              // nClipPrecision 
		DEFAULT_QUALITY,       // nQuality
		DEFAULT_PITCH | FF_DONTCARE,  // nPitchAndFamily 
		L"Arial"); // lpszFacename 

	GetDlgItem(IDC_STATIC1)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC2)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC3)->SetFont(&m_font);

	m_strText = L"";

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CKakaoTalkMacroDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CKakaoTalkMacroDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// static text ���� ����
HBRUSH CKakaoTalkMacroDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	if ((pWnd->GetDlgCtrlID() == IDC_STATIC1) || (pWnd->GetDlgCtrlID() == IDC_STATIC3))
	{
		pDC->SetTextColor(RGB(255, 127, 0));
	}

	if (pWnd->GetDlgCtrlID() == IDC_STATIC2)
	{
		pDC->SetTextColor(RGB(80, 188, 223));
	}

	return hbr;
}



void CKakaoTalkMacroDlg::OnBnClickedLogin()
{
	CString str_ChatRoom, str_ChatRoom2, strValue;

	GetDlgItemText(IDC_EDIT1, str_ChatRoom); // ä�ù� �̸��� ����.
	GetDlgItemText(IDC_EDIT3, str_ChatRoom2); // ä�ù� �̸��� ����.
	GetDlgItemText(IDC_EDIT2, strValue); // �Է��� ������ ����.

	m_strText = strValue;

	// �����ִ� ä�ù� �ڵ��� ����.
	m_hwndKakaoTalk1 = ::FindWindow(NULL, str_ChatRoom);

	//if (NULL != m_hwndKakaoTalk1) {
		//�޸���ȿ��ִ� ����Ʈ�ڽ� �ڵ��� ã�´�. 
		m_hwndKakaoTalk1Child = ::FindWindowEx(m_hwndKakaoTalk1, NULL, L"RichEdit20W", NULL);

		//�޸��忡 ���ڿ� �Է�! 
		::SendMessage(m_hwndKakaoTalk1Child, WM_SETTEXT, 0, (LPARAM)m_strText);
		::PostMessage(m_hwndKakaoTalk1Child, WM_KEYDOWN, 0x0000000D, 0x001C0001);
		::PostMessage(m_hwndKakaoTalk1Child, WM_KEYDOWN, 0x0000000D, 0x001C0001);
	//}
	
	m_hwndKakaoTalk2 = ::FindWindow(NULL, str_ChatRoom2);

	//if (NULL != m_hwndKakaoTalk2) {
		//�޸���ȿ��ִ� ����Ʈ�ڽ� �ڵ��� ã�´�. 
		m_hwndKakaoTalk2Child = ::FindWindowEx(m_hwndKakaoTalk2, NULL, L"RichEdit20W", NULL);

		//�޸��忡 ���ڿ� �Է�! 
		::SendMessage(m_hwndKakaoTalk2Child, WM_SETTEXT, 0, (LPARAM)m_strText);
		::PostMessage(m_hwndKakaoTalk2Child, WM_KEYDOWN, 0x0000000D, 0x001C0001);
		::PostMessage(m_hwndKakaoTalk2Child, WM_KEYDOWN, 0x0000000D, 0x001C0001);
	//}

/* // ����
	//�޸��� �ڵ��� ã�´�. 
	m_hwndKakaoTalk1 = ::FindWindow(L"Notepad", NULL);

	if (NULL != m_hwndKakaoTalk1) {
		//�޸���ȿ��ִ� ����Ʈ�ڽ� �ڵ��� ã�´�. 
		m_hwndKakaoTalk1Child = ::FindWindowEx(m_hwndKakaoTalk1, NULL, L"Edit", NULL);

		//�޸��忡 ���ڿ� �Է�! 
		::SendMessage(m_hwndKakaoTalk1Child, WM_SETTEXT, 0, (LPARAM)m_strText);
	}
*/
}
