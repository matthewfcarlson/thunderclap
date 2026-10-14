// STATUS: equivalent (tools/equiv.py level 3: 117 inputs, branch coverage 26/28, incomplete)
// hulkfight::motion::GrappleStruggleAction::vfunc_5 @ 0x00147bb0
struct Source_147bb0 {
    char pad[0x334];
    Source_147bb0* a334;
    Source_147bb0* b338;
    char pad2[0x1e58 - 0x33c];
    float value;
    int valueSet;
    char pad3[0x1f58 - 0x1e60];
    int flagA;
    char pad4[0x1f7c - 0x1f5c];
    int flagB;
    char pad5[0x20a8 - 0x1f80];
    int limitIndex;
};

struct Node { Source_147bb0* FUN_00059a30(); };
struct Owner_147bb0 { Node* FUN_000592a0(); };

class Config_147bb0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float v6();
    char pad[0x14 - 4];
    float f14;
    float f18;
    float f1c;
    float f20;
};

class GrappleStruggleAction {
public:
    bool run(int mode, float dt);
    char p0[0x1c];
    Config_147bb0* cfg;
    Owner_147bb0* owner;
    float elapsed;
};

bool GrappleStruggleAction::run(int mode, float dt)
{
    Source_147bb0* s = owner->FUN_000592a0()->FUN_00059a30();

    if (mode == 1) {
        if (s->a334 != 0) {
            Source_147bb0* from = s->b338;
            if (from == 0)
                from = s->a334;
            s->value = from->value;
            s->valueSet = 1;
        }
        if (s->b338 == 0)
            return true;
    } else if (mode == 0) {
        if (s->b338 != 0) {
            s->value = s->b338->value;
            s->valueSet = 1;
        }
        if (s->a334 == 0)
            return true;
    } else {
        return true;
    }

    float base = s->value;
    float r = ((cfg->f1c - cfg->f18) * base + cfg->f18) * dt;
    elapsed = dt + elapsed;
    if (s->limitIndex >= 0) {
        float lim = cfg->f14;
        if (lim - cfg->v6() < elapsed) {
            int flag = 0;
            if (s->flagA == 1 || s->flagB == 1)
                flag = 1;
            r = flag * cfg->f20 * dt + r;
        }
    }
    s->valueSet = 1;
    s->value = r + base;
    return true;
}
