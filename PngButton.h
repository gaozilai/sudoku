#pragma once

class CPngButton : public CButton
{
public:
    class CPngMemDC : public CDC
    {
    private:
        CBitmap     m_bitmap; // DeleteObject() on ~CGdiObject()
        CBitmap*    m_oldBitmap;
        CDC*        m_pDC;
        CRect       m_rcBounds;
    public:
        CPngMemDC(CDC* pDC, const CRect& rcBounds) : CDC()
        {
            CreateCompatibleDC(pDC);
            m_bitmap.CreateCompatibleBitmap(pDC, rcBounds.Width(), rcBounds.Height());
            m_oldBitmap = SelectObject(&m_bitmap);
            SetWindowOrg(rcBounds.left, rcBounds.top);
            m_pDC = pDC;
            m_rcBounds = rcBounds;
        }
        ~CPngMemDC()
        {
            SetWindowOrg(0, 0);
            m_pDC->BitBlt(m_rcBounds.left, m_rcBounds.top, m_rcBounds.Width(), m_rcBounds.Height(), this, 0, 0, SRCCOPY);
            SelectObject(m_oldBitmap);
        }
    };

	CPngButton();
	virtual ~CPngButton();
	virtual void PreSubclassWindow();
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDis);

    void SetBkGnd(CDC* pDC);
	CSize LoadStdImage(UINT id);
    void LoadHotImage(UINT id);
    void LoadPressedImage(UINT id);
    void LoadCheckedImage(UINT id);
    void LoadDisableImage(UINT id);

public:
    void SetCheck(BOOL bCheck);
    BOOL GetCheck() {return m_bChecked;}

protected:
    void InitBitmaps( CDC* pDC, CRect rect );
    void InitDC(CDC& dc, CPngMemDC& mDC, Graphics& graphics, CRect rect, Image* pImg, ImageAttributes* ia = NULL, CSize offset = CSize(0, 0));
    void LoadImage(Image*& pImage, UINT id);

    BOOL m_bHotLight;
    BOOL m_bChecked;
    Image* m_pImage;
    Image* m_pImgHot;
    Image* m_pImgCheck;
    Image* m_pImgPress;
    Image* m_pImgDisable;
    CDC m_dcBk;			
    CDC m_dcStandard;	
    CDC m_dcPressed;	
    CDC m_dcHotLight;		
    CDC m_dcChecked;		
    CDC m_dcDisabled;	

	DECLARE_MESSAGE_MAP()
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wparam, LPARAM lparam);
};
