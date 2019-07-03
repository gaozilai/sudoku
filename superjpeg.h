#pragma once

#ifndef  DLL_JPGPROCESSING
#define  DLL_JPGPROCESSING extern "C" _declspec(dllimport)
#endif


/*==========================函数说明==========================*\
函数名称: DecompressJpg     
功能描述: 
    - 解压缩JPG数据到bmp缓存
返回值: 
    - TRUE, 成功; FALSE, 失败
参数: 
    filename    - IN 解压文件名
    pBmpBuffer  - IN/OUT 解压后的BMP数据缓存; 为NULL时,不解压，只返回图像大小信息
    nImgWidth   - OUT 图像宽度
    nImgHeight  - OUT 图像高度
    nPixelBytes - OUT 图像每个像素的位数， 1 或 4
作者: 高自来
创建日期: 2012-7-14
\*============================================================*/
DLL_JPGPROCESSING 
BOOL DecompressJpg(const char* filename, void* pBmpBuffer, int &nImgWidth, int &nImgHeight, int &nPixelBytes);

/*==========================函数说明==========================*\
函数名称: CompressToJpg     
功能描述: 
    - 压缩BMP数据成JPG文件 
返回值: 
    - TRUE, 成功; FALSE, 失败
参数: 
    pBmpData    - IN bmp数据
    nImgWidth   - IN 图像宽度
    nImgHeight  - IN 图像高度
    bColor      - IN 是否为彩色图像
    filename    - IN 压缩到文件的文件名
    nQuality    - IN 压缩质量(1-100)
作者: 高自来
创建日期: 2012-7-14
\*============================================================*/
DLL_JPGPROCESSING 
BOOL CompressToJpg(void* pBmpData, int nImgWidth, int nImgHeight, BOOL bColor, const char * filename, int nQuality);
