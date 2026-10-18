// STATUS: equivalent (tools/equiv.py level 3: 11901 inputs, branch coverage 24/24)
// FUN_00220050 @ 0x00220050
// FUN_00220050 @ 0x00220050
struct Str;

struct Zio_220050 {
    unsigned int n;
    unsigned char *p;
};

struct TValue_220050 {
    int tt;
    void *val;
};

struct State_220050 {
    char pad0[8];
    TValue_220050 *top;
    char pad1[0x18 - 0xc];
    TValue_220050 *stack_last;
};

struct Reader {
    State_220050 *L;
    Zio_220050 *zio;
    int unused8;
    int swap;
};

struct Proto_220050 {
    char pad0[0x20];
    Str *source;
    char pad1[0x3c - 0x24];
    int lineDefined;
    char pad2[4];
    unsigned char b44, b45, b46, b47;
};

Proto_220050 *FUN_002196d0(State_220050 *L);
void FUN_00215460(State_220050 *L, int n);
// equiv-conv: FUN_0021fa80 eax
Str *FUN_0021fa80(Reader *S);
// equiv-conv: FUN_0021f8c0 ecx eax edx
void FUN_0021f8c0(void *dst, int size, Reader *r);
// equiv-conv: FUN_0021f800 esi stack
void FUN_0021f800(Reader *r, const char *msg);
int FUN_0021a550(Zio_220050 *z);
// equiv-conv: FUN_0021fcb0 eax ebx
void FUN_0021fcb0(Reader *S, Proto_220050 *f);
// equiv-conv: FUN_0021faf0 eax ebx
void FUN_0021faf0(Reader *S, Proto_220050 *f);
// equiv-conv: FUN_0021fb50 eax stack
void FUN_0021fb50(Reader *S, Proto_220050 *f);
// equiv-conv: FUN_0021fd10 eax stack
void FUN_0021fd10(Reader *S, Proto_220050 *f);
// equiv-conv: FUN_0021fe20 eax stack
void FUN_0021fe20(Reader *S, Proto_220050 *f);
int FUN_002146a0(Proto_220050 *f);

static int LoadByte(Reader *S)
{
    Zio_220050 *z = S->zio;
    unsigned int n = z->n;
    z->n = n - 1;
    z = S->zio;
    int ch;
    if (n != 0) {
        unsigned char *p = z->p;
        ch = *p;
        z->p = p + 1;
    } else {
        ch = FUN_0021a550(z);
    }
    if (ch == -1)
        FUN_0021f800(S, "unexpected end of file");
    return ch;
}

Proto_220050 *FUN_00220050(Reader *S, Str *parent)
{
    int v;
    Proto_220050 *f = FUN_002196d0(S->L);
    State_220050 *L = S->L;
    TValue_220050 *t = L->top;
    t->val = f;
    t->tt = 9;
    L = S->L;
    if ((char *)L->stack_last - (char *)L->top <= 8)
        FUN_00215460(L, 1);
    S->L->top++;
    f->source = FUN_0021fa80(S);
    if (f->source == 0)
        f->source = parent;
    FUN_0021f8c0(&v, 4, S);
    if (v < 0)
        FUN_0021f800(S, "bad integer");
    f->lineDefined = v;
    f->b44 = (unsigned char)LoadByte(S);
    f->b45 = (unsigned char)LoadByte(S);
    f->b46 = (unsigned char)LoadByte(S);
    f->b47 = (unsigned char)LoadByte(S);
    FUN_0021fcb0(S, f);
    FUN_0021fb50(S, f);
    FUN_0021fd10(S, f);
    FUN_0021fe20(S, f);
    FUN_0021faf0(S, f);
    if (FUN_002146a0(f) == 0)
        FUN_0021f800(S, "bad code");
    S->L->top--;
    return f;
}
