// STATUS: equivalent (tools/equiv.py level 3: 400 inputs, branch coverage 38/40, incomplete; run with --inputs 12000)
// FUN_002611b0 @ 0x002611b0
extern "C" int strcmp(const char *a, const char *b);

struct Interp;

struct Builtin {
    const char *name;
    const char *(__cdecl *fn)(Interp *in);
};
extern Builtin DAT_004cd388[];
extern int DAT_004cd418;

struct Str {
    char data[0x10];
    Str *FUN_0023fc40(const char *text, int len);
    const char *FUN_0023fb00();
    void FUN_00240060();
};

struct Symbols;

struct Interp {
    Symbols *symbols;        // 0x0000
    char pad04[0x2004 - 4];
    char *out;               // 0x2004
    char *cur;               // 0x2008
    char *end;               // 0x200c
};

void __cdecl FUN_00260b30(Interp *in);
int __cdecl FUN_002673a0(const char *text, int radix);
Str *__cdecl FUN_002610e0(Symbols *symbols, int *key);

const char *__cdecl FUN_002611b0(Interp *in)
{
    if (in->cur >= in->end)
        return "";

    FUN_00260b30(in);
    char *p = in->cur;
    if (*p == '(') {
        in->cur = p + 1;
        const char *result = FUN_002611b0(in);
        FUN_00260b30(in);
        char *q = in->cur;
        if (!(q < in->end) && *q != ')')
            return "Missing )";
        in->cur = q + 1;
        return result;
    }

    char *token = in->out;
    while (p < in->end) {
        char c = *p;
        if (c == ' ' || c == '(' || c == ')')
            break;
        *in->out = c;
        in->out++;
        p++;
    }
    *in->out = 0;
    in->out++;
    in->cur = p;

    if (*token != '$')
        return token;

    Str name;
    int key = FUN_002673a0(name.FUN_0023fc40(token + 1, 2)->FUN_0023fb00(), 0);
    Str *found = FUN_002610e0(in->symbols, &key);
    name.FUN_00240060();

    if (found != 0) {
        char *start = in->out;
        const char *s = found->FUN_0023fb00();
        while (*s != 0) {
            *in->out = *s;
            in->out++;
            s++;
        }
        *in->out = 0;
        in->out++;
        return start;
    }

    for (int i = 0; i < DAT_004cd418; i++) {
        if (strcmp(token + 1, DAT_004cd388[i].name) == 0)
            return DAT_004cd388[i].fn(in);
    }
    return "Undefined symbol";
}
