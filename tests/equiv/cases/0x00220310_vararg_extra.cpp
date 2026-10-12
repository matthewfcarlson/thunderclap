// STATUS: equivalent (tools/equiv.py level 3: 96 inputs, branch coverage 17/20, incomplete)
// FUN_00220310 @ 0x00220310
struct State;

struct Zio {
    unsigned int n;
    unsigned char *p;
};

struct Reader {
    State *L;
    Zio *zio;
    int unused8;
    int swap;
};

// equiv-conv: FUN_00220220 eax
void FUN_00220220(Reader *S);
// equiv-conv: FUN_002202a0 eax edi stack
void FUN_002202a0(Reader *S, int size, const char *name);
// equiv-conv: FUN_0021f8c0 eax ecx edx
void FUN_0021f8c0(int size, void *dst, Reader *r);
// equiv-conv: FUN_0021f800 stack esi
void FUN_0021f800(const char *msg, Reader *r, ...);
int __cdecl FUN_0021a550(Zio *z);

// Lua 5.0 luaU_loadheader tail (version, endianness, sizes, test number); S arrives in eax.
// equiv-conv: FUN_00220310 eax
void FUN_00220310(Reader *S)
{
    float x;
    int ch;
    unsigned int n;
    Zio *z;

    FUN_00220220(S);

    z = S->zio;
    n = z->n;
    z->n = n - 1;
    z = S->zio;
    if (n != 0) {
        unsigned char *p = z->p;
        ch = *p;
        z->p = p + 1;
    } else {
        ch = FUN_0021a550(z);
    }
    if (ch == -1)
        FUN_0021f800("unexpected end of file", S);

    int version = (unsigned char)ch;
    if (version > 0x51)
        FUN_0021f800("bad version (read %d.%d; expected at %s %d.%d)", S, version / 16, version % 16, "most", 6, 1);
    if (version < 0x51)
        FUN_0021f800("bad version (read %d.%d; expected at %s %d.%d)", S, version / 16, version % 16, "least", 5, 1);

    z = S->zio;
    n = z->n;
    z->n = n - 1;
    z = S->zio;
    if (n != 0) {
        unsigned char *p = z->p;
        ch = *p;
        z->p = p + 1;
    } else {
        ch = FUN_0021a550(z);
    }
    if (ch == -1)
        FUN_0021f800("unexpected end of file", S);

    S->swap = ((char)ch != 1);

    FUN_002202a0(S, 4, "int");
    FUN_002202a0(S, 4, "size_t");
    FUN_002202a0(S, 4, "instruction");
    FUN_002202a0(S, 4, "number");

    FUN_0021f8c0(4, &x, S);
    if ((int)x != 0x1df5e76)
        FUN_0021f800("unknown number format", S);
}
