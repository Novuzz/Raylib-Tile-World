#include "global.hpp"
#include <raylib.h>

int ** collisionMap;

void println(const char *text, ...)
{
    #if !defined(RAYGUI_TEXTFORMAT_MAX_SIZE)
        #define RAYGUI_TEXTFORMAT_MAX_SIZE   256
    #endif

    static char buffer[RAYGUI_TEXTFORMAT_MAX_SIZE];

    va_list args;
    va_start(args, text);
    vsnprintf(buffer, RAYGUI_TEXTFORMAT_MAX_SIZE, text, args);
    cout << buffer << "\n";
    va_end(args);

}