#include "compat/ptr.h"
struct Ctx;
struct Parser_245b00 {
    char pad[0x90];
    int line;
};
bool F2(Ctx* c, const char* s, ...);
int vfmt(char* buf, int n, const char* fmt, char* va);
bool Err(Parser_245b00* p, Ctx* c, const char* fmt, ...) {
    char buf[0x1000];
#if defined(HULK_PTR64)
    __builtin_va_list va;
    __builtin_va_start(va, fmt);
    vfmt(buf, 0x1000, fmt, va);
#else
    vfmt(buf, 0x1000, fmt, (char*)&fmt + 4);
#endif
    F2(c, buf);
    F2(c, "\nError Line: [%d]\n", p->line);
    return false;
}
