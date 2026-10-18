// FUN_000af8e0 @ 0x000af8e0
#include "decls/data/game/global.h"

class Voice_af8e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual float v5();
    virtual void v6(float value);
};

class Emitter_af8e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual Voice_af8e0 *v16(int slot);
};

struct Entry_af8e0 {
    char pad00[0x0d];
    char skip;          // 0x0d
    char pad0e[2];
    int value;          // 0x10
};

struct EntryList_af8e0 {
    Entry_af8e0 *FUN_000ace20(int index);
};

struct Group_af8e0 {
    unsigned int count;     // 0x00
    char pad04[8];
    float timer[2];         // 0x0c
    float level[2];         // 0x14
    float decay[2];         // 0x1c
    float limit[2];         // 0x24
    Emitter_af8e0 *emitter;       // 0x2c
};

class Mixer {
public:
    char pad00[8];
    bool enabled;           // 0x08
    char pad09[3];
    EntryList_af8e0 *entries;     // 0x0c
    int groupCount;         // 0x10
    Group_af8e0 *groups;          // 0x14
    int ticks;              // 0x18

    void FUN_000af700(int index, int value);
    void FUN_000af530(int index, int slot, int flag);
    void FUN_000af8e0(float dt);
};

void Mixer::FUN_000af8e0(float dt)
{
    ticks++;
    if (!enabled)
        return;

    for (int i = 0; i < groupCount; i++) {
        if (entries->FUN_000ace20(i)->skip != 0) {
            FUN_000af700(i, 0);
            continue;
        }
        FUN_000af700(i, entries->FUN_000ace20(i)->value);

        for (unsigned int j = 0; j < groups[i].count; j++) {
            Group_af8e0 *g = groups;
            if (g[i].timer[j] > 0.0f) {
                g[i].timer[j] = g[i].timer[j] - dt;
                if ((*(bool*)&DAT_004dda3d)) {
                    g = groups;
                    float *level = &g[i].level[j];
                    float *limit = &g[i].limit[j];
                    float *decay = &g[i].decay[j];
                    Voice_af8e0 *v = g[i].emitter->v16(j);
                    if (v->v5() > 0.0f) {
                        float d = dt + *decay;
                        *decay = d;
                        if (d > 0.05f) {
                            *decay = 0.0f;
                            groups[i].emitter->v16(j)->v6(0.0f);
                        }
                    }
                    float l = dt + *level;
                    *level = l;
                    if (l > *limit * 0.001f) {
                        groups[i].emitter->v16(j)->v6(1.0f);
                        *level = 0.0f;
                        *decay = 0.0f;
                    }
                }
            } else {
                if ((*(bool*)&DAT_004dda3d))
                    g[i].emitter->v16(j)->v6(0.0f);
                groups[i].timer[j] = 0.0f;
                FUN_000af530(i, j, 0);
            }
        }
    }
}
