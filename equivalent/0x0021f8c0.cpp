// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 12/12)
// FUN_0021f8c0 @ 0x0021f8c0
// FUN_0021f8c0 @ 0x0021f8c0
struct ZIO_21f8c0 {
    unsigned int n;
    const unsigned char *p;
};
struct LoadState_21f8c0 {
    char pad0[4];
    ZIO_21f8c0 *Z;
    char pad8[4];
    int swap;       // 0x0c
};
int __cdecl FUN_0021a550(ZIO_21f8c0 *z);
extern "C" unsigned int __cdecl FUN_0021a610(void *, void *, unsigned int);
// equiv-conv: FUN_0021f800 esi stack
void FUN_0021f800(LoadState_21f8c0 *S, const char *msg);

// LoadBlock: reads n bytes into buf, reversed when the state asks for byte swapping.
// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void FUN_0021f8c0(char *buf, unsigned int n, void *S)
{
    if (((LoadState_21f8c0 *)S)->swap == 0) {
        if (((int)FUN_0021a610((ZIO_21f8c0 *)(((LoadState_21f8c0 *)S)->Z), (char *)buf, n)) != 0)
            FUN_0021f800(((LoadState_21f8c0 *)S), "unexpected end of file");
        return;
    }
    char *dst = buf + n - 1;
    for (; n != 0; n--) {
        int c;
        if (((LoadState_21f8c0 *)S)->Z->n-- > 0)
            c = *((LoadState_21f8c0 *)S)->Z->p++;
        else
            c = FUN_0021a550(((LoadState_21f8c0 *)S)->Z);
        if (c == -1)
            FUN_0021f800(((LoadState_21f8c0 *)S), "unexpected end of file");
        *dst-- = (char)c;
    }
}
