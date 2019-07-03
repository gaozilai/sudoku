#pragma once
#ifdef WIN32
#undef OS_WINDOWS
#include "snap7.h"
#pragma comment(lib, "snap7.lib")
#endif // WIN32
#include <afxmt.h>

#ifndef SWAP_BYTE_W
#define SWAP_BYTE_W(wd) MAKEWORD(HIBYTE(wd), LOBYTE(wd))
#endif
#ifndef SWAP_BYTE_DW
#define SWAP_BYTE_DW(dw) MAKELONG(SWAP_BYTE_W(HIWORD(dw)), SWAP_BYTE_W(LOWORD(dw))) 
#endif

class CPLCComm
{
public:
    virtual ~CPLCComm(void);
    static CPLCComm* Instance();
    BOOL Init(const char* ip, int Rack, int Slot, int dbNumber);
    BOOL Read(int Start, int Size, BYTE* buffer, int dbNumber = -1);
    BOOL Write(BYTE* buffer, int Start, int Size, int dbNumber = -1);
    const char* LastErrorMessage(){return m_szLastError;}

protected:
    BOOL m_bConnect;
    CPLCComm(void);
    void FormatErrorCode( int er );
    static CPLCComm* m_pInstance;
    S7Object m_plcClient;
    int m_dbNumber;
    CCriticalSection m_csPLC;
    char m_szLastError[10240];
};

