// STATUS: equivalent (tools/equiv.py level 3: 20007 inputs, branch coverage 18/18)
// FUN_00338710 @ 0x00338710
// 0x00338710: true if str (of length len, or its strlen when len <= 0) ends with suffix
#include "compat/ptr.h"
static inline hulk_uintptr strlen_inline(const char *s)
{
    const char *p = s;
    while (*p)
        p++;
    return p - s;
}
static inline int strcmp_inline(const char *a, const char *b)
{
    while (*a && *a == *b) {
        a++;
        b++;
    }
    return (unsigned char)*a - (unsigned char)*b;
}

bool __stdcall FUN_00338710(const char* str, const char* suffix, int len)
{
    if (len <= 0)
        len = (int)(__int64)strlen_inline(str);
    int suffixLen = (int)(__int64)strlen_inline(suffix);
    if (suffixLen > len)
        return false;
    return strcmp_inline(suffix, str + (len - suffixLen)) == 0;
}
