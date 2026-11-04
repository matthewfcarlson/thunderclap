// STATUS: equivalent (tools/equiv.py level 3: 18083 inputs, branch coverage 40/41, incomplete)
// FUN_000fbc00 @ 0x000fbc00
// cl-flags: /GS
#include "compat/ptr.h"

extern "C" hulk_intptr FUN_000fbc00(unsigned short *buf, unsigned int count, const char *fmt, char *ap)
{
    struct Frame {
        int c;
        char *savedAp;
        char tmp[20];
    } fr;
    unsigned short *out = buf;
    if (fmt == 0) {
        *buf = 0;
        return 0;
    }
    fr.c = (signed char)*fmt;
    if (fr.c != 0) {
        unsigned int limit = count - 1;
        char *args = ap - 4;
        do {
            fmt++;
            if ((unsigned int)(out - buf) >= limit)
                break;
            bool store = true;
            if (fr.c == '%') {
                fr.c = (signed char)*fmt;
                fmt++;
                if ((unsigned int)(fr.c - 0x53) <= 0x22) {
                    if (fr.c == 'c') {
#if defined(HULK_PTR64)
                        *out = (unsigned short)__builtin_va_arg(ap, unsigned int);
#else
                        *out = *(unsigned short *)(args + 4);
                        args += 4;
#endif
                        out++;
                        store = false;
                    } else if (fr.c == 's') {
#if defined(HULK_PTR64)
                        const char *s = __builtin_va_arg(ap, const char *);
#else
                        const char *s = *(const char **)(args + 4);
                        args += 4;
#endif
                        char ch = *s;
                        while (ch != 0) {
                            *out = (short)(signed char)ch;
                            out++;
                            if ((unsigned int)(out - buf) >= limit)
                                break;
                            s++;
                            ch = *s;
                        }
                        store = false;
                    } else if (fr.c == 'S') {
#if defined(HULK_PTR64)
                        const unsigned short *ws = __builtin_va_arg(ap, const unsigned short *);
#else
                        const unsigned short *ws = *(const unsigned short **)(args + 4);
                        args += 4;
#endif
                        unsigned short wc = *ws;
                        while (wc != 0) {
                            *out = wc;
                            out++;
                            if ((unsigned int)(out - buf) >= limit)
                                break;
                            ws++;
                            wc = *ws;
                        }
                        store = false;
                    } else if (fr.c == 'u') {
#if defined(HULK_PTR64)
                        unsigned int v = __builtin_va_arg(ap, unsigned int);
#else
                        unsigned int v = *(unsigned int *)(args + 4);
                        args += 4;
#endif
                        fr.savedAp = args;
                        char *p = fr.tmp;
                        do {
                            *p = (char)(v % 10 + '0');
                            p++;
                            v /= 10;
                        } while (v != 0);
                        p--;
                        while (p >= fr.tmp) {
                            *out = (short)(signed char)*p;
                            out++;
                            if ((unsigned int)(out - buf) >= limit)
                                break;
                            p--;
                        }
                        args = fr.savedAp;
                        store = false;
                    }
                    if (!store && (unsigned int)(out - buf) >= limit)
                        store = true;
                }
            }
            if (store) {
                *out = (unsigned short)fr.c;
                out++;
            }
            fr.c = (signed char)*fmt;
        } while (fr.c != 0);
    }
    *out = 0;
    hulk_intptr n = out - buf;
    return n;
}
