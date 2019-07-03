// V2.0 ManageCam接口增加 "void* pContext" 参数，用于回调函数ProcessCallback

#ifndef _CAPTURE_FACTORY_INSTANCE_DECLARE__H_
#define _CAPTURE_FACTORY_INSTANCE_DECLARE__H_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef void (CALLBACK *ProcessCallback)(int iCamId, const BYTE* pImage, void* pContext);

class CFireCamera
{
protected:
    int m_iCamId;
	ProcessCallback m_pProcess;

public:
    virtual ~CFireCamera() = 0 {}
    CFireCamera(int iCamid, ProcessCallback process){m_iCamId = iCamid; m_pProcess = process;}
    int GetCamId() const {return m_iCamId;} 

public:
	virtual const char* GetDeviceName(){return "";}
	virtual bool Start() = 0;
	virtual bool Stop() = 0;
	virtual int GetImageWidth() = 0;
	virtual int GetImageHeight() = 0;
    virtual int GetImageBytes(){return 1;}
    virtual bool SoftTrigger(){return false;}

public:
    virtual void ShowImage(bool bShow){}
    // dynamic setting.
    enum DynPropertyType
    {
        DYN_BRIGHTNESS, /**< Brightness. */
        DYN_AUTO_EXPOSURE, /**< Auto exposure. */
        DYN_SHARPNESS, /**< Sharpness */
        DYN_WHITE_BALANCE, /**< White balance. */
        DYN_HUE, /**< Hue. */
        DYN_SATURATION, /**< Saturation. */
        DYN_GAMMA, /**< Gamma. */
        DYN_IRIS, /**< Iris. */
        DYN_FOCUS, /**< Focus. */
        DYN_ZOOM, /**< Zoom. */
        DYN_PAN, /**< Pan. */
        DYN_TILT, /**< Tilt. */
        DYN_SHUTTER, /**< Shutter. */
        DYN_GAIN, /**< Gain. */
        DYN_TRIGGER_MODE, /**< Trigger mode. */
        DYN_TRIGGER_DELAY, /**< Trigger delay. */
        DYN_FRAME_RATE, /**< Frame rate. */
        DYN_TEMPERATURE, /**< Temperature. */
        DYN_UNSPECIFIED_PROPERTY_TYPE, /**< Unspecified property type. */
    };
    virtual int DynPropertyValue(DynPropertyType dType, int iValue){return -1;}// return current property value. (iValue<0, ignore.)
    // 参数意义参看说明FacCapture.txt; 
    virtual void SetParamAddOn(int iType, WPARAM wParam, LPARAM lParam){}
    virtual void* GetParamAddOn(int iType, WPARAM wParam, LPARAM lParam){return NULL;}
};

class CCaptureFac
{
public:
    virtual ~CCaptureFac() = 0 {}

	virtual bool Init(){return false;}
    virtual CFireCamera* ManageCam(int iCamid, ProcessCallback process, void* pContext) = 0;    // base 1.
    virtual void ReleaseCam(CFireCamera*& pCam) = 0;

};

typedef CCaptureFac* (*FCreateFactory)();
typedef void (*FDestroyFactory)(CCaptureFac*&);

#endif