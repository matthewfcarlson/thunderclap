// STATUS: equivalent (tools/equiv.py level 3: 1287 inputs, branch coverage 22/22)
// FUN_0003e2a0 @ 0x0003e2a0
#include "decls/data/game/hulkfight.h"

struct Vec3_3e2a0 {
    float x, y, z;
};

struct Mat_3e2a0 {
    float m[12];
    Vec3_3e2a0 t;
    float w;
};

struct Anchor_3e2a0 {
    void FUN_00059a50(Vec3_3e2a0* out);
};

struct Target_3e2a0 {
    void FUN_001c5080(float a, float b);
};

struct MatSource_3e2a0 {
    char pad00[0x10];
    Target_3e2a0* target;
    Mat_3e2a0* FUN_001c5e60();
    void FUN_001c5e40(Mat_3e2a0* m);
};

struct PosSource_3e2a0 {
    char pad00[0x11c];
    Target_3e2a0* target;
    Vec3_3e2a0* FUN_001d6b40();
    void FUN_001d7810(Vec3_3e2a0 v);
    void FUN_001d8fc0(float f);
};

struct MatList {
    char pad00[0xc];
    int count;
    char pad10[0x1c - 0x10];
    Mat_3e2a0* data;
};


class CCharacter_3e2a0 {
public:
    char pad00[0x10];
    Anchor_3e2a0* anchor;
    char pad14[0x120 - 0x14];
    MatList* mats;
    MatSource_3e2a0* matSource;
    PosSource_3e2a0* posSource;
    char pad12c[0x20b0 - 0x12c];
    int mode;
    void FUN_00035250(Vec3_3e2a0* v);
    void FUN_0003ba60(int a, float b);
    void FUN_000365f0(int a, float b);
    void FUN_0003e2a0(int a, Vec3_3e2a0 off, float scale, int unused, bool enable);
};

void CCharacter_3e2a0::FUN_0003e2a0(int a, Vec3_3e2a0 off, float scale, int unused, bool enable)
{
    if (!enable)
        return;
    if (scale <= 0.0f)
        return;

    Vec3_3e2a0 pos;
    Mat_3e2a0 m;

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
        Target_3e2a0* t;
        if (matSource)
            t = matSource->target;
        else
            t = posSource->target;
        if (t)
            t->FUN_001c5080((*(float*)&DAT_00421894), 1.5f);
    }

    FUN_0003ba60(a, scale);
    FUN_000365f0(a, scale);
}
