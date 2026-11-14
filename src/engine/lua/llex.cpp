// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0021aeb0..0x0021c190 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f9ca7db9 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9ca7db9 {} using namespace fn_f9ca7db9;
#include "engine/lua.h"
// (ren2) isalnum's own name (CRT, C linkage)
extern "C" int __cdecl isalnum(int);

// ---- declarations shared by the functions below
namespace fn_f9ca7db9 {
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" int __cdecl iscntrl(int);
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" const char* __cdecl FUN_0021af00(LuaVMLexState* ls, int token);
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
extern "C" LuaVMTObject* __cdecl FUN_0021a500(LuaVMState* L, LuaVMTable* t, LuaVMString* key);
extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
extern "C" void FUN_0021b1c0(LuaVMLexState* ls);
extern "C" void FUN_0021b0d0(LuaVMLexState* ls);
extern "C" int FUN_0021b480(LuaVMLexState* ls);


// 0x0021aeb0 FUN_0021aeb0 (73 B): matches/0x0021aeb0.cpp
// sym: _FUN_0021aeb0
// luaX_init: create the reserved words' strings, fix them and number them (TString.reserved).
// data: token2string = DAT_00426bf0 (const char* [21])
extern "C" void __cdecl FUN_0021aeb0(LuaVMState* L) {
    int i = 0;
    do {
        const char* p = (const char*)DAT_00426bf0[i];
        const char* e = p + 1;
        char c;
        do {
            c = *p;
            p++;
        } while (c != 0);
        LuaVMString* ts = FUN_00219430(L, (const char*)DAT_00426bf0[i], (unsigned int)(p - e));
        ts->marked |= 0x20;
        ts->reserved = (unsigned char)(i + 1);
        i++;
    } while (i < 21);
}


// 0x0021af00 FUN_0021af00 (82 B): matches/0x0021af00.cpp
// sym: _FUN_0021af00
// luaX_token2str: a single-character token as "%c" (or "char(%d)" when it is a control character), a reserved
// word or other token by the token2string table.
// data: token2string = DAT_00426bf0 (const char* [], indexed by token - 257)
extern "C" const char* __cdecl FUN_0021af00(LuaVMLexState* ls, int token) {
    const char* r;
    if (token < 0x101) {
        if (iscntrl(token))
            r = FUN_00216320(ls->L, "char(%d)", token);
        else
            r = FUN_00216320(ls->L, "%c", token);
    } else {
        r = (const char*)DAT_00426bf0[token - 0x101];
    }
    return r;
}


// 0x0021af60 FUN_0021af60 (99 B): equivalent/0x0021af60.cpp
// sym: _FUN_0021af60 @f817c98ca699 @wce84fc7f84ae
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 8/8)
// txtToken: a name, string or number token as the buffer's text (NUL-terminated), any other by luaX_token2str.
// equiv-conv: FUN_0021af60 eax edi
extern "C" const char* FUN_0021af60(int token, LuaVMLexState* ls) {
    if (token != 0x116 && (token <= 0x11c || token > 0x11e))
        return FUN_0021af00(ls, token);
    LuaVMBuffer* b = ls->buff;
    if (b->n + 1 > b->buffsize) {
        unsigned int size = b->buffsize;
        b->buffer = (char*)FUN_0021add0(ls->L, b->buffer, size, size * 2 + 0x20);
        b->buffsize = b->buffsize * 2 + 0x20;
    }
    b->buffer[b->n] = 0;
    ++b->n;
    return ls->buff->buffer;
}


// 0x0021b060 FUN_0021b060 (23 B): matches/0x0021b060.cpp
// sym: _FUN_0021b060
// luaX_syntaxerror: a lexer error near the current token.
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg) {
    FUN_0021afd0(ls, msg, ls->t.token);
}


// 0x0021b080 FUN_0021b080 (70 B): matches/0x0021b080.cpp
// sym: _FUN_0021b080
// luaX_newstring: intern a string and anchor it in the function's constant table (set to true when new).
extern "C" LuaVMString* __cdecl FUN_0021b080(LuaVMLexState* ls, const char* str, unsigned int l) {
    LuaVMState* L = ls->L;
    LuaVMString* ts = FUN_00219430(L, str, l);
    LuaVMTObject* o = FUN_0021a500(L, ls->fs->h, ts);
    if (o->tt == LUAVM_TNIL) {
        o->value.b = 1;
        o->tt = LUAVM_TBOOLEAN;
    }
    return ts;
}


// 0x0021b0d0 FUN_0021b0d0 (139 B): equivalent/0x0021b0d0.cpp
// sym: _FUN_0021b0d0 @fcb28a928da9 @w18fb5ddbe3fe
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 12/12)
// inclinenumber: skip a newline sequence ("\n", "\r", "\n\r" or "\r\n") and count the line.
 // luaX_lexerror
// equiv-conv: FUN_0021b0d0 esi
extern "C" void FUN_0021b0d0(LuaVMLexState* ls) {
    int old = ls->current;

    ls->current = (ls->z->n-- > 0) ? (unsigned char)*ls->z->p++ : FUN_0021a550(ls->z);
    if ((ls->current == '\n' || ls->current == '\r') && ls->current != old) {
        ls->current = (ls->z->n-- > 0) ? (unsigned char)*ls->z->p++ : FUN_0021a550(ls->z);
    }
    if (++ls->linenumber >= 0x7ffffffd) {
        FUN_0021afd0(ls, "chunk has too many lines", ls->t.token);
    }
}


// 0x0021b160 FUN_0021b160 (92 B): matches/0x0021b160.cpp
// sym: _FUN_0021b160
// luaX_setinput: start the lexer on a stream (line 1, no lookahead, no function) and read the first character.
extern "C" void __cdecl FUN_0021b160(LuaVMState* L, LuaVMLexState* ls, LuaVMZio* z, LuaVMString* source) {
    ls->L = L;
    ls->z = z;
    ls->linenumber = 1;
    ls->lastline = 1;
    ls->lookahead.token = 0x11f;  // TK_EOS
    ls->fs = 0;
    ls->source = source;
    unsigned int n = z->n;
    z->n = n - 1;
    LuaVMZio* q = ls->z;
    if (n > 0) {
        const char* t = q->p;
        int v = (unsigned char)*t++;
        q->p = t;
        ls->current = v;
        return;
    }
    ls->current = FUN_0021a550(q);
}


// 0x0021b1c0 FUN_0021b1c0 (104 B): equivalent/0x0021b1c0.cpp
// sym: _FUN_0021b1c0 @d4c627fa9e02 @w0af7d2f7379d
// STATUS: equivalent (tools/equiv.py level 3: 2948 inputs, branch coverage 4/4)
// save_and_next: append the current character to the buffer, then read the next one.
// equiv-conv: FUN_0021b1c0 edi
extern "C" void FUN_0021b1c0(LuaVMLexState* ls) {
    LuaVMBuffer* b = ls->buff;
    if (b->n + 1 > b->buffsize) {
        b->buffer = (char*)FUN_0021add0(ls->L, b->buffer, b->buffsize, b->buffsize * 2 + 0x20);
        b->buffsize = b->buffsize * 2 + 0x20;
    }
    b->buffer[b->n] = (char)ls->current;
    b->n++;
    if (ls->z->n-- > 0)
        ls->current = (unsigned char)*ls->z->p++;
    else
        ls->current = FUN_0021a550(ls->z);
}

} // namespace fn_f9ca7db9

// 0x0021b230 FUN_0021b230 (590 B): equivalent/0x0021b230.cpp [wrapped: macros]
// sym: _FUN_0021b230 @008f0495b548 @wd4b873dc0649
namespace fn_0021b230 {
// STATUS: equivalent (tools/equiv.py level 3: 1803 inputs, branch coverage 40/40)
// read_numeral: lex the digits of a number (fraction, exponent) into the token buffer and convert it.


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl isdigit(int c);
#endif


extern "C++" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C++" int __cdecl FUN_0021a550(LuaVMZio* z);
extern "C" int __cdecl FUN_00215ff0(const char* s, float* result);
extern "C++" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);

// save_and_next out of line: the lexer state arrives in edi
// equiv-conv: FUN_0021b1c0 edi
extern "C++" void FUN_0021b1c0(LuaVMLexState* ls);

// grow the token buffer when full, then append one character
#define SAVE(LS, c)                                                                                          \
    do {                                                                                                     \
        LuaVMBuffer* b = (LS)->buff;                                                                         \
        if (b->n + 1 > b->buffsize) {                                                                        \
            b->buffer = (char*)FUN_0021add0((LS)->L, b->buffer, b->buffsize, b->buffsize * 2 + 0x20);        \
            b->buffsize = b->buffsize * 2 + 0x20;                                                            \
        }                                                                                                    \
        b->buffer[b->n] = (char)(c);                                                                         \
        b->n++;                                                                                              \
    } while (0)

// The character is stored before the count goes up and read before the pointer moves on, in the original's
// order: clang orders `b->buffer[b->n++] = c` and `*z->p++` the other way round, which a buffer overlapping
// its own header (a fuzzed input, undefined behaviour) tells apart (tools/equiv.py --wine).
#define NEXT(LS)                                                                                             \
    do {                                                                                                     \
        if ((LS)->z->n-- > 0) {                                                                              \
            int ch_ = (unsigned char)*(LS)->z->p;                                                            \
            (LS)->z->p++;                                                                                    \
            (LS)->current = ch_;                                                                             \
        } else {                                                                                             \
            (LS)->current = FUN_0021a550((LS)->z);                                                           \
        }                                                                                                    \
    } while (0)

// equiv-conv: FUN_0021b230 eax stack
extern "C" void FUN_0021b230(LuaVMLexState* LS, LuaVMSemInfo* seminfo) {
    while (isdigit(LS->current)) {
        SAVE(LS, LS->current);
        NEXT(LS);
    }
    if (LS->current == '.') {
        FUN_0021b1c0(LS);
        if (LS->current == '.') {
            FUN_0021b1c0(LS);
            FUN_0021afd0(LS, "ambiguous syntax (decimal point x string concatenation)", 0x11d);
        }
    }
    while (isdigit(LS->current)) {
        SAVE(LS, LS->current);
        NEXT(LS);
    }
    if (LS->current == 'e' || LS->current == 'E') {
        FUN_0021b1c0(LS);
        if (LS->current == '+' || LS->current == '-')
            FUN_0021b1c0(LS);
        while (isdigit(LS->current)) {
            SAVE(LS, LS->current);
            NEXT(LS);
        }
    }
    SAVE(LS, 0);
    if (!FUN_00215ff0(LS->buff->buffer, &seminfo->r))
        FUN_0021afd0(LS, "malformed number", 0x11d);
}
} // namespace fn_0021b230
#undef NEXT
#undef SAVE

namespace fn_f9ca7db9 {

// 0x0021b480 FUN_0021b480 (149 B): equivalent/0x0021b480.cpp
// sym: _FUN_0021b480 @6685ade32ca8 @wc1f07883eb37
// STATUS: equivalent (tools/equiv.py level 3: 3061 inputs, branch coverage 10/10)
// skip_sep: count the run of '*' after a long bracket's opening character (-count - 1 when the closing one differs).
// equiv-conv: FUN_0021b1c0 edi
// equiv-conv: FUN_0021b480 eax
extern "C" int FUN_0021b480(LuaVMLexState* ls) {
    int count = 0;
    int s = ls->current;
    FUN_0021b1c0(ls);
    while (ls->current == '*') {
        LuaVMBuffer* b = ls->buff;
        if (b->n + 1 > b->buffsize) {
            b->buffer = (char*)FUN_0021add0(ls->L, b->buffer, b->buffsize, b->buffsize * 2 + 0x20);
            b->buffsize = b->buffsize * 2 + 0x20;
        }
        b->buffer[b->n] = (char)ls->current;
        b->n++;
        if (ls->z->n-- > 0)
            ls->current = (unsigned char)*ls->z->p++;
        else
            ls->current = FUN_0021a550(ls->z);
        count++;
    }
    return ls->current == s ? count : -count - 1;
}


// 0x0021b520 FUN_0021b520 (393 B): equivalent/0x0021b520.cpp
// sym: _FUN_0021b520 @dfd61312ec5d @w7fd6076ca4d0
// STATUS: equivalent (tools/equiv.py level 3: 115 inputs, branch coverage 30/31, incomplete)
// read_long_string: a long string or comment up to the matching closing bracket (nested ones counted); the string
// (seminfo non-null) is interned and anchored in the function's constant table.
// equiv-conv: FUN_0021b1c0 edi
// equiv-conv: FUN_0021b0d0 esi
// equiv-conv: FUN_0021b480 eax
// equiv-conv: FUN_0021b520 ecx eax stack
extern "C" void FUN_0021b520(LuaVMLexState* ls, int sep, LuaVMSemInfo* seminfo) {
    int cont = 0;
    FUN_0021b1c0(ls);
    if (ls->current == 10 || ls->current == 13)
        FUN_0021b0d0(ls);
    for (;;) {
        switch (ls->current) {
        case -1:
            FUN_0021afd0(ls, seminfo ? "unfinished long string" : "unfinished long comment", 0x11f);
            break;
        case '[':
            if (FUN_0021b480(ls) == sep) {
                FUN_0021b1c0(ls);
                cont++;
            }
            break;
        case ']':
            if (FUN_0021b480(ls) == sep) {
                FUN_0021b1c0(ls);
                if (cont-- == 0) {
                    if (seminfo) {
                        LuaVMBuffer* b = ls->buff;
                        LuaVMState* L = ls->L;
                        LuaVMString* ts = FUN_00219430(L, b->buffer + sep + 2, b->n + (0x7ffffffe - sep) * 2);
                        LuaVMTObject* o = FUN_0021a500(L, ls->fs->h, ts);
                        if (o->tt == LUAVM_TNIL) {
                            o->value.b = 1;
                            o->tt = LUAVM_TBOOLEAN;
                        }
                        seminfo->ts = ts;
                    }
                    return;
                }
            }
            break;
        case '\n':
        case '\r': {
            LuaVMBuffer* b = ls->buff;
            if (b->n + 1 > b->buffsize) {
                b->buffer = (char*)FUN_0021add0(ls->L, b->buffer, b->buffsize, b->buffsize * 2 + 0x20);
                b->buffsize = b->buffsize * 2 + 0x20;
            }
            b->buffer[b->n] = '\n';
            b->n++;
            FUN_0021b0d0(ls);
            if (!seminfo)
                ls->buff->n = 0;
            break;
        }
        default:
            if (seminfo) {
                FUN_0021b1c0(ls);
            } else {
                LuaVMZio* z = ls->z;
                unsigned int n = z->n;
                z->n = n - 1;
                if (n != 0)
                    ls->current = (unsigned char)*ls->z->p++;
                else
                    ls->current = FUN_0021a550(ls->z);
            }
            break;
        }
    }
}

} // namespace fn_f9ca7db9

// 0x0021b720 FUN_0021b720 (898 B): equivalent/0x0021b720.cpp [wrapped: macros]
// sym: _FUN_0021b720 @57755bc35946 @wcdfb1651a96c
namespace fn_0021b720 {
// STATUS: equivalent (tools/equiv.py level 3: 1255 inputs, branch coverage 45/48, incomplete)
// read_string: a quoted string up to the delimiter, with escapes; interned and anchored in the constant table.
// checked with equiv.py --inputs 8000 --time-budget 1500 (the default budget stops early)

extern unsigned int DAT_004d9968;

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void __fastcall __security_check_cookie(unsigned int);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int isdigit(int c);
#endif


extern "C" {
extern "C++" { int __cdecl FUN_0021a550(LuaVMZio* z); }
extern "C++" { void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize); }
extern "C++" { void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token); }
void __cdecl FUN_00216340(char* out, const char* source, int bufflen);
extern "C++" { const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...); }
void __cdecl FUN_002152b0(LuaVMState* L, int errcode);
extern "C++" { LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l); }
extern "C++" { LuaVMTObject* __cdecl FUN_0021a500(LuaVMState* L, LuaVMTable* t, LuaVMString* key); }
}

// save_and_next with the lexer state in edi
// equiv-conv: FUN_0021b1c0 edi
extern "C++" void FUN_0021b1c0(LuaVMLexState* ls);
// inclinenumber with the lexer state in esi
// equiv-conv: FUN_0021b0d0 esi
extern "C++" void FUN_0021b0d0(LuaVMLexState* ls);

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
} // namespace fn_0021b720
#undef NEXT
#undef SAVE


// 0x0021bbc0 FUN_0021bbc0 (1310 B): equivalent/0x0021bbc0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: _FUN_0021bbc0 @72472be06074 @wee4ecac95fa9
namespace fn_0021bbc0 {
// STATUS: equivalent (tools/equiv.py level 3: 2771 inputs, branch coverage 68/89, incomplete)
// llex: the next token (its semantic value in seminfo).
// equiv-conv: FUN_0021b0d0 esi
// equiv-conv: FUN_0021b480 eax
// equiv-conv: FUN_0021b520 ecx eax stack
// equiv-conv: FUN_0021b230 eax stack
// equiv-conv: FUN_0021b1c0 edi
// equiv-conv: FUN_0021b720 ecx stack stack


extern "C++" int __cdecl FUN_0021a550(LuaVMZio* z);
extern "C++" void FUN_0021b0d0(LuaVMLexState* ls);
extern "C++" int FUN_0021b480(LuaVMLexState* ls);
extern "C++" void FUN_0021b520(LuaVMLexState* ls, int sep, LuaVMSemInfo* seminfo);
extern "C++" void FUN_0021b230(LuaVMLexState* ls, LuaVMSemInfo* seminfo);
extern "C++" void FUN_0021b1c0(LuaVMLexState* ls);
extern "C++" void FUN_0021b720(LuaVMLexState* ls, int del, LuaVMSemInfo* seminfo);
extern "C++" LuaVMString* __cdecl FUN_0021b080(LuaVMLexState* ls, const char* str, unsigned int l);
extern "C++" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int isspace(int c);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int isdigit(int c);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int isalpha(int c);
#endif


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
} // namespace fn_0021bbc0

