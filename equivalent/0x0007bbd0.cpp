// STATUS: equivalent (tools/equiv.py level 3: 339 inputs, branch coverage 30/32, incomplete)
// FUN_0007bbd0 @ 0x0007bbd0
struct Mat4;

struct Vec3 {
    float x, y, z;
    void FUN_0022d210(Mat4* m);
};

struct Mat4 {
    float m[16];
    void FUN_0022b980();
    void FUN_0022baf0(Vec3* axis, float angle);
    void FUN_0022be40(Vec3* t);
};

struct Tile {
    short id;
    char active;
    char pad03;
    int bits;
};

struct EntryTail {
    Vec3 b;
    int pad18;
    int owner;
    int p;
    int q;
    char pad28[0x1c];
    char on;
    char pad45[3];
};

struct Entry {
    Vec3 a;
    EntryTail t;
};

struct Flags {
    char a;
    char b;
};

struct Cfg {
    float a, b, c, d;
    char on;
    char pad[3];
};

struct Frame {
    int count;
    int l14;
    EntryTail* cur;
    int l1c;
    int tmp20;
    int slotBase;
    Vec3 pos;
    Vec3 axis;
    Mat4 mat;
    Cfg cfg[7];
};

class HexBoard {
public:
    Tile tiles[800];
    char pad1900[4];
    Entry entries[98];
    Flags flags[7];

    void FUN_00079990(Cfg* cfg, int a2, int a3, int a4, int a5, int a6, int slot, int* out, int a9, int a10);
    void FUN_00079c80(Cfg* cfg, int a2, int a3, int a4, int a5, int a6, int slot, int* out, int a9, int a10);
    void FUN_00079f40(Cfg* cfg, int a2, int a3, int a4, int a5, int a6, int slot, int* out, int a9, int a10);
    void FUN_0007a840(int slot, int k, int* a, int* b);
    void FUN_0007bbd0(int idx);
};

void HexBoard::FUN_0007bbd0(int idx)
{
    if (!tiles[idx].active)
        return;

    int slot = 0;
    while (entries[slot * 14].t.owner != 0) {
        slot++;
        if (slot >= 7)
            return;
    }

    Frame f;
    entries[slot * 14].t.owner = idx;
    flags[slot].a = 0;
    flags[slot].b = 0;
    int bits = tiles[idx - 1].bits;
    for (int shift = 0; shift < 0x1c; shift += 4) {
        int n = (bits >> shift) & 0xf;
        Cfg* c = &f.cfg[shift >> 2];
        if (!(n & 1)) {
            c->on = 0;
        } else {
            c->on = 1;
            if (n & 2) {
                c->a = 39.0f;
                c->b = 8.0f;
                c->c = 1.0f;
                c->d = 2.0f;
            } else {
                c->a = 43.5f;
                c->b = 0;
                c->c = 0;
                c->d = 0;
            }
        }
    }

    f.count = 0;
    FUN_00079990(f.cfg, 0, 3, 2, -1, 1, slot, &f.count, 0, 2);
    FUN_00079990(f.cfg, 1, 3, 4, 1, 1, slot, &f.count, 1, 3);
    FUN_00079c80(f.cfg, 2, 0, 5, -1, 1, slot, &f.count, 2, 0);
    FUN_00079f40(f.cfg, 3, 0, 5, 1, 6, slot, &f.count, 5, 4);
    FUN_00079c80(f.cfg, 4, 1, 6, 1, 1, slot, &f.count, 3, 1);
    FUN_00079990(f.cfg, 5, 3, 2, -1, -1, slot, &f.count, 0, 2);
    FUN_00079990(f.cfg, 6, 3, 4, 1, -1, slot, &f.count, 1, 3);

    f.mat.FUN_0022b980();
    int quot = (idx - 1) / 30;
    int rem = (idx - 1) % 30;
    f.l1c = rem;
    f.l14 = -((rem % 2) != 0) - quot * 2;
    int tileId = tiles[idx].id;
    f.pos.x = (float)f.l14 * 77.9423f;
    f.l14 = tileId;
    f.pos.y = 0;
    f.axis.x = 0;
    f.axis.y = 1.0f;
    f.axis.z = 0;
    f.pos.z = ((float)f.l1c - 0.5f) * -135.0f;
    f.mat.FUN_0022baf0(&f.axis, (float)f.l14 * 1.0472f);
    f.mat.FUN_0022be40(&f.pos);

    if (f.count > 0) {
        Entry* e = &entries[slot * 14];
        f.slotBase = slot * 14;
        for (int k = 0; k < f.count; k++) {
            f.cur = &e->t;
            e->a.FUN_0022d210(&f.mat);
            e->t.b.FUN_0022d210(&f.mat);
            int sgn = ((k % 2) != 0) ? -1 : 1;
            FUN_0007a840(slot, k, &f.l14, &f.l1c);
            f.cur->p = f.l14;
            f.cur->q = f.l1c;
            if (f.l14 != -1 && f.l1c != -1) {
                int sgn2 = ((f.l1c % 2) != 0) ? -1 : 1;
                f.tmp20 = f.l14 * 14;
                Entry* a = &entries[f.tmp20 + sgn2 + f.l1c];
                a->t.p = slot;
                a->t.q = k + sgn;
                Entry* b = &entries[f.tmp20 + f.l1c];
                b->t.p = slot;
                b->t.q = k;
                Entry* c = &entries[f.slotBase + sgn + k];
                c->t.p = f.l14;
                c->t.q = sgn2 + f.l1c;
            }
            e = e + 1;
        }
    }
    for (int j = f.count; j < 14; j++)
        entries[slot * 14 + j].t.on = 0;
}
