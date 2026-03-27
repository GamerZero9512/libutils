#include "utils.h"

bool WINCON_ANSI_ENABLED = false;

int vlenasstr(const char* fmt, va_list args) {
    va_list copy;
    va_copy(copy, args);
    int len = vsnprintf(NULL, 0, fmt, copy);
    va_end(copy);
    return len;
}

int lenasstr(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    int len = vlenasstr(fmt, args);
    va_end(args);
    return len;
}

char* vtostring(const char* fmt, va_list args) {
    int len = vlenasstr(fmt, args);
    if(len < 0) return NULL;
    char* str = malloc(len + 1);
    if(!str) return NULL;
    va_list copy;
    va_copy(copy, args);
    vsnprintf(str, len + 1, fmt, copy);
    va_end(copy);
    return str;
}

char* tostring(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    char* result = vtostring(fmt, args);
    va_end(args);
    return result;
}

void vpanic(const char* fmt, va_list args) {
    if(!WINCON_ANSI_ENABLED) enable_wincon_ansi();
    fprintf(stderr, "%spanic:%s ", ANSI_FG_BRIGHT_RED, ANSI_RESET);
    vfprintf(stderr, fmt, args);
    fputc('\n', stderr);
    exit(EXIT_FAILURE);
}

void panic(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vpanic(fmt, args);
    va_end(args);
}

void enable_wincon_ansi(void) {
#if IS_WINDOWS
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hErr = GetStdHandle(STD_ERROR_HANDLE);
    if(hOut != INVALID_HANDLE_VALUE) {
        DWORD modeOut = 0;
        if(GetConsoleMode(hOut, &modeOut)) SetConsoleMode(hOut, modeOut | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }
    if(hErr != INVALID_HANDLE_VALUE) {
        DWORD modeErr = 0;
        if(GetConsoleMode(hErr, &modeErr)) SetConsoleMode(hErr, modeErr | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }
#endif
    WINCON_ANSI_ENABLED = true;
}

int ANSI_CUR_GET_POS(int* x, int* y) {
    int r = 0, c = 0;
    int ch;
    if(write(STDOUT_FILENO, "\x1b[6n", 4) != 4) return -1;
    if((ch = getchar()) != 0x1b) return -1;
    if((ch = getchar()) != '[') return -1;
    while((ch = getchar()) >= '0' && ch <= '9') r = r * 10 + (ch - '0');
    if(ch != ';') return -1;
    while((ch = getchar()) >= '0' && ch <= '9') c = c * 10 + (ch - '0');
    if(ch !=  'R') return -1;
    *x = r;
    *y = c;
    return 0;
}