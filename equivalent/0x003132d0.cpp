// STATUS: equivalent (tools/equiv.py level 3: 58 inputs, branch coverage 26/26)
// FUN_003132d0 @ 0x003132d0
struct Box_3132d0 {
    float minx, miny, minz;
    float maxx, maxy, maxz;
};

class HashGrid {
public:
    unsigned short table[0x1000];
    short* parent;
    void FUN_003132d0(Box_3132d0* boxes, int count);
};

void HashGrid::FUN_003132d0(Box_3132d0* boxes, int count)
{
    for (int i = 0; i < count; i++) {
        Box_3132d0* b = &boxes[i];
        for (int x = (int)(__int64)b->minx; x <= (int)(__int64)b->maxx; x++) {
            for (int y = (int)(__int64)b->miny; y <= (int)(__int64)b->maxy; y++) {
                for (int z = (int)(__int64)b->minz; z <= (int)(__int64)b->maxz; z++) {
                    int h = (((z << 4) ^ y) << 4) ^ x;
                    int slot = (h ^ (h >> 12)) & 0xfff;
                    unsigned short entry = table[slot];
                    if (entry == 0xffff) {
                        table[slot] = (unsigned short)(__int64)i;
                    } else {
                        int other = (short)entry;
                        short* u = parent;
                        int ri = i;
                        for (int p = u[ri]; p != ri; p = u[ri])
                            ri = p;
                        u[i] = (short)(__int64)ri;
                        u = parent;
                        int ro = other;
                        for (int p = u[ro]; p != ro; p = u[ro])
                            ro = p;
                        u[other] = (short)(__int64)ro;
                        u = parent;
                        u[u[other]] = u[u[i]];
                    }
                }
            }
        }
    }
}
