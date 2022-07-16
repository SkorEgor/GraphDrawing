#include "Drawer.h"


// Диалоговое окно CGraphDrawingDlg
class CGraphDrawingDlg : public CDialogEx
{
public:
	CGraphDrawingDlg(CWnd* pParent = nullptr);
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GRAPHDRAWING_DIALOG };
#endif
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
protected:
	Drawer drv;
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic graphPicture;
	afx_msg void OnBnClickedButton1();
};
