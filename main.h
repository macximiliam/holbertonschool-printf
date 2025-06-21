#ifndef MAIN_H
#define MAIN_H
/*
 * Structs, enums and unions definitions
 * Typedefs
 * Function prototypes
 */
#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int print_str(va_list args);

#endif  /* MAIN_H */
