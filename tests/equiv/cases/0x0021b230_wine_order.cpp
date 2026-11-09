// STATUS: equivalent (tools/equiv.py level 3: 1803 inputs, branch coverage 40/40)
// read_numeral: lex the digits of a number (fraction, exponent) into the token buffer and convert it.
#include "decls/data/lua.h"

extern "C" int __cdecl isdigit(int c);

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
extern "C" int __cdecl FUN_00215ff0(const char* s, float* result);
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);

// save_and_next out of line: the lexer state arrives in edi
// equiv-conv: FUN_0021b1c0 edi
extern "C" void FUN_0021b1c0(LuaVMLexState* ls);

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
