// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 34/34)
// FUN_0021fe20 @ 0x0021fe20
struct Proto_21fe20;

struct Zio_21fe20 {
    unsigned int n;                 // 0x0
    unsigned char *p;               // 0x4
};

struct LoadState_21fe20 {
    void *L;                        // 0x0
    Zio_21fe20 *z;                         // 0x4
    void *buff;                     // 0x8
};

struct TValue_21fe20 {
    int tt;                         // 0x0
    void *value;                    // 0x4
};

struct Proto_21fe20 {
    char pad0[8];
    TValue_21fe20 *k;                      // 0x08
    char pad0c[4];
    Proto_21fe20 **p;                      // 0x10
    char pad14[0x20 - 0x14];
    void *source;                   // 0x20
    char pad24[4];
    int sizek;                      // 0x28
    char pad2c[0x34 - 0x2c];
    int sizep;                      // 0x34
};

void __cdecl FUN_0021f800(const char *fmt, ...);
// equiv-conv: FUN_0021f8c0 edx ecx eax
void FUN_0021f8c0(LoadState_21fe20 *S, void *out, int size);
void *__cdecl FUN_0021add0(void *L, void *block, int oldsize, int newsize);
int __cdecl FUN_0021a550(Zio_21fe20 *z);
void *__cdecl FUN_0021a6b0(void *L, void *buff, int size);
int __cdecl FUN_0021a610(Zio_21fe20 *z, void *buff, int size);
void *__cdecl FUN_00219430(void *L, void *str, int len);
Proto_21fe20 *__cdecl FUN_00220050(LoadState_21fe20 *S, void *source);

// Lua 5.0 undump: LoadConstants(S, f) followed by LoadFunctions
// equiv-conv: FUN_0021fe20 eax stack
void FUN_0021fe20(LoadState_21fe20 *S, Proto_21fe20 *f)
{
    struct Frame {
        int n;
        int index;      // constant index, later reused for the function count
        int size;
        int num;
    } fr;

    FUN_0021f8c0(S, &fr.n, 4);
    if (fr.n < 0)
        FUN_0021f800("bad integer");

    int n = fr.n;
    f->k = (TValue_21fe20 *)FUN_0021add0(S->L, 0, 0, n * 8);
    f->sizek = n;
    for (int i = 0; i < n; ++i)
        f->k[i].tt = 0;

    for (fr.index = 0; fr.index < n; ++fr.index) {
        TValue_21fe20 *o = &f->k[fr.index];
        Zio_21fe20 *z = S->z;
        unsigned int left = z->n;
        z->n = left - 1;
        z = S->z;
        int c;
        if (left != 0)
            c = *z->p++;
        else
            c = FUN_0021a550(z);
        if (c == -1)
            FUN_0021f800("unexpected end of file");

        switch (c & 0xff) {
        case 0:
            o->tt = 0;
            break;
        case 3:
            FUN_0021f8c0(S, &fr.num, 4);
            o->value = (void *)fr.num;
            o->tt = 3;
            break;
        case 4:
            FUN_0021f8c0(S, &fr.size, 4);
            if (fr.size == 0) {
                n = fr.n;
                o->value = 0;
                o->tt = 4;
            } else {
                int size = fr.size;
                void *buff = FUN_0021a6b0(S->L, S->buff, size);
                if (FUN_0021a610(S->z, buff, size) != 0)
                    FUN_0021f800("unexpected end of file");
                o->value = FUN_00219430(S->L, buff, size - 1);
                n = fr.n;
                o->tt = 4;
            }
            break;
        default:
            FUN_0021f800("bad constant type (%d)", c & 0xff);
            break;
        }
    }

    FUN_0021f8c0(S, &fr.index, 4);
    if (fr.index < 0)
        FUN_0021f800("bad integer");

    int np = fr.index;
    f->p = (Proto_21fe20 **)FUN_0021add0(S->L, 0, 0, np * 4);
    f->sizep = np;
    for (int i = 0; i < np; ++i)
        f->p[i] = 0;
    for (int i = 0; i < np; ++i)
        f->p[i] = FUN_00220050(S, f->source);
}
