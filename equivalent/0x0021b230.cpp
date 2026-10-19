// STATUS: equivalent (tools/equiv.py level 3: 118 inputs, branch coverage 40/40)
// FUN_0021b230 @ 0x0021b230
extern "C" int __cdecl isdigit(int c);

struct lua_State;

struct Zio {
    unsigned int n;             // bytes left
    const unsigned char* p;     // next byte
};

struct Mbuffer {
    char* buffer;               // 0x00
    unsigned int n;             // 0x04
    unsigned int buffsize;      // 0x08
};

struct LexState {
    int current;                // 0x00
    char pad04[0x1c];
    lua_State* L;               // 0x20
    Zio* z;                     // 0x24
    Mbuffer* buff;              // 0x28
};

union SemInfo {
    double r;
};

char* FUN_0021add0(lua_State* L, void* block, unsigned int oldsize, unsigned int newsize);
int FUN_0021a550(Zio* z);
int FUN_00215ff0(const char* s, double* result);
void FUN_0021afd0(LexState* LS, const char* msg, int token);

// save_and_next out of line: the lexer state arrives in edi
// equiv-conv: FUN_0021b1c0 edi
void FUN_0021b1c0(LexState* LS);

// grow the token buffer when full, then append one character
#define SAVE(LS, c)                                                                          \
    do {                                                                                     \
        Mbuffer* b = (LS)->buff;                                                             \
        if (b->n + 1 > b->buffsize) {                                                        \
            b->buffer = FUN_0021add0((LS)->L, b->buffer, b->buffsize, b->buffsize * 2 + 0x20); \
            b->buffsize = b->buffsize * 2 + 0x20;                                            \
        }                                                                                    \
        b->buffer[b->n++] = (char)(c);                                                       \
    } while (0)

#define NEXT(LS) \
    ((LS)->current = ((LS)->z->n-- > 0) ? (int)(unsigned char)(*(LS)->z->p++) : FUN_0021a550((LS)->z))

// Lex the digits of a number into the token buffer and convert it.
// equiv-conv: FUN_0021b230 eax stack
void FUN_0021b230(LexState* LS, SemInfo* seminfo)
{
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
