extern "C" int __cdecl iscntrl(int);
extern int __cdecl Format(int, const char *, ...);
extern int lookup[];
int __cdecl FUN_0021af00(int a, int b)
{
    int r;
    if (b < 0x101) {
        if (iscntrl(b))
            r = Format(*(int *)(a + 0x20), "char(%d)", b);
        else
            r = Format(*(int *)(a + 0x20), "%c", b);
    } else {
        r = lookup[b];
    }
    return r;
}