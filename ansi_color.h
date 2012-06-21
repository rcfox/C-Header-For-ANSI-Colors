#ifndef ANSI_COLOR_H
#define ANSI_COLOR_H

#define COLOR_PREFIX     "\e["
#define COLOR_SEP        ";"
#define COLOR_SUFFIX     "m"

#define COLOR_BLACK      "0"
#define COLOR_RED        "1"
#define COLOR_GREEN      "2"
#define COLOR_YELLOW     "3"
#define COLOR_BLUE       "4"
#define COLOR_MAGENTA    "5"
#define COLOR_CYAN       "6"
#define COLOR_WHITE      "7"

#define COLOR_FOREGROUND "3"
#define COLOR_BACKGROUND "4"

#define COLOR_SGR_CODE(number) COLOR_SEP #number
#define COLOR_BOLD      COLOR_SGR_CODE(1)
#define COLOR_UNDERLINE COLOR_SGR_CODE(4)
#define COLOR_BLINK     COLOR_SGR_CODE(5)
#define COLOR_REVERSE   COLOR_SGR_CODE(7)
#define COLOR_INVISIBLE COLOR_SGR_CODE(8)

#define COLOR_RESET COLOR_PREFIX "0" COLOR_SUFFIX

/* Handle unspecified macro arguments. */
#define COLOR_ ""

/* Support up to 8 attributes */
#define COLOR_ATTR_REC8(attr,...) COLOR_##attr 
#define COLOR_ATTR_REC7(attr,...) COLOR_##attr COLOR_ATTR_REC8(__VA_ARGS__)
#define COLOR_ATTR_REC6(attr,...) COLOR_##attr COLOR_ATTR_REC7(__VA_ARGS__)
#define COLOR_ATTR_REC5(attr,...) COLOR_##attr COLOR_ATTR_REC6(__VA_ARGS__)
#define COLOR_ATTR_REC4(attr,...) COLOR_##attr COLOR_ATTR_REC5(__VA_ARGS__)
#define COLOR_ATTR_REC3(attr,...) COLOR_##attr COLOR_ATTR_REC4(__VA_ARGS__)
#define COLOR_ATTR_REC2(attr,...) COLOR_##attr COLOR_ATTR_REC3(__VA_ARGS__)
#define COLOR_ATTR_REC(attr,...) COLOR_##attr COLOR_ATTR_REC2(__VA_ARGS__)

#define ANSI_COLOR(forecolor,...)               \
    COLOR_PREFIX                                \
    COLOR_FOREGROUND COLOR_##forecolor          \
    COLOR_ATTR_REC(__VA_ARGS__)                 \
    COLOR_SUFFIX

#define ANSI_COLOR2(forecolor,backcolor,...)    \
    COLOR_PREFIX                                \
    COLOR_FOREGROUND COLOR_##forecolor          \
    COLOR_SEP                                   \
    COLOR_BACKGROUND COLOR_##backcolor          \
    COLOR_ATTR_REC(__VA_ARGS__)                 \
    COLOR_SUFFIX

#define COLORIZE(text,forecolor,...) ANSI_COLOR(forecolor,__VA_ARGS__) text COLOR_RESET
#define COLORIZE2(text,forecolor,backcolor,...) ANSI_COLOR2(forecolor,backcolor,__VA_ARGS__) text COLOR_RESET

#endif
