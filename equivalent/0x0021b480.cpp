// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 10/10)
// FUN_0021b480 @ 0x0021b480
struct ZIO {
    unsigned int n;
    const unsigned char *p;
};

struct Mbuffer {
    char *buffer;
    unsigned int n;
    unsigned int buffsize;
};

struct LexState {
    int current;            // 0x00
    char pad04[0x1c];
    void *L;                // 0x20
    ZIO *z;                 // 0x24
    Mbuffer *buff;          // 0x28
};

int __cdecl FUN_0021a550(ZIO *z);
char *__cdecl FUN_0021add0(void *L, char *p, unsigned int oldsize, unsigned int newsize);

// save_and_next with the lexer state in edi
// equiv-conv: FUN_0021b1c0 edi
void FUN_0021b1c0(LexState *ls);

// skip_sep: counts the run of '*' after the opening character; the lexer state is passed in eax
// equiv-conv: FUN_0021b480 eax
int FUN_0021b480(LexState *ls)
{
    int count = 0;
    int s = ls->current;
    FUN_0021b1c0(ls);
    while (ls->current == '*') {
        Mbuffer *b = ls->buff;
        if (b->n + 1 > b->buffsize) {
            b->buffer = FUN_0021add0(ls->L, b->buffer, b->buffsize, b->buffsize * 2 + 0x20);
            b->buffsize = b->buffsize * 2 + 0x20;
        }
        b->buffer[b->n] = (char)ls->current;
        b->n++;
        if (ls->z->n-- > 0)
            ls->current = *ls->z->p++;
        else
            ls->current = FUN_0021a550(ls->z);
        count++;
    }
    return ls->current == s ? count : -count - 1;
}
