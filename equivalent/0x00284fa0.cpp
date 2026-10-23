// STATUS: equivalent (tools/equiv.py level 3: 287 inputs, branch coverage 22/22)
// pure3d::BlendFrameController::vfunc_6 @ 0x00284fa0
#include "compat/ptr.h"
struct Owner_284fa0 {
    char pad00[0x14];
    float rate;
    char pad18;
    float FUN_00289db0(void* a0, void* a1, float cur, float dt, int a4, int a5, char noFlag, int a7);
};

struct Track {
    float cur;
    int a4;
    int a8;
    float remain;
    float fadeRate;
    float weight;
    int f18;
    int f1c;
    int a20;
    int f24;
    Owner_284fa0* owner;
};

class BlendFrameController {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void vfunc_6(float dt, char force);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    char pad04[0xc];
    char busy;
    char pad11[7];
    float timeScale;
    char pad1c[0xc];
    unsigned int count;
    Track tracks[1];
    char pad58[0x108 - 0x2c - sizeof(Track)];
    char dirty;
};

void BlendFrameController::vfunc_6(float dt, char force)
{
    hulk_freg scaled = dt * timeScale;
    dt = (float)scaled;                        // the callee gets the rounded value
    float step = scaled * 0.001f;              // the original multiplies the unrounded one
    unsigned int done = 1;
    dirty = 0;

    for (unsigned int i = 0; i < count; i++) {
        Track* t = &tracks[i];
        Owner_284fa0* owner = t->owner;
        t->cur = owner->FUN_00289db0(&t->f18, &t->f24, t->cur, dt, t->a4, t->a8, t->f1c == 0, t->a20);

        float x = t->remain - step * owner->rate;
        t->remain = x;
        if (x > 0.0f) {
            float y = 1.0f - x * t->fadeRate;
            if (y <= 0.0f) {
                t->weight = 0.0f;
                done++;
            } else if (y >= 1.0f) {
                t->weight = 1.0f;
                done++;
            } else {
                t->weight = (3.0f - (y + y)) * y * y;
                done++;
            }
        } else {
            t->weight = 1.0f;
        }
    }

    while (done < count) {
        v29();
        dirty = 1;
    }

    if (count != 0) {
        if (busy == 1 || force == 1)
            v7();
    }
}
