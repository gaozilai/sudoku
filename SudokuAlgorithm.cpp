#include <sstream>
#include "SudokuAlgorithm.h"

#if defined(_WIN32)
#include "Winsync.h"
#endif

#define TIME_CTRL 0
#if !defined(min)
#define min( a, b ) ( ( (a) < (b) ) ? (a) : (b) )
#endif
#define arr_count(a) (sizeof(a)/sizeof(a[0]))

CSudokuSolve::CSudokuSolve(void)
{
    m_bTimCtrl = TIME_CTRL;
    m_iSolveCnt = 0;
    for (int i = 0; i < arr_count(m_solves) ; i++)
    {
    	m_solves[i] = new unsigned char[9*9];
    }
}

CSudokuSolve::~CSudokuSolve(void)
{
    for (int i = 0; i < arr_count(m_solves) ; i++)
    {
        delete[] m_solves[i];
    }
}

void CSudokuSolve::Search(int iTimeStart)
{
    if (m_bTimCtrl)
    {
        int iNow = GetNowClock();
        if (iNow - iTimeStart > 1000 * 60)
        {
            throw(-1);
        }
    }
    unsigned char btMask[10];
    int iMinX, iMinY, iMin = 10;
    for (int i = 0; i < 9 ; i++)
    {
    	for (int j = 0; j < 9 ; j++)
    	{
    		if (m_data[i][j])
    		{
                continue;
    		}
            int iUnc = Uncertainty(i, j, btMask);
            if (iUnc == 0)
            {
                return;
            }
            if (iUnc < iMin)
            {
                iMin = iUnc;
                iMinX = i;
                iMinY = j;
                if (iMin == 1) break;
            }
    	}
        if (iMin == 1) break;
    }
    if (iMin == 10) // all filled.
    {
        memcpy(m_solves[m_iSolveCnt], m_data, sizeof(m_data));
        m_iSolveCnt++;
        if (m_iSolveCnt >= m_iSolveMax)
        {
            throw(1);
        }
        return;
    }
    Uncertainty(iMinX, iMinY, btMask);
    for (int i = 1; i < 10 ; i++)
    {
    	if (btMask[i])
    	{
            m_data[iMinX][iMinY] = i;
            Search(iTimeStart);
    	}
    }
    m_data[iMinX][iMinY] = 0;
}

bool CSudokuSolve::CheckUnique()
{
    for (int i = 0; i < 9 ; i++)
    {
    	for (int m = 0; m < 9 ; m++)
    	{
    		for (int n = m + 1; n < 9 ; n++)
    		{
    			if (m_data[i][m] != 0 && m_data[i][m] == m_data[i][n])
    			{
                    return 0;
    			}
    		}
    	}
    } 

    for (int i = 0; i < 9 ; i++)
    {
        for (int m = 0; m < 9 ; m++)
        {
        	for (int n = m + 1; n < 9 ; n++)
        	{
                if (m_data[m][i] != 0 && m_data[m][i] == m_data[n][i])
                {
                    return 0;
                }
        	}
        }
    }

    unsigned char btTemp[9];
    for (int i = 0; i < 9 ; i+=3)
    {
    	for (int j = 0; j < 9 ; j+=3)
    	{
    		memcpy(btTemp, &m_data[i][j], 3);
            memcpy(btTemp+3, &m_data[i + 1][j], 3);
            memcpy(btTemp+6, &m_data[i + 2][j], 3);
            for (int m = 0; m < 9 ; m++)
            {
            	for (int n = m + 1; n < 9 ; n++)
            	{
            		if (btTemp[m] != 0 && btTemp[m] == btTemp[n])
            		{
                        return 0;
            		}
            	}
            }
    	}
    }
    return 1;
}

int CSudokuSolve::Uncertainty(int x, int y, unsigned char* pMark)
{
    int iCount = 0;
    for (int i = 0; i < 10 ; i++)
    {
    	pMark[i] = 1;
    }

    for (int i = 0; i < 9 ; i++)
    {
    	pMark[m_data[x][i]] = 0;
    }
    for (int i = 0; i < 9 ; i++)
    {
    	pMark[m_data[i][y]] = 0;
    }

    int iX = x / 3 * 3;
    int iY = y / 3 * 3;
    for (int i = 0; i < 3 ; i++)
    {
        for (int j = 0; j < 3 ; j++)
        {
        	pMark[m_data[iX+i][iY+j]] = 0;
        }    	
    }
    for (int i = 1; i < 10 ; i++)
    {
    	iCount += pMark[i];
    }
    return iCount;
}

bool CSudokuSolve::IfSolved()
{
    return m_iSolveCnt > 0;

    bool bSolved = 1;
    for (int i = 0; i < 9 ; i++)
    {
        for (int j = 0; j < 9 ; j++)
        {
            if (m_data[i][j] == 0)
            {
                bSolved = 0;
                break;
            }
        }
    }
    return bSolved;
}

int CSudokuSolve::Calculate(unsigned char* pSudoku, int iBufferLen, int iSolvesMax)
{
    if (iBufferLen != 9*9) return 0;
    if (iSolvesMax > arr_count(m_solves))
    {
        printf("\n\033[31m I can only calculate up to %d results, continue? (y/n)\033[0m", (int)arr_count(m_solves));

        char choice[10];
        scanf("%s", choice);
        if (choice[0] != 'y' && choice[0] != 'Y')
        {
            return 0;
        }
    }

    m_iSolveMax = min(iSolvesMax, arr_count(m_solves));
    
    for (int i = 0; i < 9*9 ; i++)
    {
    	int x = i / 9;
        int y = i % 9;
        m_data[x][y] = pSudoku[i];
    }

    if (CheckUnique() == 0){return 0;}

    try
    {
        Search(GetNowClock());
    }
    catch (int iE)
    {
        bool bContinue = false;
    	if (iE == -1)
    	{
            printf("Can't solved in 1 minute, continue solve? (y/n)");
            char choice[10];
            scanf("%s", choice);
            bContinue = choice[0] == 'y' || choice[0] == 'Y';
    	}
        if (bContinue)
        {
            m_bTimCtrl = 0;
            Calculate(pSudoku, iBufferLen, m_iSolveMax);
        }
    }

    m_bTimCtrl = TIME_CTRL;

    return m_iSolveCnt;

    // bool bSolved = IfSolved();
    // if (bSolved)
    // {
    //     for (int i = 0; i < 9*9 ; i++)
    //     {
    //         int x = i / 9;
    //         int y = i % 9;
    //         pSudoku[i] = m_data[x][y];
    //     }
    // }
    // return bSolved;
}

int CSudokuSolve::GetNowClock()
{
    int iNowClock = 0;
#if defined(_WIN32)
    iNowClock = GetTickCount();
#elif defined(linux) || defined(__LYNX)
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    iNowClock = ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
#endif
    return iNowClock;
}
