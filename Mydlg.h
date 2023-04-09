#pragma once

class CMy425View;
// Mydlg 대화 상자

class Mydlg : public CDialogEx
{
	DECLARE_DYNAMIC(Mydlg)

public:
	Mydlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Mydlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CMy425View* view;

	virtual void PostNcDestroy();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CListCtrl m_memberlist;
	CEdit m_id;
	CEdit m_pw;
	CEdit m_pw2;
	CEdit m_name;
//	CButton m_professor;
//	CButton m_student;
//	BOOL m_professor;
//	BOOL m_student;
	CButton m_professor;
	CButton m_student;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton6();
	CButton m_check1;
	CButton m_check2;
	CListCtrl m_wishlist;
	CEdit m_edit5;
//	CEdit m_edit6;
	CEdit m_edit7;
//	CEdit m_edit8;
	CEdit m_edit10;
	CEdit m_edit11;
	afx_msg void OnBnClickedButton7();
	CEdit m_edit8;
	CEdit m_edit9;
	afx_msg void OnBnClickedButton8();
	int check;
};
