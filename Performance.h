#pragma once
class SupPerformance
{
public:
	SupPerformance(){QueryPerformanceFrequency(&m_CounterFrequency);}
	void Reset(){QueryPerformanceCounter(&m_ResetTime);}
	float GetTime(BOOL bReset)      { return (float)ComputeTime(bReset); }
	float GetTimeMilli(BOOL bReset)	{ return (float)(ComputeTime(bReset) * 1000.0); }
	float GetTimeMicro(BOOL bReset)	{ return (float)(ComputeTime(bReset) * 1000000.0); }

protected:
	double ComputeTime(BOOL bReset)
	{
		LARGE_INTEGER CrrentTime;
		QueryPerformanceCounter(&CrrentTime);
		double fSpan = (CrrentTime.QuadPart - m_ResetTime.QuadPart) / (double)m_CounterFrequency.QuadPart;
		if (bReset) m_ResetTime = CrrentTime;
		return fSpan;
	}

protected:
	LARGE_INTEGER m_CounterFrequency;
	LARGE_INTEGER m_ResetTime;
};
