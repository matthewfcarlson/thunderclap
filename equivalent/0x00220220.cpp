// STATUS: equivalent (tools/equiv.py level 3: 3008 inputs, branch coverage 10/10)
// FUN_00220220 @ 0x00220220
struct ZIO_220220 {
    unsigned int n;
    const unsigned char *p;
};
struct LoadState_220220 {
    char pad0[4];
    ZIO_220220 *Z;
};
int __cdecl FUN_0021a550(ZIO_220220 *z);
void __cdecl FUN_0021f800(const char *msg);

// equiv-conv: FUN_00220220 eax
void FUN_00220220(LoadState_220220 *S)
{
    const char *s = "\x1bLua";
    for (;;) {
        int c;
        if (S->Z->n-- > 0)
            c = *S->Z->p++;
        else
            c = FUN_0021a550(S->Z);
        if (c == -1)
            FUN_0021f800("unexpected end of file");
        if (c != *s)
            break;
        s++;
        if (*s == 0)
            return;
    }
    if (*s != 0)
        FUN_0021f800("bad signature");
}
