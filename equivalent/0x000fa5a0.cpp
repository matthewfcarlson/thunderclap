// STATUS: equivalent (tools/equiv.py level 3: 253 inputs, branch coverage 76/76)
// FUN_000fa5a0 @ 0x000fa5a0
#include "compat/ptr.h"
extern "C" char *__cdecl strncpy(char *dst, const char *src, unsigned int n);
extern "C" int __cdecl isdigit(int c);
inline void *operator new(unsigned int, void *p) throw() { return p; }

extern void *__cdecl FUN_0008d690(hulk_uintptr size);
extern char *__cdecl FUN_0008d6d0(hulk_uintptr size);
extern char *__cdecl FUN_003465c6(char *s, const char *delims);
extern double __cdecl FUN_003458c1(const char *s);

namespace DollyScript {

class CToken {
public:
    virtual void vfunc_0();
    virtual unsigned long long vfunc_1();
    virtual void vfunc_2();
    int next;
    int a;
    int b;
};

class CTokenStatement {
public:
    CTokenStatement(char *t, int a_, int b_) : next(0), a(a_), b(b_), text(t) {}
    virtual void vfunc_0();
    virtual unsigned long long vfunc_1();
    virtual void vfunc_2();
    int next;
    int a;
    int b;
    char *text;
};

class CTokenString {
public:
    CTokenString(char *t, int a_, int b_) : next(0), a(a_), b(b_), text(t) {}
    virtual void vfunc_0();
    virtual unsigned long long vfunc_1();
    virtual void vfunc_2();
    int next;
    int a;
    int b;
    char *text;
};

class CTokenSectionStart {
public:
    CTokenSectionStart(int b_) : next(0), a(0), b(b_) {}
    virtual void vfunc_0();
    virtual unsigned long long vfunc_1();
    virtual void vfunc_2();
    int next;
    int a;
    int b;
};

class CTokenSectionEnd {
public:
    CTokenSectionEnd(int b_) : next(0), a(0), b(b_) {}
    virtual void vfunc_0();
    virtual unsigned long long vfunc_1();
    virtual void vfunc_2();
    int next;
    int a;
    int b;
};

class CTokenHashed {
public:
    CTokenHashed *FUN_000f9c20(const char *name, int a, int b, int c);
};

class CTokenNumber {
public:
    CTokenNumber *FUN_000f9880(float v, int a, int b);
};

}


DollyScript::CToken * __stdcall FUN_000fa5a0(char **cur, const char *base, int a, int b, const char *copy)
{
    char c = **cur;
    if (c == '#')
        return 0;
    if (c == '(') {
        const char *start = (*cur - base) + copy;
        const char *q = start;
        int depth = 0;
        if (*start != 0) {
            do {
                char ch = *q;
                if (ch == '(')
                    depth++;
                else if (ch == ')')
                    depth--;
                q++;
                if (depth == 0)
                    break;
            } while (*q != 0);
        }
        hulk_uintptr len = q - start;
        char *buf = FUN_0008d6d0(len + 1);
        strncpy(buf, start, len);
        buf[len] = 0;
        void *mem = FUN_0008d690(0x14);
        DollyScript::CTokenStatement *t = 0;
        if (mem != 0)
            t = new (mem) DollyScript::CTokenStatement(buf, a, b);
        const char *endp = q + (base - copy);
        char *cursor = *cur;
        if (cursor != 0) {
            while (*cur < endp) {
                *cur = FUN_003465c6(0, " \t\n\r");
                if (*cur == 0)
                    break;
            }
        }
        return (DollyScript::CToken *)(void *)t;
    }
    if (c == '"') {
        const char *s = (*cur - base) + copy + 1;
        unsigned int count = 0;
        const char *p = s;
        char ch = *p;
        if (ch != 0 && ch != '"') {
            for (;;) {
                if (ch == '\\') {
                    ch = p[1];
                    p++;
                    if (ch == 0) {
                        count++;
                        break;
                    }
                }
                ch = p[1];
                count++;
                p++;
                if (ch == 0)
                    break;
                if (ch == '"')
                    break;
            }
        }
        count++;
        char *out = FUN_0008d6d0(count);
        char *dst = out;
        if (*s != 0) {
            for (;;) {
                char d = *s;
                if (d == '"') {
                    s++;
                    break;
                }
                if (d == '\\') {
                    d = s[1];
                    s++;
                    if (d == 0) {
                        *dst = '\\';
                        dst++;
                        s++;
                        break;
                    }
                    if (d == 'n')
                        d = 10;
                    else if (d == 't')
                        d = 9;
                }
                *dst = d;
                dst++;
                s++;
                if (*s == 0)
                    break;
            }
        }
        *dst = 0;
        void *mem = FUN_0008d690(0x14);
        DollyScript::CTokenString *t = 0;
        if (mem != 0)
            t = new (mem) DollyScript::CTokenString(out, a, b);
        char *cursor = *cur;
        const char *endp = s + (base - copy);
        if (cursor != 0) {
            while (*cur < endp) {
                *cur = FUN_003465c6(0, " \t\n\r");
                if (*cur == 0)
                    break;
            }
        }
        return (DollyScript::CToken *)(void *)t;
    }
    void *res = 0;
    if (c == '{') {
        void *mem = FUN_0008d690(0x10);
        if (mem != 0)
            res = new (mem) DollyScript::CTokenSectionStart(b);
    } else if (c == '}') {
        void *mem = FUN_0008d690(0x10);
        if (mem != 0)
            res = new (mem) DollyScript::CTokenSectionEnd(b);
    } else if (isdigit((int)c) == 0 && **cur != '-' && **cur != '+' && **cur != '.') {
        void *mem = FUN_0008d690(0x18);
        if (mem != 0)
            res = ((DollyScript::CTokenHashed *)mem)->FUN_000f9c20(*cur, a, b, 0);
    } else {
        float v = (float)FUN_003458c1(*cur);
        void *mem = FUN_0008d690(0x14);
        if (mem != 0)
            res = ((DollyScript::CTokenNumber *)mem)->FUN_000f9880(v, a, b);
    }
    *cur = FUN_003465c6(0, " \t\n\r");
    return (DollyScript::CToken *)res;
}
