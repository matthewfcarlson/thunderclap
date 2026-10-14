// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 12/12)
// FUN_0021f8c0 @ 0x0021f8c0
struct ZIO {
    unsigned int n;
    const unsigned char *p;
};
struct LoadState {
    char pad0[4];
    ZIO *Z;
    char pad8[4];
    int swap;       // 0x0c
};
int __cdecl FUN_0021a550(ZIO *z);
int __cdecl FUN_0021a610(ZIO *z, char *dst, unsigned int n);
// equiv-conv: FUN_0021f800 stack esi
void FUN_0021f800(const char *msg, LoadState *S);

// LoadBlock: reads n bytes into buf, reversed when the state asks for byte swapping.
// equiv-conv: FUN_0021f8c0 ecx eax edx
void FUN_0021f8c0(char *buf, unsigned int n, LoadState *S)
{
    if (S->swap == 0) {
        if (FUN_0021a610(S->Z, buf, n) != 0)
            FUN_0021f800("unexpected end of file", S);
        return;
    }
    char *dst = buf + n - 1;
    for (; n != 0; n--) {
        int c;
        if (S->Z->n-- > 0)
            c = *S->Z->p++;
        else
            c = FUN_0021a550(S->Z);
        if (c == -1)
            FUN_0021f800("unexpected end of file", S);
        *dst-- = (char)c;
    }
}
