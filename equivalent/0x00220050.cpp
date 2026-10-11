// STATUS: equivalent (tools/equiv.py level 3: 125 inputs, branch coverage 24/24)
// FUN_00220050 @ 0x00220050
struct Str;

struct Zio {
    unsigned int n;
    unsigned char *p;
};

struct TValue {
    int tt;
    void *val;
};

struct State {
    char pad0[8];
    TValue *top;
    char pad1[0x18 - 0xc];
    TValue *stack_last;
};

struct Reader {
    State *L;
    Zio *zio;
    int unused8;
    int swap;
};

struct Proto {
    char pad0[0x20];
    Str *source;
    char pad1[0x3c - 0x24];
    int lineDefined;
    char pad2[4];
    unsigned char b44, b45, b46, b47;
};

Proto *FUN_002196d0(State *L);
void FUN_00215460(State *L, int n);
// equiv-conv: FUN_0021fa80 eax
Str *FUN_0021fa80(Reader *S);
// equiv-conv: FUN_0021f8c0 eax ecx edx
void FUN_0021f8c0(int size, void *dst, Reader *r);
// equiv-conv: FUN_0021f800 stack esi
void FUN_0021f800(const char *msg, Reader *r);
int FUN_0021a550(Zio *z);
// equiv-conv: FUN_0021fcb0 eax ebx
void FUN_0021fcb0(Reader *S, Proto *f);
// equiv-conv: FUN_0021faf0 eax ebx
void FUN_0021faf0(Reader *S, Proto *f);
// equiv-conv: FUN_0021fb50 eax stack
void FUN_0021fb50(Reader *S, Proto *f);
// equiv-conv: FUN_0021fd10 eax stack
void FUN_0021fd10(Reader *S, Proto *f);
// equiv-conv: FUN_0021fe20 eax stack
void FUN_0021fe20(Reader *S, Proto *f);
int FUN_002146a0(Proto *f);

static int LoadByte(Reader *S)
{
    Zio *z = S->zio;
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
        FUN_0021f800("unexpected end of file", S);
    return ch;
}

Proto *FUN_00220050(Reader *S, Str *parent)
{
    int v;
    Proto *f = FUN_002196d0(S->L);
    State *L = S->L;
    TValue *t = L->top;
    t->val = f;
    t->tt = 9;
    L = S->L;
    if ((char *)L->stack_last - (char *)L->top <= 8)
        FUN_00215460(L, 1);
    S->L->top++;
    f->source = FUN_0021fa80(S);
    if (f->source == 0)
        f->source = parent;
    FUN_0021f8c0(4, &v, S);
    if (v < 0)
        FUN_0021f800("bad integer", S);
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
        FUN_0021f800("bad code", S);
    S->L->top--;
    return f;
}
