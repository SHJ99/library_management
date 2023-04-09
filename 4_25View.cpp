
// 4_25View.cpp: CMy425View 클래스의 구현
//

#include "pch.h"//713
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "4_25.h"
#endif

#include "4_25Doc.h"
#include "4_25View.h"

#include "Mydlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define _CRT_SECURE_NO_WARNINGS

// CMy425View

IMPLEMENT_DYNCREATE(CMy425View, CFormView)

BEGIN_MESSAGE_MAP(CMy425View, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &CMy425View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy425View::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy425View::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy425View::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMy425View::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CMy425View::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMy425View::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMy425View::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMy425View::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMy425View::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMy425View::OnBnClickedButton12)
END_MESSAGE_MAP()

// CMy425View 생성/소멸

CMy425View::CMy425View() noexcept
	: CFormView(IDD_MY4_25_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	dlg = NULL;
	//  m_edit1 = _T("");
}

CMy425View::~CMy425View()
{
}

void CMy425View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_listCtrl);

	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
	DDX_Control(pDX, IDC_EDIT3, m_edit3);
	DDX_Control(pDX, IDC_EDIT4, m_edit4);
	DDX_Control(pDX, IDC_EDIT5, m_edit5);
	DDX_Control(pDX, IDC_EDIT6, m_B_ID);
	DDX_Control(pDX, IDC_EDIT7, m_B_serial);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl2);
	DDX_Control(pDX, IDC_LIST3, m_event);
	//  DDX_Control(pDX, IDC_COMBO1, m_calander);
	//  DDX_Control(pDX, IDC_COMBO1, m_month);
	DDX_Control(pDX, IDC_LIST4, userlist);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, my_date);
	DDX_Control(pDX, IDC_LIST5, mlist_search);
	DDX_Control(pDX, IDC_EDIT8, search_edit);
}

BOOL CMy425View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CMy425View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_listCtrl.InsertColumn(0, _T("인덱스"), LVCFMT_CENTER, 0, -1);
	m_listCtrl.InsertColumn(1, _T("청구번호"), LVCFMT_CENTER, 70, -1);
	m_listCtrl.InsertColumn(2, _T("책제목"), LVCFMT_CENTER, 70, -1);
	m_listCtrl.InsertColumn(3, _T("저자"), LVCFMT_CENTER, 70, -1);
	m_listCtrl.InsertColumn(4, _T("재고"), LVCFMT_CENTER, 0, -1);
	m_listCtrl.InsertColumn(5, _T("위치"), LVCFMT_CENTER, 70, -1);

	m_listCtrl.InsertColumn(6, _T("대출가능"), LVCFMT_CENTER, 70, -1);

	m_listCtrl.InsertColumn(7, _T("대출횟수"), LVCFMT_CENTER, 70, -1);
	m_listCtrl.InsertColumn(8, _T("랭킹"), LVCFMT_CENTER, 70, -1);
	
	m_ListCtrl2.InsertColumn(0, _T("인덱스"), LVCFMT_CENTER, 0, -1);
	m_ListCtrl2.InsertColumn(1, _T("청구번호"), LVCFMT_CENTER, 70, -1);
	m_ListCtrl2.InsertColumn(2, _T("대출ID"), LVCFMT_CENTER, 70, -1);
	m_ListCtrl2.InsertColumn(3, _T("대출일자"), LVCFMT_CENTER, 70, -1);
	m_ListCtrl2.InsertColumn(4, _T("반납예정일"), LVCFMT_CENTER, 90, -1);
	
	m_event.InsertColumn(0, _T("이벤트"), LVCFMT_CENTER, 350, -1);




	userlist.InsertColumn(0, _T("인덱스"), LVCFMT_CENTER, 70, -1);
	userlist.InsertColumn(1, _T("아이디"), LVCFMT_CENTER, 70, -1);
	userlist.InsertColumn(2, _T("비밀번호"), LVCFMT_CENTER, 70, -1);
	userlist.InsertColumn(3, _T("이름"), LVCFMT_CENTER, 70, -1);
	userlist.InsertColumn(4, _T("구분"), LVCFMT_CENTER, 70, -1);
	userlist.InsertColumn(5, _T("대출수"), LVCFMT_CENTER, 70, -1);

	mlist_search.InsertColumn(0, _T("인덱스"), LVCFMT_CENTER, 0, -1);
	mlist_search.InsertColumn(1, _T("청구번호"), LVCFMT_CENTER, 70, -1);
	mlist_search.InsertColumn(2, _T("책제목"), LVCFMT_CENTER, 100, -1);
	mlist_search.InsertColumn(3, _T("저자"), LVCFMT_CENTER, 90, -1);
	mlist_search.InsertColumn(4, _T("재고"), LVCFMT_CENTER, 0, -1);
	mlist_search.InsertColumn(5, _T("위치"), LVCFMT_CENTER, 50, -1);
	mlist_search.InsertColumn(6, _T("대출가능"), LVCFMT_CENTER, 70, -1);
	mlist_search.InsertColumn(7, _T("대출횟수"), LVCFMT_CENTER, 70, -1);
	mlist_search.InsertColumn(8, _T("랭킹"), LVCFMT_CENTER, 50, -1);

}


// CMy425View 인쇄

BOOL CMy425View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMy425View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMy425View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CMy425View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CMy425View 진단

#ifdef _DEBUG
void CMy425View::AssertValid() const
{
	CFormView::AssertValid();
}

void CMy425View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMy425Doc* CMy425View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy425Doc)));
	return (CMy425Doc*)m_pDocument;
}
#endif //_DEBUG


// CMy425View 메시지 처리기

//도서관 목록 업데이트
void CMy425View::OnBnClickedButton1()
{
	int numch=0;
	UpdateData(TRUE);
	
	CString strText1 = _T("");
	m_edit1.GetWindowText(strText1);
	CString strText2 = _T("");
	m_edit2.GetWindowText(strText2);
	CString strText3 = _T("");
	m_edit3.GetWindowText(strText3);
	CString strText4 = _T("");
	m_edit4.GetWindowText(strText4);
	CString strText5 = _T("");
	m_edit5.GetWindowText(strText5);
	//인덱스
	int num = m_listCtrl.GetItemCount();
	CString str;
	str.Format(L"%d", num);

	for (int i = 0; i < m_listCtrl.GetItemCount(); i++) {
		numch = 0;
		if (strText1.Compare(m_listCtrl.GetItemText(i, 1)) == 0)
			numch++;
	}
	if (numch == 0) {
		int index = m_listCtrl.GetItemCount();
		m_listCtrl.InsertItem(index, str);
		m_listCtrl.SetItemText(index, 1, strText1);
		m_listCtrl.SetItemText(index, 2, strText2);
		m_listCtrl.SetItemText(index, 3, strText3);
		m_listCtrl.SetItemText(index, 4, strText4);
		m_listCtrl.SetItemText(index, 5, strText5);

		str.Format(L"%d", 3);//@@@@@@@ 대출
		m_listCtrl.SetItemText(index, 6, str);

		str.Format(L"%d", 0);//@@@@@@@ 대출
		m_listCtrl.SetItemText(index, 7, str);
		str.Format(L"%d", 0);//@@@@@@@ 대출
		m_listCtrl.SetItemText(index, 8, str);
	}
	else 
		MessageBox(L"청구기호는 중복될 수 없음!");

	UpdateData(FALSE);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy425View::OnBnClickedButton2()//@@@@@@@@@@대출
{
	UpdateData(TRUE);


	CString t1, t2;
	CTime m_time;
	my_date.GetTime(m_time);
	int month = m_time.GetMonth();
	int day = m_time.GetDay();
	t1.Format(L"%d/%d", month, day);
	t2.Format(L"%d/%d", month, day + 7);




	CString strText6 = _T("");
	m_B_ID.GetWindowText(strText6);
	CString strText7 = _T("");
	m_B_serial.GetWindowText(strText7);

	int num = m_ListCtrl2.GetItemCount();
	CString str;
	str.Format(L"%d", num);
	int hsd = 0;
	int dfdfdfdf = 0;
	int t = 0;
	int dfdf = 0;
	int uuyy;
	for (int i = 0; i < m_listCtrl.GetItemCount(); i++) {
		CString nstr;
		CString nnstr;
		int tti = m_listCtrl.GetItemCount();
		nstr = m_listCtrl.GetItemText(i, 1);
		uuyy = 0;
		for (int j = 0; j < userlist.GetItemCount(); j++) {
			nnstr = userlist.GetItemText(j, 1);
			if (nnstr.Compare(strText7) == 0) {
				nnstr = userlist.GetItemText(j, 5);
				dfdf = _ttoi(nnstr);
				uuyy++;
				if (dfdf == 0)
					dfdfdfdf++;
				else
					hsd = j;
				break;

			}

		}
		if (uuyy == 0) {
			MessageBox(L"일치하는 회원이 없습니다..");
			break;
		}
		if (dfdfdfdf != 0) {
			MessageBox(L"대출 한도입니다.");
			break;
		}

		if (nstr.Compare(strText6) == 0) {
			nstr = m_listCtrl.GetItemText(i, 6);
			if (nstr.Compare(_T("0")) != 0) {
				int h = 0;
				h = _ttoi(nstr);
				h--;
				nstr.Format(L"%d", h);
				m_listCtrl.SetItemText(i, 6, nstr);

				int index = m_ListCtrl2.GetItemCount();
				m_ListCtrl2.InsertItem(index, str);
				m_ListCtrl2.SetItemText(index, 1, strText6);
				m_ListCtrl2.SetItemText(index, 2, strText7);
				m_ListCtrl2.SetItemText(index, 3, t1);
				m_ListCtrl2.SetItemText(index, 4, t2);
				t++;
				h = _ttoi(nnstr);
				h--;
				nstr.Format(L"%d", h);
				userlist.SetItemText(hsd, 5, nstr);
				nstr = m_listCtrl.GetItemText(i, 7);
				h = _ttoi(nstr);
				h++;
				nstr.Format(L"%d", h);
				m_listCtrl.SetItemText(i, 7, nstr);
				break;//@@@@@@@@@@@
			}
			else {
				MessageBox(L"재고가 없습니다.");
				t++;
			}

		}


	}
	if (t == 0)
		MessageBox(L"찾을수 없습니다.");

	UpdateData(FALSE);


	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//검색하기
//m_ListCtrl2 에서도, m_listCtrl에서도 검색 가능하게 만들기. 아이디와 청구번호를 둘 다 입력하면 --> 대출중인 도서에 뜨기
//아이디만 입력하면 --> 대출중인 도서에서만 뜨기
//청구번호만 입력하면 --> 둘 모두의 리스트 컨트롤에서 뜨게 만들기
//리스트 컨트롤은 전에 만들어놨던 정보를 없애버린다.
void CMy425View::OnBnClickedButton3()
{

	/*
	CString strText6 = _T("");
	m_B_ID.GetWindowText(strText6);
	CString strText7 = _T("");
	m_B_serial.GetWindowText(strText7);
	//인덱스로 지워지네..?
	LVFINDINFO find_item;
	find_item.flags = LVFI_STRING;
	find_item.psz = strText6;

	int index = m_listCtrl.FindItem(&find_item);
	if (-1 != index) m_listCtrl.DeleteItem(index);

	*/
	UpdateData(TRUE);

	CString strNum, strID, strT, str1, str2;
	int time, j, k;
	CString strTextID;
	CString strTextNum;
	m_B_ID.GetWindowText(strTextNum);
	m_B_serial.GetWindowText(strTextID);

	for (int i = 0; i < m_ListCtrl2.GetItemCount(); i++) {
		strNum = m_ListCtrl2.GetItemText(i, 1);
		strID = m_ListCtrl2.GetItemText(i, 2);

		if (strTextNum.Compare(strNum) == 0 && strTextID.Compare(strID) == 0) {
			strT = m_ListCtrl2.GetItemText(i, 4);

			AfxExtractSubString(str1, strT, 0, '/');
			AfxExtractSubString(str2, strT, 1, '/');

			time = _ttoi(str2) + 7;
			strT.Format(L"/%d", time);
			strT = str1 + strT;
			m_ListCtrl2.SetItemText(i, 4, strT);
			break;
		}
		else if (i == m_ListCtrl2.GetItemCount())
			MessageBox(L"정확한 ID와 청구번호를 입력하세요");
	}







	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy425View::OnBnClickedButton4()
{

	CString strNum;
	CString strText6 = _T("");
	m_B_ID.GetWindowText(strText6);
	for (int i = 0; i < m_listCtrl.GetItemCount(); i++) {
		strNum = m_listCtrl.GetItemText(i, 1);
		if (strNum.Compare(strText6) == 0) {
			m_listCtrl.DeleteItem(i);

		}
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy425View::OnBnClickedButton5()
{
	if (dlg == NULL) {
		dlg = new Mydlg;
		dlg->view = this; //뷰 자체의 위치
		dlg->Create(IDD_DIALOG1);
		dlg->ShowWindow(SW_SHOW);
	}
	else
		//만들어졌다면 그것에 집중해
		dlg->SetFocus();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

//이달의 이벤트 불러오기 //그냥 db쓰자....왜 안되지..ㅠ
void CMy425View::OnBnClickedButton7()
{
	m_event.DeleteAllItems();
	CString strA;
	CString FilePath;
	//char szFilter[] = "All Files(*.*) | *.* ||";
	CString szFilter = _T("All files(*.*)|*.*|"); // 모든 파일 표시
	CFileDialog FileDlg(TRUE, NULL, NULL, OFN_ALLOWMULTISELECT, szFilter);
	FileDlg.m_ofn.lpstrInitialDir = L"C:\\..\4_25\event";
	//4_25라는 디렉토리 안에만 들어있으면 실행됨!!
	//초기 디렉토리 주소
	if (FileDlg.DoModal() == IDOK) {
		for (POSITION pos = FileDlg.GetStartPosition(); pos != NULL;) {
			CString temp = FileDlg.GetNextPathName(pos);
			int retval = 0;
			retval = temp.Find('-');
			temp = temp.Mid(retval + 1);
			AfxExtractSubString(strA, temp, 0, '.'); // strA == "118"
			m_event.InsertItem(0, strA);
			//(0, FilePath) 하면 안나옴...왜????

		}
	}
	else
	{
		m_event.DeleteAllItems();
	}

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMy425View::OnBnClickedButton8()//@@@@@@@@@@@반납
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString nstr;
	CString nnstr;
	CString strText99 = _T("");//번호
	int y = 0;
	int x = 0;
	int z = 0;
	CString strText6 = _T("");//아이디
	m_B_serial.GetWindowText(strText6);

	int h = 0;
	int hsd = 0;


	m_B_ID.GetWindowText(strText99);
	for (int i = 0; i < m_ListCtrl2.GetItemCount(); i++) {
		nstr = m_ListCtrl2.GetItemText(i, 1);
		if (nstr.Compare(strText99) == 0) {

			nnstr = m_ListCtrl2.GetItemText(i, 2);
			if (nnstr.Compare(strText6) == 0) {
				y = i;
				x++;
				break;
			}


		}
		

	}


	int u = 0;
	if (x != 0) {
		nstr.Format(L"%d", 1);
		m_ListCtrl2.DeleteItem(y);
		for (int i = 0; i < m_listCtrl.GetItemCount(); i++) {
			nstr = m_listCtrl.GetItemText(i, 1);
			if (nstr.Compare(strText99) == 0) {
				nstr = m_listCtrl.GetItemText(i, 6);
				int h = 0;


				h = _ttoi(nstr);
				h++;
				nstr.Format(L"%d", h);
				m_listCtrl.SetItemText(i, 6, nstr);
				break;
			}

		}


		for (int i = 0; i < userlist.GetItemCount(); i++) {
			nstr = userlist.GetItemText(i, 1);
			if (nnstr.Compare(nstr) == 0) {
				nstr = userlist.GetItemText(i, 5);
				h = _ttoi(nstr);
				h++;
				nstr.Format(L"%d", h);
				userlist.SetItemText(z, 5, nstr);
				break;

			}



		}

		//
	


	}
	else
		MessageBox(L"찾을수 없습니다");
}


void CMy425View::OnBnClickedButton9()//회원검색
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString strText6 = _T("");//아이디
	m_B_serial.GetWindowText(strText6);
	CString strText;
	CString temp;
	CString trtrtr;
	for (int i = 0; i < m_ListCtrl2.GetItemCount(); i++) {
		strText= m_ListCtrl2.GetItemText(i, 2);
		if (strText.Compare(strText6) == 0) {
			strText=m_ListCtrl2.GetItemText(i, 1);

			for (int i = 0; i < m_listCtrl.GetItemCount(); i++) {
				trtrtr = m_listCtrl.GetItemText(i, 1);
				if (strText.Compare(trtrtr) == 0)
					temp += m_listCtrl.GetItemText(i, 2) + '\n';

			}

			


		}
	}
	strText6+= L"회원 대출목록";
	MessageBox(temp, strText6 );


}


void CMy425View::OnBnClickedButton10() //도서/저자 검색
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	mlist_search.DeleteAllItems();
	
	CString str, str2, str3;
	int index;
	search_edit.GetWindowText(str);
	
	for (int i = 0; i < m_listCtrl.GetItemCount(); i++) {
		str2 = m_listCtrl.GetItemText(i, 2);
		str3 = m_listCtrl.GetItemText(i, 3);

		int ch = str2.Find(str);
		int ch2 = str3.Find(str);
		if (ch != -1 || ch2 != -1) {
			index = mlist_search.GetItemCount();
			mlist_search.InsertItem(index, m_listCtrl.GetItemText(i, 0));
			mlist_search.SetItemText(index, 1, m_listCtrl.GetItemText(i, 1));
			mlist_search.SetItemText(index, 2, m_listCtrl.GetItemText(i, 2));
			mlist_search.SetItemText(index, 3, m_listCtrl.GetItemText(i, 3));
			mlist_search.SetItemText(index, 4, m_listCtrl.GetItemText(i, 4));
			mlist_search.SetItemText(index, 5, m_listCtrl.GetItemText(i, 5));
			mlist_search.SetItemText(index, 6, m_listCtrl.GetItemText(i, 6));
			mlist_search.SetItemText(index, 7, m_listCtrl.GetItemText(i, 7));
			mlist_search.SetItemText(index, 8, m_listCtrl.GetItemText(i, 8));
		}
	}
	//mlist_search
	UpdateData(FALSE);

}


void CMy425View::OnBnClickedButton11() //파일저장
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString buff0, buff1, buff2, buff3, buff4, buff5, buff6, buff7, buff8;

	CFile file(L"test.xls", CFile::modeCreate | CFile::modeReadWrite | CFile::shareExclusive);
	CStringA u8 = CW2A(_T("인덱스\t청구번호\t책제목\t저자\t재고\t위치\t대출가능\t대출횟수\t랭킹\n"), CP_UTF8);
	file.Write(u8, u8.GetLength());
	int i = 0;
	int j = 0;
	j = m_listCtrl.GetItemCount();

	if (j > 0)
	{
		for (i = 0; i < j; i++)
		{
			buff0 = m_listCtrl.GetItemText(i, 0);
			buff1 = m_listCtrl.GetItemText(i, 1);
			buff2 = m_listCtrl.GetItemText(i, 2);
			buff3 = m_listCtrl.GetItemText(i, 3);
			buff4 = m_listCtrl.GetItemText(i, 4);
			buff5 = m_listCtrl.GetItemText(i, 5);
			buff6 = m_listCtrl.GetItemText(i, 6);
			buff7 = m_listCtrl.GetItemText(i, 7);
			buff8 = m_listCtrl.GetItemText(i, 8);
			CString msg;
			msg.Format(_T("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n"),
				(LPCTSTR)buff0, (LPCTSTR)buff1, (LPCTSTR)buff2, (LPCTSTR)buff3, (LPCTSTR)buff4, (LPCTSTR)buff5, (LPCTSTR)buff6, (LPCTSTR)buff7, (LPCTSTR)buff8);
			u8 = CW2A(msg, CP_UTF8);
			file.Write(u8, u8.GetLength());
		}
	}
}


void CMy425View::OnBnClickedButton12()// 파일 불러오기
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString str, str0, str1, str2, str3, str4, str5, str6, str7, str8;


	//AfxExtractSubString(str1, str, 0, '#');

	int index, n, k;
	char *ch = new char[20480000];
	ifstream fin("data.txt");
	fin >> n;
	for (int i = 0; i < n; i++) {
		fin >> k;
		 char *c=_itoa(k, ch, 10);
		 str = ch;
		AfxExtractSubString(str0, str, 0, '#');
		AfxExtractSubString(str1, str, 1, '#');
		AfxExtractSubString(str2, str, 2, '#');
		AfxExtractSubString(str3, str, 3, '#');
		AfxExtractSubString(str4, str, 4, '#');
		AfxExtractSubString(str5, str, 5, '#');
		AfxExtractSubString(str6, str, 6, '#');
		AfxExtractSubString(str7, str, 7, '#');
		AfxExtractSubString(str8, str, 8, '#');
	
		
	}
	for (int i = 0; i < n; i++) {
		index = m_listCtrl.GetItemCount();
		m_listCtrl.InsertItem(index, str0);
		m_listCtrl.SetItemText(index, 1, str1);
		m_listCtrl.SetItemText(index, 2, str2);
		m_listCtrl.SetItemText(index, 3, str3);
		m_listCtrl.SetItemText(index, 4, str4);
		m_listCtrl.SetItemText(index, 5, str5);
		m_listCtrl.SetItemText(index, 6, str6);
		m_listCtrl.SetItemText(index, 7, str7);
		m_listCtrl.SetItemText(index, 8, str8);
	}
}
