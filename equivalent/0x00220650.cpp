// STATUS: equivalent (tools/equiv.py level 3: 120 inputs, branch coverage 18/22, incomplete)
// FUN_00220650 @ 0x00220650
struct WordBuf {
    char pad[0xc];
    unsigned int* words;
};

struct Ctx_220650 {
    WordBuf* buf;
    char pad[8];
    void* errCtx;
};

extern char DAT_00426ba4[64];
void FUN_0021b060(void* errCtx, const char* msg);

// equiv-conv: FUN_00220650 edx ebx stack stack stack stack stack
void FUN_00220650(int idx, Ctx_220650* ctx, int a1, int a2, int a3, int a4, int a5)
{
    while (idx != -1) {
        unsigned int* words = ctx->buf->words;
        unsigned int* cur = &words[idx];
        int next;
        int delta = (int)((*cur >> 6) & 0x3ffff) - 0x1ffff;
        if (delta == -1)
            next = -1;
        else
            next = delta + idx + 1;

        unsigned int* p = cur;
        if (idx >= 1 && DAT_00426ba4[words[idx - 1] & 0x3f] < 0)
            p = &words[idx - 1];

        unsigned int w = *p;
        int target;
        if ((w & 0x3f) != 0x18) {
            target = a5 - idx - 1;
        } else {
            unsigned int c;
            if ((w & 0x7fc0) != 0) {
                c = (unsigned int)a2;
                if (c == 0xff)
                    c = (w >> 15) & 0x1ff;
                *p = (w & 0xffffff) | (c << 24);
                target = a1;
            } else {
                c = (unsigned int)a4;
                if (c == 0xff)
                    c = (w >> 15) & 0x1ff;
                *p = (w & 0xffffff) | (c << 24);
                target = a3;
            }
            cur = &ctx->buf->words[idx];
            target = target - idx - 1;
        }
        int mag = target < 0 ? -target : target;
        if (mag > 0x1ffff)
            FUN_0021b060(ctx->errCtx, "control structure too long");
        *cur ^= (*cur ^ (((unsigned int)(target + 0x1ffff)) << 6)) & 0xffffc0;
        idx = next;
    }
}
