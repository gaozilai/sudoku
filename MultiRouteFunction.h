#pragma once
class CMultiRouteFunction
{
    struct PROCESS_PARA
    {
        void* pIn;
        void* pOut;
        void* pReserve1;
        void* pReserve2;
        int iWid;
        int iHei;
        int iReserve1;
        int iReserve2;
    };
    struct THREADPARA
    {
        int _id;
        HANDLE _hEvent;
        HANDLE _hExitEvent;
        void* _pContext;
    };

public:
    CMultiRouteFunction(void);
    ~CMultiRouteFunction(void);
    void Init(int iProcessor = 0);
    void RGB32ToY(BYTE *pY, const DWORD *pRGB8888, int iLen);


private:
    static UINT ProcessThread( LPVOID pParam );
    void Finished();

    int m_iNumberOfProcessors;
    HANDLE* m_hEvent;
    HANDLE* m_hThreadFinished;
    HANDLE* m_hProcessFinished;
    CCriticalSection m_csLock;

    PROCESS_PARA* m_pProcessParam;
    enum PROCESS_TYPE
    {
        RGB32TOGRAY,

        UNKNOWN
    } m_ProcessType;
};

