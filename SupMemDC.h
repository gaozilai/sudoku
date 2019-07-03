
#pragma once

class SupMemDC : public CDC
{
private:
    CBitmap     m_bitmap; // DeleteObject() on ~CGdiObject()
    CBitmap*    m_oldBitmap;
    CDC*        m_pDC;
    CSize       m_sizWnd;
public:
    SupMemDC(CDC* pDC, int iWndWid, int iWndHei) : CDC()
    {
        CreateCompatibleDC(pDC);
        m_bitmap.CreateCompatibleBitmap(pDC, iWndWid, iWndHei);
        m_oldBitmap = SelectObject(&m_bitmap);
        m_pDC = pDC;
        m_sizWnd = CSize(iWndWid, iWndHei);
    }
    ~SupMemDC()
    {
        m_pDC->BitBlt(0, 0, m_sizWnd.cx, m_sizWnd.cy, this, 0, 0, SRCCOPY);
        SelectObject(m_oldBitmap);
    }
};
