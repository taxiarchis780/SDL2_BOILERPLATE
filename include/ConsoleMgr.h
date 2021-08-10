#include <windows.h>


namespace ConsoleMgr
{

    enum Colors{
        ColorBlack = 0,
        ColorBlue = 1,
        ColorGreen = 2,
        ColorCyan = 3,
        ColorRed = 4,
        ColorMagenta = 5,
        ColorBrown = 6,
        ColorLightGray = 7,
        ColorDarkGray = 8,
        ColorLightBlue = 9,
        ColorLightGreen = 10,
        ColorLightCyan = 11,
        ColorLightRed = 12,
        ColorLightMagenta = 13,
        ColorYellow = 14,
        ColorWhite = 15
    };

    void SetColor(int value){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);
    }

    void ResetColor()
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  7);
    }

}