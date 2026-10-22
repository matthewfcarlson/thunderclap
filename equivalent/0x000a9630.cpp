// STATUS: equivalent (tools/equiv.py level 3: 186 inputs, branch coverage 24/24)
// FUN_000a9630 @ 0x000a9630
// cl-flags: /GS
#include "decls/data/game/global.h"
#include "compat/ptr.h"

extern "C" double sqrt(double);


struct Sphere_a9630 {
    float x, y, z, radius;
};
struct Effect_a9630 {
    void FUN_001c5130(float a, float b);
};
struct SubObj_a9630 {
    char pad[0x11c];
    Effect_a9630* effect;
};
struct Attach_a9630 {
    char pad[0x10];
    Effect_a9630* effect;
};
struct Item_a9630 {
    char pad[0x124];
    Attach_a9630* attach;
    bool FUN_000359e0(Sphere_a9630* out);
    SubObj_a9630* FUN_00035ef0(int index);
};
struct List_a9630 {
    char pad[0xc];
    int count;
    Item_a9630* FUN_00024190(int index);
    bool FUN_00024300(Item_a9630* item);
    bool FUN_000242d0(Item_a9630* item);
};
struct Holder_a9630 {
    char pad[0x20];
    List_a9630* list;
};
struct Vec3_a9630 {
    float x, y, z;
};
struct Camera {
    char pad[0x30];
    Vec3_a9630 pos;
};
class Manager_a9630 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual Camera* vfunc_14();
    void FUN_000a9630(Holder_a9630* holder);
};
void Manager_a9630::FUN_000a9630(Holder_a9630* holder) {
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    int count = holder->list->count;
    for (int i = 0; i < count; i++) {
        Item_a9630* item = holder->list->FUN_00024190(i);
        if (!item)
            continue;
        if (holder->list->FUN_00024300(item))
            continue;
        Sphere_a9630 s;
        if (!item->FUN_000359e0(&s))
            continue;
        Camera* cam = vfunc_14();
        Vec3_a9630 c = cam->pos;
        hulk_freg dx = s.x - c.x;
        hulk_freg dy = s.y - c.y;
        hulk_freg dz = s.z - c.z;
        double dist = sqrt((double)(dy * dy + dz * dz + dx * dx));
        if (!(dist < s.radius))
            continue;
        hulk_freg a = (*(const float*)&DAT_004218a8);
        hulk_freg b = (*(const float*)&DAT_004218b8);
        if (holder->list->FUN_000242d0(item)) {
            a = (*(const float*)&DAT_004218ac);
            b = (*(const float*)&DAT_004218bc);
        }
        if (item->attach && item->attach->effect)
            item->attach->effect->FUN_001c5130(a, b);
        for (int j = 0; j < 8; j++) {
            SubObj_a9630* sub = item->FUN_00035ef0(j);
            if (sub && sub->effect)
                sub->effect->FUN_001c5130(a, b);
        }
    }
}
