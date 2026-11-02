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
extern "C" void __cdecl FUN_00215460(void *, int);
// equiv-conv: FUN_0021fa80 eax
extern "C" Str *FUN_0021fa80(Reader *S);
// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char *, unsigned int, void *);
// equiv-conv: FUN_0021f800 esi stack
void FUN_0021f800(Reader *r, const char *msg);
int FUN_0021a550(Zio_220050 *z);
// equiv-conv: FUN_0021fcb0 eax ebx
extern "C" void __cdecl FUN_0021fcb0(void *, void *);
// equiv-conv: FUN_0021faf0 eax ebx
extern "C" void __cdecl FUN_0021faf0(void *, void *);
// equiv-conv: FUN_0021fb50 eax stack
extern "C" void __cdecl FUN_0021fb50(void *, void *);
// equiv-conv: FUN_0021fd10 eax stack
extern "C" void __cdecl FUN_0021fd10(void *, void *);
// equiv-conv: FUN_0021fe20 eax stack
extern "C" void __cdecl FUN_0021fe20(void *, void *);
extern "C" int __cdecl FUN_002146a0(void *);

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

extern "C" void *FUN_00220050(void *S, void *parent)
{
    int v;
    Proto_220050 *f = FUN_002196d0(((Reader *)S)->L);
    State_220050 *L = ((Reader *)S)->L;
    TValue_220050 *t = L->top;
    t->val = f;
    t->tt = 9;
    L = ((Reader *)S)->L;
    if ((char *)L->stack_last - (char *)L->top <= 8)
        FUN_00215460((State_220050 *)L, 1);
    ((Reader *)S)->L->top++;
    f->source = FUN_0021fa80(((Reader *)S));
    if (f->source == 0)
        f->source = ((Str *)parent);
    FUN_0021f8c0((char *)(void *)(&v), 4, (Reader *)((Reader *)S));
    if (v < 0)
        FUN_0021f800(((Reader *)S), "bad integer");
    f->lineDefined = v;
    f->b44 = (unsigned char)LoadByte(((Reader *)S));
    f->b45 = (unsigned char)LoadByte(((Reader *)S));
    f->b46 = (unsigned char)LoadByte(((Reader *)S));
    f->b47 = (unsigned char)LoadByte(((Reader *)S));
    FUN_0021fcb0((Reader *)((Reader *)S), (Proto_220050 *)f);
    FUN_0021fb50((Reader *)((Reader *)S), (Proto_220050 *)f);
    FUN_0021fd10((Reader *)((Reader *)S), (Proto_220050 *)f);
    FUN_0021fe20((Reader *)((Reader *)S), (Proto_220050 *)f);
    FUN_0021faf0((Reader *)((Reader *)S), (Proto_220050 *)f);
    if (FUN_002146a0((Proto_220050 *)f) == 0)
        FUN_0021f800(((Reader *)S), "bad code");
    ((Reader *)S)->L->top--;
    return (Proto_220050 *)f;
}
