#pragma once
#include "SupIntArray.h"
#include <afxcmn.h>

#define COLUMN_COUNT 5
class CListData  
{
public:
    struct LIST_INFO
    {
        CString strData[COLUMN_COUNT]; 
        BOOL bDefect;
    };
    
public:
    CListData();
    virtual ~CListData();
    void Release();
    void Add(LIST_INFO* pInfo);
    int GetCount();
    LIST_INFO *Item(int nIndex);

private:
    CArray<LIST_INFO*, LIST_INFO*> m_arrayData; 
    CCriticalSection m_Lock;
};

class CVListCtrl : public CListCtrl
{
public:
	CVListCtrl(CListData *pList);
	virtual ~CVListCtrl();
    void UpdateList(UINT iSelect = -1, SupIntArray* pFilter = NULL);

protected:
    CListData* m_pArrData;
    SupIntArray* m_pArrFilter;

protected:
    DECLARE_MESSAGE_MAP()
	afx_msg void OnGetdispinfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult);
};
