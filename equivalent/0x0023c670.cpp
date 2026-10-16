// STATUS: equivalent (tools/equiv.py level 3: 134 inputs, branch coverage 38/38)
// fight::Bank::vfunc_8 @ 0x0023c670
#include "gen/fight.h"

struct Node_23c670 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual Node_23c670 *v8(void *ctx, float *weight);
    char pad04[0x10 - 4];
    int kind;
    char pad14[0x20 - 0x14];
    Node_23c670 *next;
    Node_23c670 *FUN_0023c300();
};

float __cdecl FUN_00238350(void *ctx);

struct Bank_nv_23c670 {
    bool FUN_002333f0(void *ctx, int b);
};

unsigned int fight::Bank::vfunc_8(unsigned int __p0, unsigned int __p1) { void * ctx = (void *)__p0; int b = (int)__p1;

    if (!((Bank_nv_23c670*)this)->FUN_002333f0(ctx, b))
        return (unsigned int)(0);

    float sum = 0.0f;
    for (Node_23c670 *n = (*(Node_23c670 * *)&this->f_1c); n; n = n->next) {
        if (n->kind == 2)
            continue;
        if (n->kind == 4) {
            Node_23c670 *inner = n->FUN_0023c300();
            if (!inner || inner->kind == 2)
                continue;
        }
        float w = 0.0f;
        Node_23c670 *hit = n->v8(ctx, &w);
        if (!hit)
            continue;
        if (!(w > 0.0f))
            return (unsigned int)(hit);
        sum = w + sum;
    }
    if (sum <= 0.0f)
        return (unsigned int)(0);

    float target = FUN_00238350(ctx) * sum;
    float acc = 0.0f;
    for (Node_23c670 *n = (*(Node_23c670 * *)&this->f_1c); n; n = n->next) {
        if (n->kind == 2)
            continue;
        if (n->kind == 4) {
            Node_23c670 *inner = n->FUN_0023c300();
            if (!inner || inner->kind == 2)
                continue;
        }
        float w = 0.0f;
        Node_23c670 *hit = n->v8(ctx, &w);
        if (!hit)
            continue;
        if (!(w > 0.0f))
            continue;
        acc = w + acc;
        if (target <= acc)
            return (unsigned int)(hit);
    }
    return (unsigned int)(0);
}
