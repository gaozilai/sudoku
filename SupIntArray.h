#pragma once
#define INT_ARR_PAGE 4096
#include <afxmt.h>

class SupIntArray
{
public:
    SupIntArray(void)
    {
        m_iAlloc = 0;
        m_pArray = NULL; 
        m_iCount = 0;
    }

    virtual ~SupIntArray(void){delete[] m_pArray;}
    void Add(int i)
    {
        m_Lock.Lock();
        if (m_iCount >= m_iAlloc)
        {
            int* pNew = new int[m_iAlloc + INT_ARR_PAGE];
            memcpy(pNew, m_pArray, m_iAlloc * sizeof(int));
            m_iAlloc += INT_ARR_PAGE;
            delete[] m_pArray;
            m_pArray = pNew;
        }

        m_pArray[m_iCount] = i;
        m_iCount++;
        m_Lock.Unlock();
    }
    void RemoveAt(int nIndex, int nCount)
    {
        m_Lock.Lock();
        memmove(m_pArray+nIndex, m_pArray+nIndex+nCount, (m_iCount-nIndex-nCount)*sizeof(int));
        m_iCount -= nCount;
        m_Lock.Unlock();
    }
    void RemoveAll()
    {
        m_Lock.Lock();
        m_iCount = 0;
        m_Lock.Unlock();
    }

    int GetAt(int index)
    {
        m_Lock.Lock();
        int i = m_pArray[index];
        m_Lock.Unlock();
        return i;
    }

    int GetCount()
    {
        m_Lock.Lock();
        int iCount = m_iCount;
        m_Lock.Unlock();
        return iCount;
    }

private:
    int* m_pArray;
    int m_iCount;
    int m_iAlloc;
    CCriticalSection m_Lock;
};

