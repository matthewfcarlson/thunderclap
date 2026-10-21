// STATUS: equivalent (tools/equiv.py level 3: 8244 inputs, branch coverage 47/50, incomplete)
// FUN_0029df90 @ 0x0029df90
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "compat/ptr.h"
struct V3 {
    float x, y, z;
};

namespace pure3d {
class Entity {
public:
    virtual void v0();
};

class Light : public Entity {
public:
    virtual void v1();
};

class DirectionalLight : public Light {
public:
    char pad04[0x13 - 4];
    char flag13;
    char pad14[0x68 - 0x14];
    DirectionalLight *FUN_002a2e70();
    void FUN_002a07a0(unsigned int color);
    void FUN_002a2fc0(V3 *v);
};
}

struct Group {
    char pad0[0x10];
    int size;                   // 0x10
    int count;                  // 0x14
    pure3d::Light **items;      // 0x18
    void FUN_002a0fc0(int index, pure3d::Light *light);
};

struct Entry {
    float weight;               // 0x00
    unsigned int color;         // 0x04
    char pad08[4];
    V3 dir;                     // 0x0c
    unsigned int flags;         // 0x18
    char pad1c[4];
};

struct Slots {
    void FUN_002a1180(int n);
};

struct Table {
    Slots *slots;
    Entry *entries;             // 0x04
    void FUN_0029c660();
};

union Arg2 {
    float *rgb;
    float scale;
};

union Arg3 {
    int mode;
    char flag;
};

void *thunk_FUN_0008d690(unsigned int size);

class Manager {
public:
    char pad0[0x40];
    Table *table;               // 0x40
    float FUN_0029dcc0(int mode, int n);
    float FUN_0029dd30(Table *t);
    void FUN_0029df90(Group *group, Arg2 a2, Arg3 a3);
};

void Manager::FUN_0029df90(Group *group, Arg2 a2, Arg3 a3)
{
    int count = group->count;
    table->FUN_0029c660();
    table->slots->FUN_002a1180(count + 1);
    hulk_freg k = FUN_0029dcc0(a3.mode, 0x10);
    float *rgb = a2.rgb;
    hulk_freg a = rgb[0] < 0.0f ? rgb[0] : 0.0f;
    hulk_freg b = rgb[1] < 0.0f ? rgb[1] : 0.0f;
    hulk_freg c = rgb[2] < 0.0f ? rgb[2] : 0.0f;
    hulk_freg m = (c + b + a) * 0.333f;
    a2.scale = 1.0f;
    a3.flag = 0;
    if (k > 0.0f && m < -0.0001f) {
        a3.flag = 1;
        double t = (m + k) / k;
        a2.scale = (float)t;
        if (t < 0.0)
            a2.scale = 0.0f;
    }
    hulk_freg ret = FUN_0029dd30(table);
    Entry *first = &table->entries[count];
    double total = (k - ret) + first->weight;
    int ival = 0;
    if (first->weight > 0.0f) {
        double prod = total * 0.33f;
        double v = prod;
        if (first->weight > prod)
            v = first->weight;
        ival = (int)(v * a2.scale);
        hulk_freg d = (float)ival;
        rgb[0] = d + rgb[0];
        rgb[1] = d + rgb[1];
        rgb[2] = d + rgb[2];
    }
    for (int i = 0; i < count; i++) {
        if ((int)table->entries[i].weight - ival <= 0) {
            group->FUN_002a0fc0(i, 0);
            continue;
        }
        pure3d::Light *item = 0;
        if (i < group->size)
            item = group->items[i];
        pure3d::DirectionalLight *light = dynamic_cast<pure3d::DirectionalLight *>(item);
        if (light == 0) {
            void *mem = thunk_FUN_0008d690(0x68);
            if (mem != 0)
                light = ((pure3d::DirectionalLight *)mem)->FUN_002a2e70();
            else
                light = 0;
            group->FUN_002a0fc0(i, light);
        }
        unsigned int raw = table->entries[i].color;
        if (a3.flag) {
            int r = (int)((float)((raw >> 16) & 0xff) * a2.scale);
            unsigned int col = 0xffffff00 | r;
            col <<= 8;
            int g = (int)((float)((raw >> 8) & 0xff) * a2.scale);
            col |= g;
            col <<= 8;
            int bl = (int)((float)(raw & 0xff) * a2.scale);
            col |= bl;
            raw = col;
        }
        int cb = (int)(raw & 0xff) - ival;
        int cg = (int)((raw >> 8) & 0xff) - ival;
        int cr = (int)((raw >> 16) & 0xff) - ival;
        if (cb < 0)
            cb = 0;
        else if (cb > 0xff)
            cb = 0xff;
        if (cg < 0)
            cg = 0;
        else if (cg > 0xff)
            cg = 0xff;
        if (cr < 0)
            cr = 0;
        else if (cr > 0xff)
            cr = 0xff;
        unsigned int out = 0xffffff00 | cr;
        out <<= 8;
        out |= cg;
        out <<= 8;
        out |= cb;
        light->FUN_002a07a0(out);
        V3 dir = table->entries[i].dir;
        light->FUN_002a2fc0(&dir);
        light->flag13 = (table->entries[i].flags & 8) == 8;
    }
}
