// FUN_002613b0 @ 0x002613b0
struct Symbols;

struct Str_2613b0 {
    char data[0xc];
    Str_2613b0 *FUN_0023fc40(const char *text, int len);
    const char *FUN_0023fb00();
    int FUN_0023f990();
    void FUN_00240060();
    void FUN_00240190(Str_2613b0 *src);
};

struct Interp_2613b0 {
    Symbols *symbols;        // 0x0000
    char buf[0x2000];
    char *out;               // 0x2004
    char *cur;               // 0x2008
    char *end;               // 0x200c
};

const char *__cdecl FUN_002611b0(Interp_2613b0 *in);

void __cdecl FUN_002613b0(Symbols *symbols, Str_2613b0 *dest, Str_2613b0 *src)
{
    Interp_2613b0 in;
    in.symbols = symbols;
    in.out = in.buf;
    in.cur = (char *)src->FUN_0023fb00();
    in.end = in.cur + src->FUN_0023f990();

    const char *last = "";
    for (const char *r = FUN_002611b0(&in); *r != 0; r = FUN_002611b0(&in))
        last = r;

    Str_2613b0 tmp;
    dest->FUN_00240190(tmp.FUN_0023fc40(last, 2));
    tmp.FUN_00240060();
}
