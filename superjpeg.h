#pragma once

#ifndef  DLL_JPGPROCESSING
#define  DLL_JPGPROCESSING extern "C" _declspec(dllimport)
#endif


/*==========================����˵��==========================*\
��������: DecompressJpg     
��������: 
    - ��ѹ��JPG���ݵ�bmp����
����ֵ: 
    - TRUE, �ɹ�; FALSE, ʧ��
����: 
    filename    - IN ��ѹ�ļ���
    pBmpBuffer  - IN/OUT ��ѹ���BMP���ݻ���; ΪNULLʱ,����ѹ��ֻ����ͼ���С��Ϣ
    nImgWidth   - OUT ͼ����
    nImgHeight  - OUT ͼ��߶�
    nPixelBytes - OUT ͼ��ÿ�����ص�λ���� 1 �� 4
����: ������
��������: 2012-7-14
\*============================================================*/
DLL_JPGPROCESSING 
BOOL DecompressJpg(const char* filename, void* pBmpBuffer, int &nImgWidth, int &nImgHeight, int &nPixelBytes);

/*==========================����˵��==========================*\
��������: CompressToJpg     
��������: 
    - ѹ��BMP���ݳ�JPG�ļ� 
����ֵ: 
    - TRUE, �ɹ�; FALSE, ʧ��
����: 
    pBmpData    - IN bmp����
    nImgWidth   - IN ͼ����
    nImgHeight  - IN ͼ��߶�
    bColor      - IN �Ƿ�Ϊ��ɫͼ��
    filename    - IN ѹ�����ļ����ļ���
    nQuality    - IN ѹ������(1-100)
����: ������
��������: 2012-7-14
\*============================================================*/
DLL_JPGPROCESSING 
BOOL CompressToJpg(void* pBmpData, int nImgWidth, int nImgHeight, BOOL bColor, const char * filename, int nQuality);
