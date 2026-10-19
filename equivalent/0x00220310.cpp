// STATUS: equivalent (tools/equiv.py level 3: 12640 inputs, branch coverage 18/20, incomplete)
// FUN_00220310 @ 0x00220310
// FUN_00220310 @ 0x00220310
// FUN_00220310 @ 0x00220310
struct State;

struct Zio_220310 {
    unsigned int n;
    unsigned char *p;
};

struct Reader {
    State *L;
    Zio_220310 *zio;
    int unused8;
    int swap;
};

// equiv-conv: FUN_00220220 eax
void FUN_00220220(Reader *S);
// equiv-conv: FUN_002202a0 eax edi stack
void FUN_002202a0(Reader *S, int size, const char *name);
// equiv-conv: FUN_0021f8c0 ecx eax edx
void FUN_0021f8c0(void *dst, int size, Reader *r);
// equiv-conv: FUN_0021f800 esi stack
void FUN_0021f800(Reader *r, const char *msg, ...);
int __cdecl FUN_0021a550(Zio_220310 *z);

// Lua 5.0 luaU_loadheader tail (version, endianness, sizes, test number); S arrives in eax.
// equiv-conv: FUN_00220310 eax
void FUN_00220310(Reader *S)
{
    float x;
    int ch;
    unsigned int n;
    Zio_220310 *z;

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
        FUN_0021f800(S, "unexpected end of file");

    int version = (unsigned char)ch;
    if (version > 0x51)
        FUN_0021f800(S, "bad version (read %d.%d; expected at %s %d.%d)", version / 16, version % 16, "most", 5, 1);
    if (version < 0x51)
        FUN_0021f800(S, "bad version (read %d.%d; expected at %s %d.%d)", version / 16, version % 16, "least", 5, 1);

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
        FUN_0021f800(S, "unexpected end of file");

    S->swap = ((char)ch != 1);

    FUN_002202a0(S, 4, "int");
    FUN_002202a0(S, 4, "size_t");
    FUN_002202a0(S, 4, "instruction");
    FUN_002202a0(S, 4, "number");

    FUN_0021f8c0(&x, 4, S);
    if ((int)x != 0x1df5e76)
        FUN_0021f800(S, "unknown number format");
}
