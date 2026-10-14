// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0021fa80 @ 0x0021fa80
struct State;
struct Zio;
struct Buffer;
struct Str;

struct Reader {
    State *L;
    Zio *zio;
    Buffer *buf;
};

// equiv-conv: FUN_0021f8c0 eax ecx edx
void FUN_0021f8c0(int size, void *dst, Reader *r);
// equiv-conv: FUN_0021f800 stack esi
void FUN_0021f800(const char *msg, Reader *r);
char *FUN_0021a6b0(State *L, Buffer *buf, unsigned int n);
int FUN_0021a610(Zio *z, char *dst, unsigned int n);
Str *FUN_00219430(State *L, const char *s, unsigned int len);

// equiv-conv: FUN_0021fa80 eax
Str *FUN_0021fa80(Reader *r)
{
    unsigned int size;
    FUN_0021f8c0(4, &size, r);
    if (size == 0)
        return 0;
    char *s = FUN_0021a6b0(r->L, r->buf, size);
    if (FUN_0021a610(r->zio, s, size))
        FUN_0021f800("unexpected end of file", r);
    return FUN_00219430(r->L, s, size - 1);
}
