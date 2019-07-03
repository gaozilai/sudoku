#pragma once
#include "afxwin.h"
class SPopMenu : public CMenu
{
public:
    SPopMenu(void);
    virtual ~SPopMenu(void);
    virtual void DrawItem( LPDRAWITEMSTRUCT);
    virtual void MeasureItem( LPMEASUREITEMSTRUCT );

    BOOL AppendMenu(UINT nFlags, UINT_PTR nIDNewItem = 0, LPCTSTR lpszNewItem = NULL);
    BOOL SetMenuItemBitmaps(UINT nPosition, UINT nFlags, const CBitmap* pBmpUnchecked, const CBitmap* pBmpChecked);
    void SetPngIcon(UINT idMenu, UINT idResChecked, UINT idResUncheck);
    void SetPngIcon(UINT idMenu, CString strFileChecked, CString strFileUncheck);

protected:
    CFont m_font;
    CPen* m_penSelect;
    CPen* m_penNormal;
    CBrush* m_brhSelect;
    CBrush* m_brhNormal;

    CSize m_sizMenu;
    struct sBMP
    {
        const CBitmap* bmpChecked;
        const CBitmap* bmpUncheck;
        UINT id;
    };
    struct sPNG
    {
        Image* pngChecked;
        Image* pngUncheck;
        UINT id;
    };

    CArray <sBMP, sBMP&> m_bmps;
    CArray <sPNG, sPNG&> m_pngs;
};

