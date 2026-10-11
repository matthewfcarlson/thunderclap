// STATUS: equivalent (tools/equiv.py level 3: 27 inputs, branch coverage 25/26, incomplete)
// FUN_003132d0 @ 0x003132d0
struct Box {
    float minx, miny, minz;
    float maxx, maxy, maxz;
};

class HashGrid {
public:
    unsigned short table[0x1000];
    short* parent;
    void FUN_003132d0(Box* boxes, int count);
};

void HashGrid::FUN_003132d0(Box* boxes, int count)
{
    for (int i = 0; i < count; i++) {
        Box* b = &boxes[i];
        for (int x = (int)b->minx; x <= (int)b->maxx; x++) {
            for (int y = (int)b->miny; y <= (int)b->maxy; y++) {
                for (int z = (int)b->minz; z <= (int)b->maxz; z++) {
                    int h = (((z << 4) ^ y) << 4) ^ x;
                    int slot = (h ^ (h >> 12)) & 0xfff;
                    unsigned short entry = table[slot];
                    if (entry == 0xffff) {
                        table[slot] = (unsigned short)i;
                    } else {
                        int other = (short)entry;
                        short* u = parent;
                        int ri = i;
                        for (int p = u[ri]; p != ri; p = u[ri])
                            ri = p;
                        u[i] = (short)ri;
                        u = parent;
                        int ro = other;
                        for (int p = u[ro]; p != ro; p = u[ro])
                            ro = p;
                        u[other] = (short)ro;
                        u = parent;
                        u[u[other]] = u[u[i]];
                    }
                }
            }
        }
    }
}
