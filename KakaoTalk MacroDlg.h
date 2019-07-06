
// KakaoTalk MacroDlg.h : header file
//

#pragma once


// CKakaoTalkMacroDlg dialog
class CKakaoTalkMacroDlg : public CDialogEx
{
// Construction
public:
	CKakaoTalkMacroDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_KAKAOTALKMACRO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
private:
	CFont m_font;

	//īī������ �ڵ� ����� 
	HWND m_hwndKakaoTalk1, m_hwndKakaoTalk2;

	//���ϵ� �ڵ� �����
	HWND m_hwndKakaoTalk1Child, m_hwndKakaoTalk2Child;

	// �޸��忡 �Է��� ������ ������ ����
	LPCTSTR  m_strText; 

	CEdit m_ChatRoom;
	
	
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnBnClickedLogin();
	
};
