#include "compat/ptr.h"
extern "C" int __cdecl _vsnprintf(char*, unsigned int, const char*, char*);
extern "C" unsigned int __cdecl strlen(const char*);
struct Writer {
    int unused;
    int(__cdecl* write)(Writer*, const char*, int);
};
int __cdecl FUN_00246f50(Writer* w, const char* fmt, ...) {
    char buf[1024];
#if defined(HULK_PTR64)
    __builtin_va_list va;
    __builtin_va_start(va, fmt);
    _vsnprintf(buf, 1024, fmt, va);
#else
    _vsnprintf(buf, 1024, fmt, (char*)&fmt + 4);
#endif
    buf[1023] = 0;
    return w->write(w, buf, strlen(buf));
}