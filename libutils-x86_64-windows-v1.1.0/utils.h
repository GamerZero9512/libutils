#pragma once

#ifndef UTILS_H
#define UTILS_H

#define UTILS_VERSION "1.1.0"

#define UTILS_VERSION_MAJOR 1
#define UTILS_VERSION_MINOR 1
#define UTILS_VERSION_PATCH 0

// =============== OS DETECTOR ===============

#define OS_UNKNOWN 0
#define OS_WINDOWS 1
#define OS_LINUX 2
#define OS_MACOS 3

#if defined(_WIN32) || defined(_WIN64)
    #define OS "Windows"
    #define OS_TYPE OS_WINDOWS
    #define IS_UNKNOWN 0
    #define IS_WINDOWS 1
    #define IS_LINUX 0
    #define IS_MACOS 0
#elif defined(__linux__)
    #define OS "Linux"
    #define OS_TYPE OS_LINUX
    #define IS_UNKNOWN 0
    #define IS_WINDOWS 0
    #define IS_LINUX 1
    #define IS_MACOS 0
#elif defined(__APPLE__) && defined(__MACH__)
    #define OS "macOS"
    #define OS_TYPE OS_MACOS
    #define IS_UNKNOWN 0
    #define IS_WINDOWS 0
    #define IS_LINUX 0
    #define IS_MACOS 1
#else
    #ifndef UTILS_ALLOW_UNKNOWN_PLATFORM
        #error "utils: unrecognised platform"
    #else
        #define OS "Unknown"
        #define OS_TYPE OS_UNKNOWN
        #define IS_UNKNOWN 1
	#define IS_WINDOWS 0
	#define IS_LINUX 0
	#define IS_MACOS 0
    #endif
#endif

// =============== ANSI CODES ==============

#define ANSI_CUR_HOME "\x1b[H"
#define ANSI_CUR_POS(x, y) tostring("\x1b[%d;%dH", x, y)
#define ANSI_CUR_UP(y) tostring("\x1b[%dA", y)
#define ANSI_CUR_DOWN(y) tostring("\x1b[%dB", y)
#define ANSI_CUR_RIGHT(x) tostring("\x1b[%dC", x)
#define ANSI_CUR_LEFT(x) tostring("\x1b[%dD", x)
#define ANSI_CUR_LINE_DOWN(y) tostring("\x1b[%dE", y)
#define ANSI_CUR_LINE_UP(y) tostring("\x1b[%dF", y)
#define ANSI_CUR_COLUMN(x) tostring("\x1b[%dG", x)
#define ANSI_CUR_UP_ONE "\x1bM"
#define ANSI_CUR_SAVE_LEGACY "\x1b7"
#define ANSI_CUR_RESTORE_LEGACY "\x1b8"
#define ANSI_CUR_SAVE "\x1b[s"
#define ANSI_CUR_RESTORE "\x1b[u"

#define ANSI_ERASE_FROM_CUR "\x1b[J"
#define ANSI_ERASE_UNTIL_CUR "\x1b[1J"
#define ANSI_ERASE_ALL "\x1b[2J"
#define ANSI_ERASE_SAVED "\x1b[3J"
#define ANSI_ERASE_LINE_FROM_CUR "\x1b[K"
#define ANSI_ERASE_LINE_UNTIL_CUR "\x1b[1K"
#define ANSI_ERASE_LINE "\x1b[2K"

#define ANSI_RESET "\x1b[0m"
#define ANSI_STYLE_BOLD "\x1b[1m"
#define ANSI_RESET_STYLE_BOLD "\x1b[22m"
#define ANSI_STYLE_DIM "\x1b[2m"
#define ANSI_RESET_STYLE_DIM "\x1b[22m"
#define ANSI_STYLE_ITALIC "\x1b[3m"
#define ANSI_RESET_STYLE_ITALIC "\x1b[23m"
#define ANSI_STYLE_UNDERLINE "\x1b[4m"
#define ANSI_RESET_STYLE_UNDERLINE "\x1b[24m"
#define ANSI_STYLE_BLINK "\x1b[5m"
#define ANSI_RESET_STYLE_BLINK "\x1b[25m"
#define ANSI_STYLE_REVERSE "\x1b[7m"
#define ANSI_RESET_STYLE_REVERSE "\x1b[27m"
#define ANSI_STYLE_HIDDEN "\x1b[8m"
#define ANSI_RESET_STYLE_HIDDEN "\x1b[28m"
#define ANSI_STYLE_STRIKETHROUGH "\x1b[9m"
#define ANSI_RESET_STYLE_STRIKETHROUGH "\x1b[29m"

#define ANSI_FG_BLACK "\x1b[30m"
#define ANSI_BG_BLACK "\x1b[40m"
#define ANSI_FG_RED "\x1b[31m"
#define ANSI_BG_RED "\x1b[41m"
#define ANSI_FG_GREEN "\x1b[32m"
#define ANSI_BG_GREEN "\x1b[42m"
#define ANSI_FG_YELLOW "\x1b[33m"
#define ANSI_BG_YELLOW "\x1b[43m"
#define ANSI_FG_BLUE "\x1b[34m"
#define ANSI_BG_BLUE "\x1b[44m"
#define ANSI_FG_MAGENTA "\x1b[35m"
#define ANSI_BG_MAGENTA "\x1b[45m"
#define ANSI_FG_CYAN "\x1b[36m"
#define ANSI_BG_CYAN "\x1b[46m"
#define ANSI_FG_WHITE "\x1b[37m"
#define ANSI_BG_WHITE "\x1b[47m"
#define ANSI_FG_DEFAULT "\x1b[39m"
#define ANSI_BG_DEFAULT "\x1b[49m"

#define ANSI_FG_BRIGHT_BLACK "\x1b[90m"
#define ANSI_BG_BRIGHT_BLACK "\x1b[100m"
#define ANSI_FG_BRIGHT_RED "\x1b[91m"
#define ANSI_BG_BRIGHT_RED "\x1b[101m"
#define ANSI_FG_BRIGHT_GREEN "\x1b[92m"
#define ANSI_BG_BRIGHT_GREEN "\x1b[102m"
#define ANSI_FG_BRIGHT_YELLOW "\x1b[93m"
#define ANSI_BG_BRIGHT_YELLOW "\x1b[103m"
#define ANSI_FG_BRIGHT_BLUE "\x1b[94m"
#define ANSI_BG_BRIGHT_BLUE "\x1b[104m"
#define ANSI_FG_BRIGHT_MAGENTA "\x1b[95m"
#define ANSI_BG_BRIGHT_MAGENTA "\x1b[105m"
#define ANSI_FG_BRIGHT_CYAN "\x1b[96m"
#define ANSI_BG_BRIGHT_CYAN "\x1b[106m"
#define ANSI_FG_BRIGHT_WHITE "\x1b[97m"
#define ANSI_BG_BRIGHT_WHITE "\x1b[107m"

#define ANSI_FG_256(a) tostring("\x1b[38;5;%dm", a)
#define ANSI_BG_256(a) tostring("\x1b[48;5;%dm", a)
#define ANSI_FG_RGB(r, g, b) tostring("\x1b[38;2;%d;%d;%dm", r, g, b)
#define ANSI_BG_RGB(r, g, b) tostring("\x1b[48;2;%d;%d;%dm", r, g, b)

#define ANSI_ENABLE_WRAP "\x1b[?7h"
#define ANSI_DISABLE_WRAP "\x1b[?7l"

#define ANSI_CUR_HIDE "\x1b[?25l"
#define ANSI_CUR_SHOW "\x1b[?25h"
#define ANSI_SAVE_SCREEN "\x1b[?47h"
#define ANSI_RESTORE_SCREEN "\x1b[?47l"
#define ANSI_ALT_BUFFER_ENABLE "\x1b[?1049h"
#define ANSI_ALT_BUFFER_DISABLE "\x1b[?1049l"

#define ANSI_SET_TITLE(a) tostring("\x1b]0;%s\x1b\\", a)

// =============== INCLUDES ===============

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#if IS_WINDOWS
#define NOMINMAX
#include <windows.h>
#endif

// =============== FUNCTIONS ===============

int vlenasstr(const char* fmt, va_list args);
int lenasstr(const char* fmt, ...);
char* tostring(const char* fmt, ...);
char* vtostring(const char* fmt, va_list args);

static inline int imax(int a, int b) { return a > b ? a : b; }
static inline double dmax(double a, double b) { return a > b ? a : b; }
static inline int imin(int a, int b) { return a < b ? a : b; }
static inline double dmin(double a, double b) { return a < b ? a : b; }
static inline int iclamp(int val, int min, int max) {
    if(val > max) return max;
    if(val < min) return min;
    return val;
}
static inline double dclamp(double val, double min, double max) {
    if(val > max) return max;
    if(val < min) return min;
    return val;
}
void panic(const char* fmt, ...);
void vpanic(const char* fmt, va_list args);
static inline void fastwrite(int stream, const char* string) {
    write(stream, string, strlen(string));
}
void enable_wincon_ansi(void);
int ANSI_CUR_GET_POS(int* x, int* y);
static inline char* timestr(time_t* t) {
    return tostring(ctime(&(time_t){time(t)}));
}

// =============== MACROS ===============

#define max(a, b) _Generic((a), int: imax, double: dmax)(a, b)
#define min(a, b) _Generic((a), int: imin, double: dmin)(a, b)
#define clamp(val, mn, mx) _Generic((val), int: iclamp, double: dclamp)(val, mn, mx)
#define sz_fastwrite(stream, string) write(stream, string, sizeof(string) - 1)

#ifdef _MSC_VER
    #define arrlen(arr) (sizeof(arr) / sizeof((arr)[0]))
#else
    #define arrlen(arr) (sizeof(arr) / sizeof((arr)[0]) + 0 * _Static_assert(!__builtin_types_compatible_p(typeof(arr), typeof(&arr[0])), "arrlen: expected array, got pointer"))
#endif

#endif

// =============== VARIABLES ===============

extern bool WINCON_ANSI_ENABLED;