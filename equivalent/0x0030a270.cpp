// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 16/16)
// FUN_0030a270 @ 0x0030a270
#include "decls/data/engine/physics.h"

extern "C" double sqrt(double);
union FloatBits_30a270 {
    float f;
    int i;
};

struct Vec3_30a270 {
    float x, y, z;
};

struct Row_30a270 {
    char pad00[0x18];
    float limit;
};

struct Mgr220 {
    char pad00[0x10];
    Row_30a270 *rows;
};

class Node;

struct Context {
    char pad00[0x218];
    Node *active;
    char pad21c[4];
    Mgr220 *table;
};


class Node {
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
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16(Vec3_30a270 *in, Vec3_30a270 *out);
    char pad04[8 - 4];
    int index;
    char pad0c[0x18 - 0xc];
    Context *ctx;
    Node *parent;
    char pad20[0xd4 - 0x20];
    Vec3_30a270 origin;
    char pade0[0xe4 - 0xe0];
    float radius;
    float weight;
    char flagEC;
    char flagED;
    char flagEE;
    int FUN_0030a270(Vec3_30a270 *pos, Vec3_30a270 *dir);
};

int Node::FUN_0030a270(Vec3_30a270 *pos, Vec3_30a270 *dir)
{
    weight = 0.0f;
    flagEE = 0;
    flagEC = 0;
    if (this != ctx->active) {
        if (radius > 0.0f) {
            Vec3_30a270 d;
            d.x = pos->x - origin.x;
            d.y = pos->y - origin.y;
            d.z = pos->z - origin.z;
            vfunc_16(&d, &d);
            float len = (float)sqrt(d.z * d.z + d.y * d.y + d.x * d.x);
            if (len > DAT_004d3178 * ctx->table->rows[index].limit) {
                d.x = d.x * (1.0f / len);
                d.y = d.y * (1.0f / len);
                d.z = d.z * (1.0f / len);
                if (parent && parent == ctx->active) {
                    weight = 1.0f;
                } else {
                    float dot = d.z * dir->z + d.y * dir->y + d.x * dir->x;
                    FloatBits_30a270 u;
                    u.f = dot;
                    u.i &= 0x7fffffff;
                    if (u.f >= DAT_004d317c)
                        weight = 0.0f;
                    else
                        weight = radius;
                }
            }
        }
        if (parent)
            parent->FUN_0030a270(pos, dir);
    }
    int r = (weight == 0.0f);
    flagED = (char)r;
    return r;
}
