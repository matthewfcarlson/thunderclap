// Same code shape as 0x000964a0 (propagated; names are from that function)
#include "compat/ptr.h"
extern int __cdecl __vsnprintf(char*, int, const char*, void*);

void FUN_000dfcc0(char* buffer, int size, const char* format, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, format);
#else
    char* args = (char*)&format + 4;
#endif
    int result = __vsnprintf(buffer, size, format, args);
    if (size > 0 && result == -1)
        buffer[size - 1] = 0;
}