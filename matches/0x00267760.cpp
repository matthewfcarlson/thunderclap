#include "compat/ptr.h"
extern "C" int __cdecl __vsnprintf(char*, unsigned int, const char*, char*);
extern "C" void FUN_00267760(char* buffer, unsigned int size, const char* format, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, format);
    __vsnprintf(buffer, size, format, args);
#else
    __vsnprintf(buffer, size, format, (char*)&format + 4);
#endif
    if (!(size <= 0U))
        buffer[size - 1] = 0;
}