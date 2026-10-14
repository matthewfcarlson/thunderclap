// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 28/31, incomplete)
// FUN_0021b520 @ 0x0021b520
struct Zio_21b520 {
    unsigned int n;
    unsigned char* p;
};
struct Mbuffer_21b520 {
    char* buffer;
    unsigned int n;
    unsigned int size;
};
struct Table;
struct FuncState_21b520 {
    char pad0[4];
    Table* h;
};
struct TString;
struct TValue_21b520 {
    int tt;
    int v;
};
struct SemInfo_21b520 {
    TString* ts;
};
struct LexState_21b520 {
    int current;
    int linenumber;
    char pad8[4];
    int lastline;
    char pad10[0xc];
    FuncState_21b520* fs;
    void* L;
    Zio_21b520* z;
    Mbuffer_21b520* buff;
};

// equiv-conv: FUN_0021b1c0 edi
void FUN_0021b1c0(LexState_21b520* ls);
// equiv-conv: FUN_0021b0d0 esi
void FUN_0021b0d0(LexState_21b520* ls);
// equiv-conv: FUN_0021b480 eax
int FUN_0021b480(LexState_21b520* ls);
void FUN_0021afd0(LexState_21b520* ls, const char* msg, int token);
int FUN_0021a550(Zio_21b520* z);
char* FUN_0021add0(void* L, char* block, unsigned int oldsize, unsigned int newsize);
TString* FUN_00219430(void* L, const char* str, unsigned int len);
TValue_21b520* FUN_0021a500(void* L, Table* t, TString* key);

// equiv-conv: FUN_0021b520 ecx eax stack
void FUN_0021b520(LexState_21b520* ls, int sep, SemInfo_21b520* seminfo)
{
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
                        Mbuffer_21b520* b = ls->buff;
                        void* L = ls->L;
                        TString* ts = FUN_00219430(L, b->buffer + sep + 2, b->n + (0x7ffffffe - sep) * 2);
                        TValue_21b520* o = FUN_0021a500(L, ls->fs->h, ts);
                        if (o->tt == 0) {
                            o->v = 1;
                            o->tt = 1;
                        }
                        seminfo->ts = ts;
                    }
                    return;
                }
            }
            break;
        case '\n':
        case '\r': {
            Mbuffer_21b520* b = ls->buff;
            if (b->n + 1 > b->size) {
                b->buffer = FUN_0021add0(ls->L, b->buffer, b->size, b->size * 2 + 0x20);
                b->size = b->size * 2 + 0x20;
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
                Zio_21b520* z = ls->z;
                unsigned int n = z->n;
                z->n = n - 1;
                if (n != 0)
                    ls->current = *ls->z->p++;
                else
                    ls->current = FUN_0021a550(ls->z);
            }
            break;
        }
    }
}
