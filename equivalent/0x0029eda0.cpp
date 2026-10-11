// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 18/18)
// FUN_0029eda0 @ 0x0029eda0
struct Source {
    int FUN_002a0850();
    float *FUN_002a0870();
    char pad0[0x12];
    char flag12;
    char flag13;
    char pad14[0x50 - 0x14];
    int mode;
};

struct Entry {
    int f0;
    unsigned color;
    float radiusSq;
    char pad0c[0x18 - 0xc];
    unsigned flags;
    int f1c;
};

struct Backend {
    void FUN_002a0fc0(int index, Source *src);
};

extern unsigned DAT_004cf730;

class EntryTable {
public:
    Backend *backend;
    Entry *entries;
    void FUN_0029eda0(int index, Source *src);
};

void EntryTable::FUN_0029eda0(int index, Source *src)
{
    backend->FUN_002a0fc0(index, src);
    entries[index].f0 = 0;
    entries[index].color = DAT_004cf730;
    entries[index].f1c = 0;
    entries[index].flags = 0;
    if (!src)
        return;

    if (src->FUN_002a0850() == 1) {
        float *p = src->FUN_002a0870();
        entries[index].radiusSq = *p;
        float v = entries[index].radiusSq;
        entries[index].radiusSq = v * v;
    } else if (src->FUN_002a0850() == 2) {
        float *p = src->FUN_002a0870();
        entries[index].radiusSq = p[0] * p[0] + p[1] * p[1] + p[2] * p[2];
    } else if (src->FUN_002a0850() == 3) {
        float *p = src->FUN_002a0870();
        entries[index].radiusSq = p[0] * p[0] + p[1] * p[1] + p[2] * p[2];
    } else {
        entries[index].radiusSq = 1.0e12f;
    }

    if (src->mode != 2 && src->flag12)
        entries[index].flags |= 4;
    else
        entries[index].flags &= ~4u;

    if (src->flag13)
        entries[index].flags |= 8;
    else
        entries[index].flags &= ~8u;

    entries[index].flags &= ~0x13u;
    int mode = src->mode;
    if (mode == 0)
        entries[index].flags |= 0x11;
    else if (mode == 2)
        entries[index].flags |= 0x12;
}
