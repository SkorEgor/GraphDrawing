#include "pch.h"
#include "framework.h"
#include "GraphDrawing.h"
#include "GraphDrawingDlg.h"
#include "afxdialogex.h"

#include <vector>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CGraphDrawingDlg::CGraphDrawingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GRAPHDRAWING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGraphDrawingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRAPH, graphPicture);
}

BEGIN_MESSAGE_MAP(CGraphDrawingDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CGraphDrawingDlg::OnBnClickedButton1)
END_MESSAGE_MAP()

BOOL CGraphDrawingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	drv.Create(GetDlgItem(IDC_GRAPH)->GetSafeHwnd());

	return TRUE;
}

void CGraphDrawingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CGraphDrawingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGraphDrawingDlg::OnBnClickedButton1()
{
	vector <double> x, y;
	int numberFunctionPoints = 20;
	
	//Заполняем точки функции
	for (int i = 0; i < numberFunctionPoints; i++) {
		x.push_back(i);
		y.push_back(i * 2);
	}

	//Вызов отрисовки
	drv.Draw(
		y, y[0], y[y.size() - 1],
		x, x[0], x[x.size() - 1],
		'R'
	);
}
