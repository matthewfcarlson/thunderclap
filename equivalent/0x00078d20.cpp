// STATUS: equivalent (tools/equiv.py level 3: 47 inputs, branch coverage 24/24)
// FUN_00078d20 @ 0x00078d20
struct Rng {
    unsigned int s0;
    unsigned int s1;
};
Rng *__cdecl FUN_000964d0();

struct Rec {
    int count;
    int pad[3];
};

struct Slot {
    char pad0[0x18];
    int f18;
    char pad1c[0xbc - 0x1c];
    int keyA;
    int keyB;
};

class Pool {
public:
    char pad0[0x34b0];
    Rec recs[9];
    char pad3540[8];
    int count;
    Slot *slots[20];
    int slotCount;

    bool FUN_00078d20(int a, int b, int *pIdx, int *pSub);
};

bool Pool::FUN_00078d20(int a, int b, int *pIdx, int *pSub)
{
    Rng *r = FUN_000964d0();
    r->s0 = 36969 * (r->s0 & 0xffff) + (r->s0 >> 16);
    r->s1 = 18000 * (r->s1 & 0xffff) + (r->s1 >> 16);
    *pIdx = ((r->s0 << 16) + (r->s1 & 0xffff)) % count;

    r->s0 = 36969 * (r->s0 & 0xffff) + (r->s0 >> 16);
    r->s1 = 18000 * (r->s1 & 0xffff) + (r->s1 >> 16);
    *pSub = ((r->s0 << 16) + (r->s1 & 0xffff)) % recs[*pIdx].count;

    if (count <= 0)
        return false;
    int i = 0;
    do {
        int sum = 0;
        for (int k = 0; k < *pIdx; k++)
            sum += recs[k].count;
        int m = recs[*pIdx].count;
        for (int j = 0; j < m; j++) {
            int k = 0;
            for (; k < slotCount; k++) {
                Slot *s = slots[k];
                if (s->keyA == a && s->keyB == b && s->f18 == *pSub + sum)
                    break;
            }
            if (k == slotCount)
                return true;
            *pSub = (*pSub + 1) % m;
        }
        *pIdx = (*pIdx + 1) % count;
        i++;
    } while (i < count);
    return false;
}
