// STATUS: equivalent (tools/equiv.py level 3: 219 inputs, branch coverage 52/56, incomplete)
// FUN_000b1db0 @ 0x000b1db0
extern float DAT_003f335c;
void __cdecl FUN_00267830(char *dst, const char *src, int n);

struct Str {
    int count;
    char *data;
    void FUN_000b1020(int n);
};

class CPhysicalController {
public:
    virtual void f0();
    char pad4[0x54];
    Str srcA[11];   // 0x58
    Str srcB[12];   // 0xb0
    Str dstA[11];   // 0x110
    Str dstB[12];   // 0x168
    Str srcC[13];   // 0x1c8
    Str srcD[12];   // 0x230
    Str dstC[13];   // 0x290
    Str dstD[12];   // 0x2f8

    void FUN_000b1db0();
};

void CPhysicalController::FUN_000b1db0()
{
    Str *srcs[4];
    Str *dsts[4];
    int counts[4];
    srcs[0] = srcA; dsts[0] = dstA; counts[0] = 11;
    srcs[1] = srcB; dsts[1] = dstB; counts[1] = 12;
    srcs[2] = srcC; dsts[2] = dstC; counts[2] = 13;
    srcs[3] = srcD; dsts[3] = dstD; counts[3] = 12;
    for (int g = 0; g < 4; g++) {
        Str *s = srcs[g];
        Str *d = dsts[g];
        for (int k = 0; k < counts[g]; k++, s++, d++) {
            int n = s->count;
            d->FUN_000b1020(n);
            int off = 0;
            for (int i = 0; i < n; i++, off += 0x20) {
                const char *from;
                if (off >= 0 && i < s->count)
                    from = s->data + off;
                else
                    from = (const char *)&DAT_003f335c;
                if (d->count <= 0)
                    d->FUN_000b1020(1);
                FUN_00267830(d->data + off, from, 0x20);
            }
        }
    }
}
