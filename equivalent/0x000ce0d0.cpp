// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 27/32, incomplete)
// FUN_000ce0d0 @ 0x000ce0d0
#include "decls/data/game/global.h"

struct Obj218 {
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
};

struct Target_ce0d0 {
    char pad0[0x218];
    Obj218* obj;
    char* target;      // 0x21c, float at +0xc
    float level;       // 0x220
    char fading;       // 0x224
    char pad225[3];
    int f228;
    int f22c;
    float f230;
    char pad234[4];
    int alpha;         // 0x238
    float elapsed;     // 0x23c
    float limit;       // 0x240

    void Update(float dt);
};

static float clamp01(float v)
{
    if (v >= 0.0f && v <= 1.0f) return v;
    if (v > 1.0f) return 1.0f;
    return 0.0f;
}

void Target_ce0d0::Update(float dt)
{
    elapsed = dt + elapsed;
    if (fading) {
        if (limit > 0.0f) {
            if (elapsed > limit) fading = 0;
        }
    }
    if (fading) {
        level = clamp01(level - DAT_0049fd10);
        f230 = f230 + 0.1f;
    } else {
        level = clamp01(DAT_0049fd10 + level);
        f230 = f230 - 0.1f;
    }
    *(float*)(target + 0xc) = level;
    alpha = (int)((1.0f - level) * 255.0f);
    if (alpha > 255) alpha = 255;
    else if (alpha < 0) alpha = 0;
    if (!fading) {
        float d = level - 1.0f;
        if (d < 0.0f) d = -d;
        if (d <= 1e-05f) {
            if (obj) {
                obj->v14();
                if (obj) {
                    obj->v1();
                    obj = 0;
                }
            }
            f228 = 0;
            f22c = 0;
        }
    }
}
