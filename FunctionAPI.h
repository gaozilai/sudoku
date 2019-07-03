
#ifndef _INC_FunctionAPI_H
#define _INC_FunctionAPI_H

namespace SupAPI
{
    // string...
    void FindSection(const TCHAR* strOri, CStringList& listStr, const TCHAR* pSep);// 以pSep为分隔符，肢解CString字段
    CString GetMainPath();// 获得EXE目录，包含最后一个'\'
    CString FormatString(const TCHAR* String, ...);
    char* new_ascii_from_wchar(const wchar_t* wString);
    wchar_t* new_wchar_from_ascii(const char* aString);
    CString UTF8ToANSI(const char* str);
    CString ANSIToUTF8(const char* str);
    int CountOf(CString string, const TCHAR* pSep);
    CRect TransRect( CString strRect );


    // folder...
    BOOL SelFolder(HWND hParent, CString &strFolder);// 选择文件夹对话框
    BOOL CreateFolder(CString strFolder);// 创建文件夹 允许多级
    BOOL DeleteFolder(CString strFolder);
 

    // image...
    void CopyLocalImage(BYTE *pSrcImage,int nBufWidth,int nBufHeight, BYTE *pDstImage,int nPosX,int nPosY, int nWidth, int nHeight,int nBytesPerPixel);
    BOOL CopyRectImage(const BYTE* pSrc, int iSrcWid, int iSrcHei, CRect rtSrc, BYTE* pDst, int iDstWid, int iDstHei, CPoint ptDstPos, int iBytesPerPix);
    void DrawLineToImage(BYTE* pImage, int iWid, int iHei, int iBytesPerPxl, POINT pt1, POINT pt2, COLORREF clr);
    void DrawRectToImage( BYTE* pImage, int iWid, int iHei, int iBytesPerPxl, RECT rt, COLORREF clr );
    void Zoom(const void* pSrc, int iSrcWid, int iSrcHei, void* pDst, int iDstWid, int iDstHei, BOOL bGray);
    void ZoomEx(const void* pSrc, int iSrcWid, int iSrcHei, void* pDst, int iDstWid, int iDstHei, BOOL bGray);
    void ZoomOutEx32(const DWORD *pSrc, int nWidth, int nHeight, DWORD *pDest, int nDestWidth, int nDestHeight);
    void ZoomOutEx8(const BYTE *pSrc, int nWidth, int nHeight, BYTE *pDest, int nDestWidth, int nDestHeight);
    void ImageAdd(const BYTE* pSrc1, const BYTE* pSrc2, int iLen, OUT BYTE* pDst);
	void ImageAdd(const BYTE* pSrc1, BYTE bValue, int iLen, OUT BYTE* pDst);
    void ImageSub(const BYTE* pSrc1, const BYTE* pSrc2, int iLen, OUT BYTE* pDst);
    void ImageSub(const BYTE* pSrc1, BYTE bValue, int iLen, OUT BYTE* pDst);
    void ImageSubmulti(const BYTE* pSrc1, const BYTE* pSrc2, int iLen, float fFactor, OUT BYTE* pDst);
    void RGB32ToY(BYTE *pY, const DWORD *pRGB8888, int iLen, float fRWeight=0.299f, float fGWeight=0.587f, float fBWeight=0.114f);
    void RGB24ToRGB32(void *pSrc, void *pDst, int nWidth, int nHeight, BOOL bRBExchange = FALSE);
    void RGB32ToYRoi(const DWORD* pRGB8888, int iSrcWid, int iSrcHei, int iLeft, int iTop, int iRight, int iBottom, OUT BYTE* pY, float fRWeight=0.299f, float fGWeight=0.587f, float fBWeight=0.114f);
    BOOL InterpolateRect(const BYTE *pSrcImage, int nWidth, int nHeight, CRect roi, float fDx, float fDy, OUT BYTE *pDstImage);
    BOOL InterpolateRectEx(const BYTE* pSrc, int nWidth, int nHeight, float dx, float dy, OUT BYTE*& pDst); // 0 < dx,dy < 1 高精度
    void ProjectVert(const BYTE* pImage, int nWidth, int nHeight, int* pProj);
    void ProjectHori(const BYTE* pImage, int nWidth, int nHeight, int* pProj);
    void Projects(const BYTE* pImage, int nWidth, int nHeight, int* pProjHori, int* pProjVert);
    void ReverseImage(void* pImage, int nWidth, int nHeight, int nBytePerPixel);
    void MirrorImage_X(void* pImage, int nWidth, int nHeight, int nBytePerPixel);
    void MirrorImage_Y(void* pImage, int nWidth, int nHeight, int nBytePerPixel);
    void MergeImage(BYTE* pImageR, BYTE* pImageG, BYTE* pImageB, int nLength, DWORD* pData);
    void SplitImage(const DWORD* pImage, int nLength, OUT BYTE* pDataR, OUT BYTE* pDataG, OUT BYTE* pDataB);
	void InvertImage(BYTE* pImage, int iBytes, BYTE* pOut);
	void RGB32ComSub(BYTE *pY, const DWORD *pRGB8888, int iLen, int iR, int iG, int iB, int iAdd);
	void RGB32ComSubRoi(const DWORD* pRGB8888, int iSrcWid, int iSrcHei, int iLeft, int iTop, int iRight, int iBottom, OUT BYTE* pY, int iR, int iG, int iB, int iAdd);
    void Rotate270( void* pSrc, int nWidth, int nHeight, int nBytePerPixel, void* pDst );
    void Rotate90( void* pSrc, int nWidth, int nHeight, int nBytePerPixel, void* pDst );

    // others...
    void PointPointToLine(POINT pt1, POINT pt2, POINT* pLn);
    void matrix_multiply(double *a, int m, int n, int q, double *b, double *r); // a[m, n] x b[n, q] = r[m, q]
    BOOL inverse_matrix(double *deter, int determinant_scale);
    void LeastSquaresLine(double &dA, double &dB, double  X[], double Y[], int nCount); // y = a*x + b
}



#endif //_INC_FunctionAPI_H
