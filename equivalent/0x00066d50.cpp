// STATUS: equivalent (tools/equiv.py level 3: 218 inputs, branch coverage 36/36)
// FUN_00066d50 @ 0x00066d50
struct Vec3_66d50 {
    float x, y, z;
    float FUN_0022d110();
};

struct Anchor_66d50 {
    void FUN_00059a50(Vec3_66d50* out);
};

struct Entity {
    char pad00[0x10];
    Anchor_66d50* anchor;
    char pad14[0x1b0c - 0x14];
    float f1b0c;
    char pad1b10[0x1b38 - 0x1b10];
    int f1b38;
    char pad1b3c[4];
    int f1b40;
    int f1b44;
};

struct Registry_66d50 {
    Entity* FUN_00024280(unsigned int lo, unsigned int hi);
};

struct Globals_66d50 {
    char pad00[0x20];
    Registry_66d50* registry;
};

extern Globals_66d50* DAT_004dd700;

struct Handle_66d50 {
    int a, b;
};

struct Query_66d50 {
    int out;
    int pad;
    unsigned int lo;
    unsigned int hi;
};

struct Sub_66d50 {
    void FUN_00230f50(void (*fn)(), Sub_66d50* self);
    void FUN_00066a90(Handle_66d50* h, Query_66d50* q);
};

struct Id_66d50 {
    unsigned int lo;
    unsigned int hi;
};

void FUN_00066930();
void __cdecl FUN_000658d0(Vec3_66d50* a, Vec3_66d50* b, Vec3_66d50* c, int* out);

class Tracker_66d50 {
public:
    char pad00[0x10];
    Id_66d50 ids[1];
    char pad18[0x150 - 0x18];
    int count;
    Vec3_66d50 center;
    Vec3_66d50 v160;
    char pad16c[0x2d8 - 0x16c];
    Sub_66d50 sub;
    char pad2dc[0x370 - 0x2dc];
    float f370;
    float f374;
    void FUN_00066d50();
};

void Tracker_66d50::FUN_00066d50()
{
    struct Frame {
        int out;
        Handle_66d50 h;
        Vec3_66d50 pos;
        Vec3_66d50 w;
        Query_66d50 q;
    } f;
    f.w.x = 0.0f;
    f.w.y = 0.0f;
    f.w.z = 0.0f;
    sub.FUN_00230f50(FUN_00066930, &sub);
    Entity* best = 0;
    float bestDist = 0.0f;
    if (count <= 0)
        return;
    int i;
    for (i = 0; i < count; i++) {
        Entity* e = DAT_004dd700->registry->FUN_00024280(ids[i].lo, ids[i].hi);
        if (e != 0 && !(e->f1b0c < 0.0f)) {
            e->anchor->FUN_00059a50(&f.pos);
            f.pos.x = f.pos.x - center.x;
            f.pos.y = 0.0f;
            f.pos.z = f.pos.z - center.z;
            float dist = f.pos.FUN_0022d110();
            if (best == 0 || dist < bestDist) {
                bestDist = dist;
                best = e;
            }
        } else {
            for (int k = i + 1; k < count; k++) {
                ids[k - 1].lo = ids[k].lo;
                ids[k - 1].hi = ids[k].hi;
            }
            count = count - 1;
            i--;
        }
    }
    if (best == 0)
        return;
    best->anchor->FUN_00059a50(&v160);
    if (count <= 0)
        return;
    for (i = 0; i < count; i++) {
        Entity* e = DAT_004dd700->registry->FUN_00024280(ids[i].lo, ids[i].hi);
        e->anchor->FUN_00059a50(&f.w);
        if (!(e->f1b0c < 0.0f)) {
            f.pos.x = f.w.x;
            f.pos.z = f.w.z;
            f.pos.y = f.w.y;
            f.pos.x = f.pos.x - center.x;
            f.pos.y = 0.0f;
            f.pos.z = f.pos.z - center.z;
            float dist = f.pos.FUN_0022d110();
            if (dist < f374 && dist > f370 && (e->f1b40 | e->f1b44) != 0) {
                FUN_000658d0(&f.w, &center, &v160, &f.out);
                f.q.out = f.out;
                f.q.lo = ids[i].lo;
                f.q.hi = ids[i].hi;
                sub.FUN_00066a90(&f.h, &f.q);
                if (e == best)
                    e->f1b38 = 0;
                else
                    e->f1b38 = f.out;
            }
        } else {
            for (int k = i + 1; k < count; k++) {
                ids[k - 1].lo = ids[k].lo;
                ids[k - 1].hi = ids[k].hi;
            }
            count = count - 1;
            i--;
        }
    }
}
