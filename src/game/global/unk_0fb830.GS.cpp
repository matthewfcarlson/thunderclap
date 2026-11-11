// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000fb830..0x000fc460 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f5a66c40 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5a66c40 {} using namespace fn_f5a66c40;
#include "game/global.h"

namespace fn_f5a66c40 {

// 0x000fbc00 FUN_000fbc00 (446 B): equivalent/0x000fbc00.cpp
// sym: _FUN_000fbc00 @4657e9dcd4b3 @w1c7cdae71929
// STATUS: equivalent (tools/equiv.py level 3: 18083 inputs, branch coverage 40/41, incomplete)
// FUN_000fbc00 @ 0x000fbc00
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


// 0x000fbe00 FUN_000fbe00 (446 B): equivalent/0x000fbe00.cpp
// sym: ?FUN_000fbe00@fn_f5a66c40@@YAHPAGIPBGPAD@Z @3dc087c0e9cb @wc2735a26afcb
// STATUS: equivalent (tools/equiv.py level 3: 16642 inputs, branch coverage 40/41, incomplete)
// FUN_000fbe00 @ 0x000fbe00
hulk_intptr FUN_000fbe00(unsigned short *buf, unsigned int count, const unsigned short *fmt, char *ap)
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
    fr.c = *fmt;
    if (fr.c != 0) {
        unsigned int limit = count - 1;
        char *args = ap - 4;
        do {
            fmt++;
            if ((unsigned int)(out - buf) >= limit)
                break;
            bool store = true;
            if (fr.c == '%') {
                fr.c = *fmt;
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
            fr.c = *fmt;
        } while (fr.c != 0);
    }
    *out = 0;
    hulk_intptr n = out - buf;
    return n;
}

} // namespace fn_f5a66c40
