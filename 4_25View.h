
// 4_25View.h: CMy425View 클래스의 인터페이스
//
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

#pragma once
class Mydlg;
class CMy425Doc;

class CMy425View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CMy425View() noexcept;
	DECLARE_DYNCREATE(CMy425View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY4_25_FORM };
#endif

// 특성입니다.
public:
	CMy425Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMy425View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	Mydlg* dlg;
	CListCtrl m_listCtrl;
	afx_msg void OnBnClickedButton1();

	CEdit m_edit1;
	CEdit m_edit2;
	CEdit m_edit3;
	CEdit m_edit4;
	CEdit m_edit5;
	CEdit m_B_ID;
	CEdit m_B_serial;
	afx_msg void OnBnClickedButton2();
	CListCtrl m_ListCtrl2;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	CListCtrl m_event;
//	CComboBox m_calander;
//	CComboBox m_month;
	afx_msg void OnBnClickedButton7();
	CListCtrl userlist;
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	CDateTimeCtrl my_date;
	afx_msg void OnBnClickedButton10();
	CListCtrl mlist_search;
	CEdit search_edit;
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
};

#ifndef _DEBUG  // 4_25View.cpp의 디버그 버전
inline CMy425Doc* CMy425View::GetDocument() const
   { return reinterpret_cast<CMy425Doc*>(m_pDocument); }
#endif

