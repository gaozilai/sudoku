#pragma once

#ifdef LOG_CLS_EXPORT
#define LOG_CLASS _declspec(dllexport)
#else
#define LOG_CLASS _declspec(dllimport)
#endif 

class LOG_CLASS CLog
{
public:
	~CLog(void);
	static CLog* Instance();
	void Init(const char* szName);
	void Release();	// after released, the instance of CLog is can not used again.
	int PushLog(const char* szName, const char *szLine, ...); // return: 1 for success; 0 for failed; less than 0 is the count of dropped chars.

protected:
	CLog();
};

