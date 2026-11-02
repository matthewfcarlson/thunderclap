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
extern "C" int __cdecl FUN_0021b480(void *);
void FUN_0021afd0(LexState_21b520* ls, const char* msg, int token);
int FUN_0021a550(Zio_21b520* z);
char* FUN_0021add0(void* L, char* block, unsigned int oldsize, unsigned int newsize);
TString* FUN_00219430(void* L, const char* str, unsigned int len);
TValue_21b520* FUN_0021a500(void* L, Table* t, TString* key);

// equiv-conv: FUN_0021b520 ecx eax stack
extern "C" void FUN_0021b520(void * ls, int sep, void * seminfo)
{
    int cont = 0;
    FUN_0021b1c0(((LexState_21b520 *)ls));
    if (((LexState_21b520 *)ls)->current == 10 || ((LexState_21b520 *)ls)->current == 13)
        FUN_0021b0d0(((LexState_21b520 *)ls));
    for (;;) {
        switch (((LexState_21b520 *)ls)->current) {
        case -1:
            FUN_0021afd0(((LexState_21b520 *)ls), ((SemInfo_21b520 *)seminfo) ? "unfinished long string" : "unfinished long comment", 0x11f);
            break;
        case '[':
            if (FUN_0021b480((LexState_21b520 *)((LexState_21b520 *)ls)) == sep) {
                FUN_0021b1c0(((LexState_21b520 *)ls));
                cont++;
            }
            break;
        case ']':
            if (FUN_0021b480((LexState_21b520 *)((LexState_21b520 *)ls)) == sep) {
                FUN_0021b1c0(((LexState_21b520 *)ls));
                if (cont-- == 0) {
                    if (((SemInfo_21b520 *)seminfo)) {
                        Mbuffer_21b520* b = ((LexState_21b520 *)ls)->buff;
                        void* L = ((LexState_21b520 *)ls)->L;
                        TString* ts = FUN_00219430(L, b->buffer + sep + 2, b->n + (0x7ffffffe - sep) * 2);
                        TValue_21b520* o = FUN_0021a500(L, ((LexState_21b520 *)ls)->fs->h, ts);
                        if (o->tt == 0) {
                            o->v = 1;
                            o->tt = 1;
                        }
                        ((SemInfo_21b520 *)seminfo)->ts = ts;
                    }
                    return;
                }
            }
            break;
        case '\n':
        case '\r': {
            Mbuffer_21b520* b = ((LexState_21b520 *)ls)->buff;
            if (b->n + 1 > b->size) {
                b->buffer = FUN_0021add0(((LexState_21b520 *)ls)->L, b->buffer, b->size, b->size * 2 + 0x20);
                b->size = b->size * 2 + 0x20;
            }
            b->buffer[b->n] = '\n';
            b->n++;
            FUN_0021b0d0(((LexState_21b520 *)ls));
            if (!((SemInfo_21b520 *)seminfo))
                ((LexState_21b520 *)ls)->buff->n = 0;
            break;
        }
        default:
            if (((SemInfo_21b520 *)seminfo)) {
                FUN_0021b1c0(((LexState_21b520 *)ls));
            } else {
                Zio_21b520* z = ((LexState_21b520 *)ls)->z;
                unsigned int n = z->n;
                z->n = n - 1;
                if (n != 0)
                    ((LexState_21b520 *)ls)->current = *((LexState_21b520 *)ls)->z->p++;
                else
                    ((LexState_21b520 *)ls)->current = FUN_0021a550(((LexState_21b520 *)ls)->z);
            }
            break;
        }
    }
}
