// STATUS: equivalent (tools/equiv.py level 3: 20029 inputs, branch coverage 55/56, incomplete)
// FUN_000a5a90 @ 0x000a5a90
// 0xa5a90: character-controller step: slide the position v194 along the ground / walls with sweep tests.
#include "decls/data/game/global.h"
#include "compat/ptr.h"

extern "C" double sqrt(double);
extern "C" double fabs(double);


struct Vec3_a5a90 {
    float x;
    float y;
    float z;
    float FUN_0022d110();
    void FUN_00067930(Vec3_a5a90 *other, float t);
};

struct Sweeper_a5a90 {
    void FUN_00035550(Vec3_a5a90 *out);
    char FUN_00038e30(Vec3_a5a90 *from, Vec3_a5a90 *to, float radius, int flag, Vec3_a5a90 *hit, Vec3_a5a90 *normal);
};

struct Frame_a5a90 {
    float f0;                // S+0
    float f4;                // S+4
    Vec3_a5a90 tmpA;         // S+8
    Vec3_a5a90 vB;           // S+20
    float f32;               // S+32
    Vec3_a5a90 d;            // S+36
    Vec3_a5a90 dir;          // S+48
    Vec3_a5a90 n;            // S+60
    Vec3_a5a90 hit;          // S+72
    Vec3_a5a90 pos;          // S+84
    Vec3_a5a90 saved;        // S+96
    Vec3_a5a90 q;            // S+108
    Vec3_a5a90 r;            // S+120
    Vec3_a5a90 nrm;          // S+132
};

Vec3_a5a90 *__cdecl FUN_0009f7d0(Vec3_a5a90 *out, Vec3_a5a90 *cur, Vec3_a5a90 *dir, float a, float b);
void __cdecl FUN_000a04c0(Vec3_a5a90 *v, float *o1, float *o2, float *o3);

struct Obj_a5a90 {
    char pad000[0x17c];
    Vec3_a5a90 v17c;
    char pad188[0x194 - 0x188];
    Vec3_a5a90 v194;
    char pad1a0[0x1c4 - 0x1a0];
    Vec3_a5a90 v1c4;
    Vec3_a5a90 v1d0;
    char pad1dc[0x244 - 0x1dc];
    char flagA;
    char flagB;
    char pad246[0x254 - 0x246];
    Vec3_a5a90 v254;
    char pad260[0x26c - 0x260];
    Vec3_a5a90 v26c;
    char pad278[0x31c - 0x278];
    char b31c;
    char pad31d[0x320 - 0x31d];
    int mode;
    char pad324[0x349 - 0x324];
    char b349;
    char pad34a[0x34c - 0x34a];
    float f34c;
    Sweeper_a5a90 *sweeper;
    char pad354[0x444 - 0x354];
    float f444;
    char pad448[0x468 - 0x448];
    float f468;
    char pad46c[0x488 - 0x46c];
    float f488;
    char pad48c[0x4a0 - 0x48c];
    Vec3_a5a90 v4a0;

    char FUN_000a2800(unsigned a1, unsigned a2, unsigned a3, unsigned a4, unsigned a5, float p6, float p7,
                      Vec3_a5a90 *pos, Vec3_a5a90 *outV, float *outF);
    void FUN_000a2cc0(float a, float b, float c, float d, int mode);
    void FUN_000a1930(Vec3_a5a90 v, int mode);
    char FUN_000a5a90(unsigned a1, unsigned a2, unsigned a3, unsigned a4, unsigned a5, char a6, float a7);
};

char Obj_a5a90::FUN_000a5a90(unsigned a1, unsigned a2, unsigned a3, unsigned a4, unsigned a5, char a6, float a7)
{
    Frame_a5a90 f;
    Vec3_a5a90 *prev = &v1c4;
    Vec3_a5a90 *dirv = &v1d0;
    Vec3_a5a90 *cur = &v4a0;
    flagA = 0;
    if (mode == 3) {
        sweeper->FUN_00035550(&f.tmpA);
        f.tmpA.FUN_0022d110();
    }
    f.pos = *prev;
    f.dir = *dirv;
    f.f32 = (float)sqrt(f.dir.y * f.dir.y + (f.dir.x * f.dir.x + f.dir.z * f.dir.z));
    f.f0 = (float)sqrt(f.dir.x * f.dir.x + f.dir.z * f.dir.z);
    hulk_freg scale = f.f0 * 0.05f > DAT_0049ecdc ? DAT_0049ecdc / f.f0 : 0.05f;
    f.dir.x = f.dir.x * scale;
    f.dir.y = 0.0f * scale;
    f.dir.z = f.dir.z * scale;
    *cur = *FUN_0009f7d0(&f.tmpA, cur, &f.dir, a7, (*(float*)&DAT_0049ece0));
    f.pos.x = f.pos.x - cur->x;
    f.pos.y = f.pos.y - cur->y;
    f.pos.z = f.pos.z - cur->z;
    cur = &v194;

    if (sweeper->FUN_00038e30(&f.pos, cur, (*(float*)&DAT_0049ecb0), 1, &f.hit, &f.nrm)) {
        *cur = f.hit;
        cur->x = f.nrm.x * f468 + cur->x;
        cur->y = f.nrm.y * f468 + cur->y;
        cur->z = f.nrm.z * f468 + cur->z;
        flagA = 1;
        f.d.x = cur->x - prev->x;
        f.d.y = cur->y - prev->y;
        f.d.z = cur->z - prev->z;
        hulk_freg dist = f.d.FUN_0022d110();
        hulk_freg dot = (f.d.z * dirv->z + f.d.y * dirv->y + f.d.x * dirv->x) * 0.1f;
        hulk_freg c = dot >= -1.0f ? (dot > DAT_0049eca0 ? DAT_0049eca0 : dot) : (dot > DAT_0049eca0 ? DAT_0049eca0 : -1.0f);
        if (dist < DAT_0049eca0 + c && mode != 7 && f488 == 0.0f && f34c == 0.0f &&
            FUN_000a2800(a1, a2, a3, a4, a5, DAT_0049eca0 + 2.0f, f444 + 5.0f, &f.pos, &f.vB, &f.f4)) {
            if (f.f4 > f444) {
                f.vB.FUN_00067930(prev, 1.0f - f444 / f.f4);
                f.f4 = f444;
            }
            if (a6 == 0 && !(f.f32 >= 11.0f)) {
                f.saved.x = f.vB.x - prev->x;
                f.saved.y = f.vB.y - prev->y;
                f.saved.z = f.vB.z - prev->z;
                FUN_000a04c0(&f.saved, &f.f4, &f.f0, &f.f32);
                FUN_000a2cc0(f.f4, f.f0, f.f32, (*(float*)&DAT_0049ec64), mode);
            } else {
                FUN_000a1930(f.vB, mode);
                flagA = f.f4 < f444;
            }
            b349 = 1;
            hulk_freg k = DAT_0049ecac;
            if (mode == 6)
                k = k + k;
            f34c = k;
        }
    }

    f.saved = *cur;
    if (b31c == 0 && flagA == 0) {
        f.d.x = cur->x - v26c.x;
        f.d.y = cur->y - v26c.y;
        f.d.z = cur->z - v26c.z;
    } else {
        f.d.x = v17c.x - v254.x;
        f.d.y = v17c.y - v254.y;
        f.d.z = v17c.z - v254.z;
    }
    flagB = 0;

    hulk_freg sign = f.d.y < 0.0f ? -1.0f : (f.d.y > 0.0f ? 1.0f : 0.0f);
    f.n.x = 0.0f;
    f.n.y = sign;
    f.n.z = 0.0f;
    f.f0 = (float)fabs(f.d.y);
    if (!(f.f0 <= 1e-5f)) {
        f.vB.x = f.n.x * f468;
        f.vB.y = f.n.y * f468;
        f.vB.z = f.n.z * f468;
        f.tmpA.x = f.n.x * f.f0;
        f.tmpA.y = f.n.y * f.f0;
        f.tmpA.z = f.n.z * f.f0;
        f.q.x = cur->x - f.tmpA.x;
        f.q.y = cur->y - f.tmpA.y;
        f.q.z = cur->z - f.tmpA.z;
        f.r.x = f.vB.x + cur->x;
        f.r.y = f.vB.y + cur->y;
        f.r.z = f.vB.z + cur->z;
        if (sweeper->FUN_00038e30(&f.q, &f.r, (*(float*)&DAT_0049ecb0), 1, &f.hit, &f.nrm)) {
            cur->x = f.hit.x - f.vB.x;
            cur->y = f.hit.y - f.vB.y;
            cur->z = f.hit.z - f.vB.z;
            flagB = 1;
        }
    }

    f.n.x = f.d.x;
    f.n.y = 0.0f;
    f.n.z = f.d.z;
    hulk_freg len = f.n.FUN_0022d110();
    f.f0 = (float)fabs(len);
    if (!(f.f0 <= 1e-5f)) {
        f.vB.x = f.n.x * f468;
        f.vB.y = f.n.y * f468;
        f.vB.z = f.n.z * f468;
        f.q.x = cur->x - f.n.x * len;
        f.tmpA.y = f.n.y * len;
        f.tmpA.z = f.n.z * len;
        f.q.y = cur->y - f.tmpA.y;
        f.q.z = cur->z - f.tmpA.z;
        f.r.x = f.vB.x + cur->x;
        f.r.y = f.vB.y + cur->y;
        f.r.z = f.vB.z + cur->z;
        if (sweeper->FUN_00038e30(&f.q, &f.r, (*(float*)&DAT_0049ecb0), 1, &f.hit, &f.nrm)) {
            cur->x = f.hit.x - f.vB.x;
            cur->y = f.hit.y - f.vB.y;
            cur->z = f.hit.z - f.vB.z;
            flagB = 1;
        }
    }

    if (flagB != 0) {
        if (sweeper->FUN_00038e30(&f.pos, cur, (*(float*)&DAT_0049ecb0), 1, &f.hit, &f.nrm)) {
            *cur = f.saved;
            flagB = 0;
        }
    }
    if (flagA != 0 || flagB != 0)
        return 1;
    return 0;
}
