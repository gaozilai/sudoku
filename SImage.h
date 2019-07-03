#pragma once

class SImage // line buffer is not align to 4.
{
public:
    SImage(void);
    ~SImage(void);
    BOOL Load(const TCHAR* szFile, BOOL bUpsideDown = TRUE); //TRUE, like DIB, the first line of buffer is the last line of picture.
    BOOL Load(CFile* pFile, BOOL bUpsideDown = TRUE);
    BOOL SaveAs(const TCHAR* szFile, BOOL bUpsideDown = TRUE);
    BOOL SaveAs(CFile* pFile, BOOL bUpsideDown = TRUE);
    void SetImageSize(int iWid, int iHei, BOOL bGray);
    void SetImage(const void* pImage, int iWid, int iHei, BOOL bGray);
    void Release();

    void AttachData(void* pNewImage, int iWid, int iHei, BOOL bGray);
    void* DetachData();

    BOOL IsGray();
    int GetWidth();
    int GetHeight();
    void* Data();

    void MirrorV();
    void MirrorH();

    operator BYTE*() const
    {
        return m_pImage;
    }
    void CropImage(SImage& imgSrc, CRect rtRoi);
    void CopyImage(SImage& imgSrc);
    void ToGray();
    void Invert();

#if ((defined H_EMPTY_REGION) || (defined HALCON_CPP_H))
    BOOL ReadAnyImage(const char* szFile);
#else
    BOOL ReadAnyImage(const char* szFile){return FALSE;}
#endif

private:
    void RGB24ToRGB32(void *pSrc, void *pDst, int nWidth, int nHeight);
    int m_iWidth;
    int m_iHeight;
    BYTE* m_pImage;
    BOOL m_bGray;
};
