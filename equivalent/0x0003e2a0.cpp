// STATUS: equivalent (tools/equiv.py level 3: 380 inputs, branch coverage 22/22)
// FUN_0003e2a0 @ 0x0003e2a0
struct Vec3 {
    float x, y, z;
};

struct Mat {
    float m[12];
    Vec3 t;
    float w;
};

struct Anchor {
    void FUN_00059a50(Vec3* out);
};

struct Target {
    void FUN_001c5080(float a, float b);
};

struct MatSource {
    char pad00[0x10];
    Target* target;
    Mat* FUN_001c5e60();
    void FUN_001c5e40(Mat* m);
};

struct PosSource {
    char pad00[0x11c];
    Target* target;
    Vec3* FUN_001d6b40();
    void FUN_001d7810(Vec3 v);
    void FUN_001d8fc0(float f);
};

struct MatList {
    char pad00[0xc];
    int count;
    char pad10[0x1c - 0x10];
    Mat* data;
};

extern float DAT_00421894;

class Actor {
public:
    char pad00[0x10];
    Anchor* anchor;
    char pad14[0x120 - 0x14];
    MatList* mats;
    MatSource* matSource;
    PosSource* posSource;
    char pad12c[0x20b0 - 0x12c];
    int mode;
    void FUN_00035250(Vec3* v);
    void FUN_0003ba60(int a, float b);
    void FUN_000365f0(int a, float b);
    void FUN_0003e2a0(int a, Vec3 off, float scale, int unused, bool enable);
};

void Actor::FUN_0003e2a0(int a, Vec3 off, float scale, int unused, bool enable)
{
    if (!enable)
        return;
    if (scale <= 0.0f)
        return;

    Vec3 pos;
    Mat m;

    off.x = off.x * scale;
    off.y = off.y * scale;
    off.z = off.z * scale;
    anchor->FUN_00059a50(&pos);
    pos.x = pos.x + off.x;
    pos.y = pos.y + off.y;
    pos.z = pos.z + off.z;
    FUN_00035250(&pos);

    if (matSource) {
        m = *matSource->FUN_001c5e60();
        m.t.x = m.t.x + off.x;
        m.t.y = m.t.y + off.y;
        m.t.z = m.t.z + off.z;
        matSource->FUN_001c5e40(&m);
    } else if (posSource) {
        pos = *posSource->FUN_001d6b40();
        pos.x = pos.x + off.x;
        pos.y = pos.y + off.y;
        pos.z = pos.z + off.z;
        posSource->FUN_001d7810(pos);
        posSource->FUN_001d8fc0(scale * 1000.0f);
    } else {
        return;
    }

    MatList* list = mats;
    int n = list->count;
    for (int i = 0; i < n; i++) {
        m = list->data[i];
        m.t.x = m.t.x + off.x;
        m.t.y = m.t.y + off.y;
        m.t.z = m.t.z + off.z;
        list->data[i] = m;
    }

    if (mode == 1) {
        Target* t;
        if (matSource)
            t = matSource->target;
        else
            t = posSource->target;
        if (t)
            t->FUN_001c5080(DAT_00421894, 1.5f);
    }

    FUN_0003ba60(a, scale);
    FUN_000365f0(a, scale);
}
