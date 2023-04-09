// Mydlg.cpp: 구현 파일
//

#include "pch.h"
#include "4_25.h"
#include "Mydlg.h"
#include "afxdialogex.h"

#include "4_25View.h"
#include"4_25Doc.h"
// Mydlg 대화 상자

IMPLEMENT_DYNAMIC(Mydlg, CDialogEx)

Mydlg::Mydlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

	
}

Mydlg::~Mydlg()
{
}

void Mydlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_memberlist);
	DDX_Control(pDX, IDC_EDIT1, m_id);
	DDX_Control(pDX, IDC_EDIT2, m_pw);
	DDX_Control(pDX, IDC_EDIT3, m_pw2);
	DDX_Control(pDX, IDC_EDIT4, m_name);
	DDX_Control(pDX, IDC_RADIO3, m_professor);
	DDX_Control(pDX, IDC_RADIO4, m_student);
	DDX_Control(pDX, IDC_LIST2, m_wishlist);
	DDX_Control(pDX, IDC_EDIT5, m_edit5);
	DDX_Control(pDX, IDC_EDIT7, m_edit7);
	DDX_Control(pDX, IDC_EDIT10, m_edit10);
	DDX_Control(pDX, IDC_EDIT11, m_edit11);
	DDX_Control(pDX, IDC_EDIT8, m_edit8);
	DDX_Control(pDX, IDC_EDIT9, m_edit9);
}


BEGIN_MESSAGE_MAP(Mydlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &Mydlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &Mydlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &Mydlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Mydlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &Mydlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Mydlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Mydlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// Mydlg 메시지 처리기


void Mydlg::PostNcDestroy()
{
	CDialogEx::PostNcDestroy();
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	view->dlg = NULL;
	delete this;
	check = 1;
	
}


void Mydlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	DestroyWindow();
	//CDialogEx::OnCancel();
}


void Mydlg::OnBnClickedOk()//@@@@@@@@@@@@@@저장
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	view->userlist.DeleteAllItems();

	CString str;
	for (int i = 0; i < m_memberlist.GetItemCount(); i++) {

		str.Format(L"%d", i);
		view->userlist.InsertItem(i, str);
		str = m_memberlist.GetItemText(i, 1);
		view->userlist.SetItemText(i, 1, str);//아이디
		str = m_memberlist.GetItemText(i, 2);
		view->userlist.SetItemText(i, 2, str);//비번]
		str = m_memberlist.GetItemText(i, 3);
		view->userlist.SetItemText(i, 3, str);//이름
		str = m_memberlist.GetItemText(i, 4);
		view->userlist.SetItemText(i, 4, str);//구분(교수? 학생?)
		str = m_memberlist.GetItemText(i, 5);
		view->userlist.SetItemText(i, 5, str);//대출수







	}


	
	DestroyWindow();
	//CDialogEx::OnOK();
}


BOOL Mydlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString str;
	m_memberlist.InsertColumn(0, _T("인덱스"), LVCFMT_CENTER, 70, -1);
	m_memberlist.InsertColumn(1, _T("아이디"), LVCFMT_CENTER, 70, -1);
	m_memberlist.InsertColumn(2, _T("비밀번호"), LVCFMT_CENTER, 70, -1);
	m_memberlist.InsertColumn(3, _T("이름"), LVCFMT_CENTER, 70, -1);
	m_memberlist.InsertColumn(4, _T("구분"), LVCFMT_CENTER, 70, -1);
	m_memberlist.InsertColumn(5, _T("대출가능수"), LVCFMT_CENTER, 100, -1);

	

	m_wishlist.InsertColumn(0, _T("인덱스"), LVCFMT_CENTER, 0, -1);
	m_wishlist.InsertColumn(1, _T("청구기호"), LVCFMT_CENTER, 70, -1);
	m_wishlist.InsertColumn(2, _T("아이디"), LVCFMT_CENTER, 70, -1);
	m_wishlist.InsertColumn(3, _T("도서제목"), LVCFMT_CENTER, 70, -1);
	m_wishlist.InsertColumn(4, _T("저자"), LVCFMT_CENTER, 70, -1);
	m_wishlist.InsertColumn(5, _T("출판사"), LVCFMT_CENTER, 70, -1);
	m_wishlist.InsertColumn(56, _T("출판연도"), LVCFMT_CENTER, 70, -1);

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	for (int i = 0; i < view->userlist.GetItemCount(); i++) {//m_memberlist
		
		str.Format(L"%d", i);
		m_memberlist.InsertItem(i, str);
		str = view->userlist.GetItemText(i, 1);
		m_memberlist.SetItemText(i, 1, str);//아이디
		str = view->userlist.GetItemText(i, 2);
		m_memberlist.SetItemText(i, 2, str);//비번]
		str = view->userlist.GetItemText(i, 3);
		m_memberlist.SetItemText(i, 3, str);//이름
		str = view->userlist.GetItemText(i, 4);
		m_memberlist.SetItemText(i, 4, str);//구분(교수? 학생?)
		str = view->userlist.GetItemText(i, 5);
		m_memberlist.SetItemText(i, 5, str);//재고







	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

//회원가입하기, 리스트 컨트롤에 들어감.
void Mydlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	int mama = 0;
	int check3state = IsDlgButtonChecked(IDC_RADIO3);
	int check4state = IsDlgButtonChecked(IDC_RADIO4);
	CString nstr;
	CString nnstr;
	CString strText1 = _T("");
	m_id.GetWindowText(strText1);
	//초기화되었을 때, 아무값도 안 넣어도 되기 때문에 아이디 중복검사할 필요 없음
	if (m_memberlist.GetItemCount() == 0) {
		CString strText2 = _T("");
		m_pw.GetWindowText(strText2);
		CString strText3 = _T("");
		m_pw2.GetWindowText(strText3);
		//비밀번호가 같을 때
		if (check) {//strText2.Compare(strText3) == 0@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//비밀번호 확인 할 때 비밀번호1, 비밀번호2 일치할 때
			CString strText4 = _T("");
			m_name.GetWindowText(strText4);
			//m_professor, m_student
			CString strText5;
			if (check3state) {
				strText5 = _T("교수");
				mama = 1;
			}
			if (check4state) {
				strText5 = _T("학생");
				mama = 2;
			}
			//인덱스
			int num = m_memberlist.GetItemCount();
			CString str;
			str.Format(L"%d", num);

			int index = m_memberlist.GetItemCount();
			m_memberlist.InsertItem(index, str);
			m_memberlist.SetItemText(index, 1, strText1);//아이디
			m_memberlist.SetItemText(index, 2, strText2);//비번
			m_memberlist.SetItemText(index, 3, strText4);//이름
			m_memberlist.SetItemText(index, 4, strText5);//구분(교수? 학생?)
			if (mama == 1) {
				nnstr = _T("10");
				m_memberlist.SetItemText(index, 5, nnstr);
			}
			else if (mama == 2) {

				nnstr = _T("5");
				m_memberlist.SetItemText(index, 5, nnstr);
			}
		}
		else
			MessageBox(L"비밀번호 입력 실패");
			UpdateData(FALSE);
	}
	else {
	//아이디가 한 개 이상 들어가있기 때문에 중복 검사를 해야 한다.
		//for (int i = 0; i <= m_memberlist.GetItemCount()-1; i++) {
		//nstr = m_memberlist.GetItemText(i, 1);
		if (check == 0) {
			//중복 검사 결과 같지 않을 때, 회원 가입 가능하다.
			CString strText2 = _T("");
			m_pw.GetWindowText(strText2);
			CString strText3 = _T("");
			m_pw2.GetWindowText(strText3);

			if (strText2.Compare(strText3) == 0) {
				//비밀번호 확인 할 때 비밀번호1, 비밀번호2 일치할 때
				CString strText4 = _T("");
				m_name.GetWindowText(strText4);
				//m_professor, m_student
				CString strText5;
				if (check3state) {
					strText5 = _T("교수");
					mama = 1;
				}
				if (check4state) {
					strText5 = _T("학생");
					mama = 2;
				}
				//인덱스
				int num = m_memberlist.GetItemCount();
				CString str;
				str.Format(L"%d", num);

				int index = m_memberlist.GetItemCount();
				m_memberlist.InsertItem(index, str);
				m_memberlist.SetItemText(index, 1, strText1);//아이디
				m_memberlist.SetItemText(index, 2, strText2);//비번
				m_memberlist.SetItemText(index, 3, strText4);//이름
				m_memberlist.SetItemText(index, 4, strText5);//구분(교수? 학생?)
				check = 1;
				if (mama == 1) {
					nnstr = _T("10");
					m_memberlist.SetItemText(index, 5, nnstr);
				}
				else if (mama == 2) {

					nnstr = _T("5");
					m_memberlist.SetItemText(index, 5, nnstr);
				}
			}
			else
				MessageBox(L"비밀번호 입력 성공");
				UpdateData(FALSE);
		}
		else
			MessageBox(L"아이디 중복확인을 하세요.");
			UpdateData(FALSE);
	}//for문 닫음
	UpdateData(FALSE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//아이디 중복검사
void Mydlg::OnBnClickedButton2()
{
	CString nstr;
	CString strText99 = _T("");
	m_id.GetWindowText(strText99);
	if (m_memberlist.GetItemCount() == 0)
	{
		MessageBox(L"아이디가 중복되지 않았습니다. 비밀번호를 설정하세요.");
	}
	else {
		check = 0;
		for (int i = 0; i < m_memberlist.GetItemCount(); i++) {//@@@@@@@@@@@@@@@@@@@바꿈
			nstr = m_memberlist.GetItemText(i, 1);
			if (nstr.Compare(strText99) == 0)
				check++;
		}

		if (check) {
			MessageBox(L"아이디가 중복됩니다. 다른 아이디를 입력하세요");
			CString strText99 = _T("");
		}
		else
			MessageBox(L"아이디가 중복되지 않았습니다. 비밀번호를 설정하세요.");
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//비밀번호 검사 : 비밀번호, 비밀번호 확인란에 같은 것이 들어갔는지 확인한다.
void Mydlg::OnBnClickedButton6()
{

	//m_pw와 m_pw2의 값 비교하기
	CString strText88 = _T("");
	CString strText99 = _T("");
	m_pw.GetWindowText(strText88);
	m_pw2.GetWindowText(strText99);

	if (strText88.Compare(strText99) == 0) {
		MessageBox(L"비밀번호 입력 성공");
	}
	else
		MessageBox(L"비밀번호 입력 실패, 다시 입력하세요.");
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//희망도서 리스트에 넣기
//만약 title, author, publisher, year 가 같은 책이 있다면, 이 책은 위시리스트에 넣으면 안 된다
//만약 한 이용자가 3권 이상의 도서를 wishlist에 넣는다면, 막는다.
//이 리스트는 메인 폼과 연결해서 쓴다.
void Mydlg::OnBnClickedButton7()
{
	int numch = 0;
	UpdateData(TRUE);

	CString strTextid = _T("");
	CString strTextpw = _T("");
	CString strTexttitle = _T("");
	CString strTextauthor = _T("");
	CString strTextpublisher = _T("");
	CString strTextyear = _T("");
	m_edit5.GetWindowText(strTextid);
	m_edit8.GetWindowText(strTextpw); //패스워드를 청구기호로
	m_edit7.GetWindowText(strTexttitle);
	m_edit9.GetWindowText(strTextauthor);
	m_edit10.GetWindowText(strTextpublisher);
	m_edit11.GetWindowText(strTextyear);
		int num = m_wishlist.GetItemCount();
		CString str;
		str.Format(L"%d", num);

		for (int i = 0; i < view->m_listCtrl.GetItemCount(); i++) {
			numch = 0;
			if (strTextpw.Compare(view->m_listCtrl.GetItemText(i, 1)) == 0)
				numch++;
		}
		if (numch == 0) {
			int index = m_wishlist.GetItemCount();
			m_wishlist.InsertItem(index, str);
			m_wishlist.SetItemText(index, 1, strTextpw);
			m_wishlist.SetItemText(index, 2, strTextid);
			m_wishlist.SetItemText(index, 3, strTexttitle);
			m_wishlist.SetItemText(index, 4, strTextauthor);
			m_wishlist.SetItemText(index, 5, strTextpublisher);
			m_wishlist.SetItemText(index, 6, strTextyear);
		}
		else
			MessageBox(L"같은 청구기호가 기존 도서목록에 있음!");

	UpdateData(FALSE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Mydlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	int index;
	CString str;
	str.Format(L"%d", 3);

	for (int i = 0; i < m_wishlist.GetItemCount(); i++) {
		index = view->m_listCtrl.GetItemCount();
		view->m_listCtrl.InsertItem(index, m_wishlist.GetItemText(i, 0));
		view->m_listCtrl.SetItemText(index, 1, m_wishlist.GetItemText(i, 1));
		view->m_listCtrl.SetItemText(index, 2, m_wishlist.GetItemText(i, 2));
		view->m_listCtrl.SetItemText(index, 3, m_wishlist.GetItemText(i, 3));
		str.Format(L"%d", 3);
		view->m_listCtrl.SetItemText(index, 4, str);
		str.Format(L"1A");
		view->m_listCtrl.SetItemText(index, 5, str);
		str.Format(L"%d", 3);
		view->m_listCtrl.SetItemText(index, 6, str);
		str.Format(L"%d", 0);
		view->m_listCtrl.SetItemText(index, 7, str);
		str.Format(L"%d", 0);
		view->m_listCtrl.SetItemText(index, 8, str);

	}



	UpdateData(FALSE);
}
