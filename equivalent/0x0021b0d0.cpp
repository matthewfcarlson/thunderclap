// STATUS: equivalent (tools/equiv.py level 3: 2990 inputs, branch coverage 12/12)
// FUN_0021b0d0 @ 0x0021b0d0
// Lua 5.0 llex.c inclinenumber(LS): skip a newline sequence ("\n", "\r", "\n\r" or "\r\n") and count the line.
struct Zio_21b0d0 {
    unsigned int n;
    unsigned char* p;
};

struct LexState_21b0d0 {
    int current;
    int linenumber;
    int lastline;
    int token;
    char pad[0x24 - 0x10];
    Zio_21b0d0* z;
};

int __cdecl FUN_0021a550(Zio_21b0d0* z);                                    // luaZ_fill
void __cdecl FUN_0021afd0(LexState_21b0d0* ls, const char* msg, int token); // luaX_lexerror

// equiv-conv: FUN_0021b0d0 esi
void FUN_0021b0d0(LexState_21b0d0* ls)
{
    int old = ls->current;

    ls->current = (ls->z->n-- > 0) ? *ls->z->p++ : FUN_0021a550(ls->z);
    if ((ls->current == '\n' || ls->current == '\r') && ls->current != old) {
        ls->current = (ls->z->n-- > 0) ? *ls->z->p++ : FUN_0021a550(ls->z);
    }
    if (++ls->linenumber >= 0x7ffffffd) {
        FUN_0021afd0(ls, "chunk has too many lines", ls->token);
    }
}
