// Author: 中村宥哉
// 情報表示関数の定義

#ifndef DISPLAYINFORMATION
#define DISPLAYINFORMATION

namespace display
{
    void displayInformation ()
    {
        switch (state)
        {
        case 0:
            displayRule();
            break;
        }
    }
}

#endif