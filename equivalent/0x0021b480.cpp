// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 10/10)
// FUN_0021b480 @ 0x0021b480
struct ZIO_21b480 {
    unsigned int n;
    const unsigned char *p;
};

struct Mbuffer_21b480 {
    char *buffer;
    unsigned int n;
    unsigned int buffsize;
};

struct LexState_21b480 {
    int current;            // 0x00
    char pad04[0x1c];
    void *L;                // 0x20
    ZIO_21b480 *z;                 // 0x24
    Mbuffer_21b480 *buff;          // 0x28
};

int __cdecl FUN_0021a550(ZIO_21b480 *z);
char *__cdecl FUN_0021add0(void *L, char *p, unsigned int oldsize, unsigned int newsize);

// save_and_next with the lexer state in edi
// equiv-conv: FUN_0021b1c0 edi
void FUN_0021b1c0(LexState_21b480 *ls);

// skip_sep: counts the run of '*' after the opening character; the lexer state is passed in eax
// equiv-conv: FUN_0021b480 eax
int FUN_0021b480(LexState_21b480 *ls)
{
    int count = 0;
    int s = ls->current;
    FUN_0021b1c0(ls);
    while (ls->current == '*') {
        Mbuffer_21b480 *b = ls->buff;
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
