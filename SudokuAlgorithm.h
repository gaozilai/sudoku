#pragma once
#include <string.h>
#include <stdio.h>

class CSudokuSolve
{
public:
    // 构造函数
    CSudokuSolve(void);
	// 析构函数
    ~CSudokuSolve(void);
	// 计算函数
    int Calculate(unsigned char* pSudoku, int iBufferLen, int iSolvesMax);
    unsigned char* GetSolve(int iIndex)
    {
        return m_solves[iIndex];
    }

protected:
    int Uncertainty(int x, int y, unsigned char* pMark);
    void Search(int iTimeStart);
    bool IfSolved();
    bool CheckUnique();
    int GetNowClock();

private:
    unsigned char m_data[9][9];
    bool m_bTimCtrl;

    // all solves.
    unsigned char* m_solves[100000];
    int m_iSolveCnt;
    int m_iSolveMax;
};

