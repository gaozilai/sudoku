#if !defined(AFX_STATLIST_H__A596E4D8_CA31_4181_AFF7_DD4B599308AB__INCLUDED_)
#define AFX_STATLIST_H__A596E4D8_CA31_4181_AFF7_DD4B599308AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StatList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStatList window

class CStatList : public CStatic
{
// Construction
public:
	CStatList();

// Attributes
public:

// Operations
public:
	void Init();
    void Resize();
    void SetBkgColor(COLORREF clr);
	void SetItemCount(int nCount);
	void SetItem(int nIndex, CString strName, CString strUnit, int nDecimal, COLORREF nColor, int nValueWidth);
	void SetName(int nIndex, CString strName);
	void SetUnit(int nIndex, CString strUnit);
	void SetPrecision(int nIndex, int nDecimal);
	void SetDefaultColor(int nIndex, COLORREF nColor);
	void SetValueWidth(int nIndex, int nWidth);
	void Clear();
	void SetValue(int nIndex, double fValue);
	void SetText(int nIndex, CString strText);
	void SetColor(int nIndex, COLORREF nColor);
	void SetItemSpacing(int nSpacing);
	int GetWidth();
	virtual ~CStatList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CStatList)
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	void DrawValue(CDC *pDC, int nIndex);
	struct STAT_ITEM
	{
		STAT_ITEM()
		{
			nDecimal=0;
			nColor=nDefaultColor=0;
			nValueWidth=50;
		}
		CString strName;
		CString strUnit;
		int nDecimal;
		COLORREF nDefaultColor;
		COLORREF nColor;
		CString strText;
		int nValueWidth;
	};
	STAT_ITEM *m_pList;
	int m_nCount;
	int m_nWidth;
	int m_nItemHeight;
	int m_nItemSpacing;
	CFont m_Font;
	CDC m_MemDC;
	CDC m_MemDCBack;
	CBitmap m_MemBitmap;
	CBitmap m_MemBitmapBack;
	HBRUSH m_hBackBrush;
	void DrawItem(CDC *pDC, int nIndex); 
    COLORREF m_clrBkg;

public:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATLIST_H__A596E4D8_CA31_4181_AFF7_DD4B599308AB__INCLUDED_)
