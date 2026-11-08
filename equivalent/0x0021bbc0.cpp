// STATUS: equivalent (tools/equiv.py level 3: 2771 inputs, branch coverage 68/89, incomplete)
// llex: the next token (its semantic value in seminfo).
// equiv-conv: FUN_0021b0d0 esi
// equiv-conv: FUN_0021b480 eax
// equiv-conv: FUN_0021b520 ecx eax stack
// equiv-conv: FUN_0021b230 eax stack
// equiv-conv: FUN_0021b1c0 edi
// equiv-conv: FUN_0021b720 ecx stack stack

#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
extern "C" void FUN_0021b0d0(LuaVMLexState* ls);
extern "C" int FUN_0021b480(LuaVMLexState* ls);
extern "C" void FUN_0021b520(LuaVMLexState* ls, int sep, LuaVMSemInfo* seminfo);
extern "C" void FUN_0021b230(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C" void FUN_0021b1c0(LuaVMLexState* ls);
extern "C" void FUN_0021b720(LuaVMLexState* ls, int del, LuaVMSemInfo* seminfo);
extern "C" LuaVMString* __cdecl FUN_0021b080(LuaVMLexState* ls, const char* str, unsigned int l);
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
extern "C" int isspace(int c);
extern "C" int isdigit(int c);
extern "C" int isalpha(int c);
extern "C" int isalnum(int c);

static int Zgetc(LuaVMLexState* ls) {
    unsigned int n = ls->z->n;
    ls->z->n = n - 1;
    if (n > 0) {
        LuaVMZio* z = ls->z;
        const char* p = z->p;
        int c = (unsigned char)*p;
        z->p = p + 1;
        return c;
    }
    return FUN_0021a550(ls->z);
}

extern "C" int __cdecl FUN_0021bbc0(LuaVMLexState* ls, LuaVMSemInfo* seminfo) {
    ls->buff->n = 0;
    for (;;) {
        int c = ls->current;
        switch (c) {
        case '\n':
        case '\r':
            FUN_0021b0d0(ls);
            continue;
        case '-': {
            ls->current = Zgetc(ls);
            if (ls->current != '-')
                return '-';
            ls->current = Zgetc(ls);
            if (ls->current == '[') {
                int sep = FUN_0021b480(ls);
                ls->buff->n = 0;
                if (sep >= 0) {
                    FUN_0021b520(ls, sep, (LuaVMSemInfo*)0);
                    ls->buff->n = 0;
                    continue;
                }
            }
            if (ls->current == '\n')
                continue;
            for (;;) {
                if (ls->current == '\r')
                    break;
                if (ls->current == -1)
                    break;
                ls->current = Zgetc(ls);
                if (ls->current == '\n')
                    break;
            }
            continue;
        }
        case '[': {
            int sep = FUN_0021b480(ls);
            if (sep >= 0) {
                FUN_0021b520(ls, sep, seminfo);
                return 0x11e;
            }
            if (sep == -1)
                return '[';
            FUN_0021afd0(ls, "invalid long string delimiter", 0x11e);
            ls->current = Zgetc(ls);
            if (ls->current != '=')
                return '=';
            ls->current = Zgetc(ls);
            return 0x119;
        }
        case '=':
            ls->current = Zgetc(ls);
            if (ls->current != '=')
                return '=';
            ls->current = Zgetc(ls);
            return 0x119;
        case '<':
            ls->current = Zgetc(ls);
            if (ls->current != '=')
                return '<';
            ls->current = Zgetc(ls);
            return 0x11b;
        case '>':
            ls->current = Zgetc(ls);
            if (ls->current != '=')
                return '>';
            ls->current = Zgetc(ls);
            return 0x11a;
        case '~':
            ls->current = Zgetc(ls);
            if (ls->current != '=')
                return '~';
            ls->current = Zgetc(ls);
            return 0x11c;
        case '"':
        case '\'':
            FUN_0021b720(ls, ls->current, seminfo);
            return 0x11e;
        case '.':
            FUN_0021b1c0(ls);
            if (ls->current == '.') {
                ls->current = Zgetc(ls);
                if (ls->current != '.')
                    return 0x117;
                ls->current = Zgetc(ls);
                return 0x118;
            }
            if (!isdigit(ls->current))
                return '.';
            FUN_0021b230(ls, seminfo);
            return 0x11d;
        case -1:
            return 0x11f;
        default:
            if (isspace(c)) {
                ls->current = Zgetc(ls);
                continue;
            }
            if (isdigit(ls->current)) {
                FUN_0021b230(ls, seminfo);
                return 0x11d;
            }
            if (!isalpha(ls->current)) {
                int ch = ls->current;
                if (ch != '_') {
                    ls->current = Zgetc(ls);
                    return ch;
                }
            }
            do {
                FUN_0021b1c0(ls);
            } while (isalnum(ls->current) || ls->current == '_');
            LuaVMString* ts = FUN_0021b080(ls, ls->buff->buffer, ls->buff->n);
            unsigned char r = ts->reserved;
            if (r > 0)
                return r + 0x100;
            seminfo->ts = ts;
            return 0x116;
        }
    }
}
