// STATUS: equivalent (tools/equiv.py level 3: 1255 inputs, branch coverage 45/48, incomplete)
// read_string: a quoted string up to the delimiter, with escapes; interned and anchored in the constant table.
// checked with equiv.py --inputs 8000 --time-budget 1500 (the default budget stops early)
#include "decls/data/lua.h"

extern unsigned int DAT_004d9968;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int isdigit(int c);

extern "C" {
int __cdecl FUN_0021a550(LuaVMZio* z);
void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
void __cdecl FUN_00216340(char* out, const char* source, int bufflen);
const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
void __cdecl FUN_002152b0(LuaVMState* L, int errcode);
LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
LuaVMTObject* __cdecl FUN_0021a500(LuaVMState* L, LuaVMTable* t, LuaVMString* key);
}

// save_and_next with the lexer state in edi
// equiv-conv: FUN_0021b1c0 edi
extern "C" void FUN_0021b1c0(LuaVMLexState* ls);
// inclinenumber with the lexer state in esi
// equiv-conv: FUN_0021b0d0 esi
extern "C" void FUN_0021b0d0(LuaVMLexState* ls);

#define SAVE(c)                                                                                              \
    do {                                                                                                     \
        LuaVMBuffer* b = ls->buff;                                                                           \
        if (b->n + 1 > b->buffsize) {                                                                        \
            unsigned int old = b->buffsize;                                                                  \
            b->buffer = (char*)FUN_0021add0(ls->L, b->buffer, old, old * 2 + 0x20);                          \
            b->buffsize = b->buffsize * 2 + 0x20;                                                            \
        }                                                                                                    \
        b->buffer[b->n] = (char)(c);                                                                         \
        b->n++;                                                                                              \
    } while (0)

#define NEXT()                                                                                               \
    do {                                                                                                     \
        if (ls->z->n-- > 0) {                                                                                \
            int ch_ = (unsigned char)*ls->z->p; /* read before the pointer moves on, as the original */      \
            ls->z->p++;                                                                                      \
            ls->current = ch_;                                                                               \
        } else {                                                                                             \
            ls->current = FUN_0021a550(ls->z);                                                               \
        }                                                                                                    \
    } while (0)

// Lexer: read a quoted string up to the delimiter del, handling escapes; the lexer state arrives in ecx.
// equiv-conv: FUN_0021b720 ecx stack stack
extern "C" void FUN_0021b720(LuaVMLexState* ls, int del, LuaVMSemInfo* seminfo) {
    unsigned int cookie = DAT_004d9968;
    char buf[80];
    FUN_0021b1c0(ls);
    while (ls->current != del) {
        switch (ls->current) {
        case -1:
            FUN_0021afd0(ls, "unfinished string", 0x11f);
            break;
        case '\n':
        case '\r': {
            FUN_00216340(buf, LUAVM_GETSTR(ls->source), 80);
            const char* msg = FUN_00216320(ls->L, "%s:%d: %s", buf, ls->linenumber, "unfinished string");
            SAVE(0);
            FUN_00216320(ls->L, "%s near `%s'", msg, ls->buff->buffer);
            FUN_002152b0(ls->L, 3);
            break;
        }
        case '\\': {
            NEXT();
            int c;
            switch (ls->current) {
            case 'a':
                c = 7;
                break;
            case 'b':
                c = 8;
                break;
            case 'f':
                c = 12;
                break;
            case 'n':
                c = 10;
                break;
            case 'r':
                c = 13;
                break;
            case 't':
                c = 9;
                break;
            case 'v':
                c = 11;
                break;
            case '\n':
            case '\r':
                SAVE('\n');
                FUN_0021b0d0(ls);
                continue;
            case -1:
                continue;
            default:
                if (!isdigit(ls->current)) {
                    FUN_0021b1c0(ls);
                } else {
                    int i = 0;
                    c = 0;
                    do {
                        c = 10 * c + (ls->current - '0');
                        NEXT();
                    } while (++i < 3 && isdigit(ls->current));
                    if (c > 255)
                        FUN_0021afd0(ls, "escape sequence too large", 0x11e);
                    SAVE(c);
                }
                continue;
            }
            SAVE(c);
            NEXT();
            continue;
        }
        default:
            SAVE(ls->current);
            NEXT();
            break;
        }
    }
    FUN_0021b1c0(ls);
    LuaVMState* L = ls->L;
    LuaVMString* ts = FUN_00219430(L, ls->buff->buffer + 1, ls->buff->n - 2);
    LuaVMTObject* o = FUN_0021a500(L, ls->fs->h, ts);
    if (o->tt == LUAVM_TNIL) {
        o->value.b = 1;
        o->tt = LUAVM_TBOOLEAN;
    }
    seminfo->ts = ts;
    __security_check_cookie(cookie);
}
