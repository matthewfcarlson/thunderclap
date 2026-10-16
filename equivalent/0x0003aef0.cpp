// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 21/22, incomplete)
// FUN_0003aef0 @ 0x0003aef0
#include "decls/address.h"
extern "C" double sqrt(double);

struct V3_3aef0 {
    float x, y, z;
    float FUN_0022d110();
};

struct Weapon_3aef0;

struct Body_3aef0 {
    char pad0[8];
    Weapon_3aef0* link;               // 0x8
    int kind;                   // 0xc
    char pad10[0x40 - 0x10];
    V3_3aef0 pos;                     // 0x40
    char pad4c[0x50 - 0x4c];
    V3_3aef0 vel;                     // 0x50
    V3_3aef0 push;                    // 0x5c
};

struct Weapon_3aef0 {
    char pad0[0xec];
    int fec;                    // 0xec
    char pad0f0[0x1ed - 0xf0];
    char pending;               // 0x1ed
    Body_3aef0* FUN_001d72e0();
    void FUN_001d6cc0(float v);
    void FUN_001d7510();
    void FUN_001d81b0(V3_3aef0* v, int flag);
    void FUN_001d71e0(int v);
};

struct Slot_3aef0 {
    Weapon_3aef0* weapon;
    char pad04[0x50 - 4];
};

struct Cam_3aef0 { bool FUN_00059a50(V3_3aef0* out); };

struct Bank { int FUN_000446c0(int index); };

struct Mgr_3aef0 { void FUN_0027ffb0(void* arg); };
Mgr_3aef0* __cdecl FUN_0027f250();

struct Inventory_3aef0 { void FUN_001e5bb0(Weapon_3aef0* w, int flag); };
struct World {
    char pad0[0xc];
    Inventory_3aef0* inv;             // 0xc
};

class Actor_3aef0 {
public:
    char pad00[0x10];
    Cam_3aef0* cam;                   // 0x10
    char pad14[0x11c - 0x14];
    Bank* bank;                 // 0x11c
    char pad120[0x3a8 - 0x120];
    Slot_3aef0 slots[8];
    char pad628[0x1d84 - 0x628];
    void* ptrs[0x20];           // 0x1d84
    void FUN_0003acf0(int a, int b, int c, int d, int e, int f);
    char FUN_0003aef0(int index);
};

char Actor_3aef0::FUN_0003aef0(int index)
{
    if (index < 0 || index >= 8)
        return 0;

    Weapon_3aef0* weapon = slots[index].weapon;
    Body_3aef0* body = 0;
    if (weapon) {
        body = weapon->FUN_001d72e0();
        if (weapon->pending) {
            Mgr_3aef0* mgr = FUN_0027f250();
            unsigned int k = index + 0x14;
            void* arg;
            if (k < 0x20)
                arg = ptrs[k];
            else
                arg = 0;
            mgr->FUN_0027ffb0(arg);
            weapon->pending = 0;
        }
        weapon->FUN_001d6cc0(2.0f);
    }
    FUN_0003acf0(index, 0, -1, 0, 0, 0);

    if (weapon && bank) {
        int cur = weapon->fec;
        if (cur == bank->FUN_000446c0(index)) {
            DAT_004dd700->inv->FUN_001e5bb0(weapon, 1);
            return 1;
        }
    }
    if (body == 0)
        return 0;

    V3_3aef0 dir = body->pos;
    V3_3aef0 camPos;
    camPos.x = 0.0f;
    camPos.y = 0.0f;
    camPos.z = 0.0f;
    cam->FUN_00059a50(&camPos);
    dir.x = dir.x - camPos.x;
    dir.y = dir.y - camPos.y;
    dir.z = dir.z - camPos.z;
    dir.FUN_0022d110();
    float savedY = dir.y;
    dir.y = 0.0f;
    dir.FUN_0022d110();
    dir.y = savedY;
    dir.FUN_0022d110();
    dir.x = dir.x * 5.0f;
    dir.y = dir.y * 5.0f;
    dir.z = dir.z * 5.0f;

    if (body->kind == 5) {
        Weapon_3aef0* link = body->link;
        link->FUN_001d7510();
        link->FUN_001d81b0(&dir, 1);
        link->FUN_001d71e0(0);
    }

    float wz = body->vel.z;
    float wy = body->vel.y;
    float wx = body->vel.x;
    double len = sqrt(wz * wz + wy * wy + wx * wx);
    if (len > 8.0f) {
        float eight = 8.0f;
        double s = eight / len;
        body->vel.z = (float)(wz * s);
        body->vel.x = (float)(wx * s);
        body->vel.y = (float)(wy * s);
    }
    body->push.z = 0.0f;
    body->push.y = 0.0f;
    body->push.x = 0.0f;
    return 1;
}
