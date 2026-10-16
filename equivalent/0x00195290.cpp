// STATUS: equivalent (tools/equiv.py level 3: 3028 inputs, branch coverage 34/42, incomplete)
// FUN_00195290 @ 0x00195290
#include "decls/address.h"
#include "decls/data/engine/physics.h"
#include "decls/data/game/global.h"
extern "C" double sqrt(double);

struct V3_195290 {
    float x, y, z;
    float FUN_0022d110();
};

struct Ent_195290;

struct Shape_195290 {
    char pad0[8];
    Ent_195290 *ent;           // 8
    int kind;           // 0xc
};

struct Node {
    char pad0[0x18];
    Shape_195290 *shape;
};

struct Rec_195290 {
    float t;
    Node *node;
    float c;
};

struct HitList_195290 {
    int count;
    char pad4[4];
    Rec_195290 *recs;          // 8
};

struct Ent_195290 {
};

struct Probe_195290 {
    char pad0[0x128];
    Ent_195290 *ent128;
    void FUN_000368d0(int v);
    void FUN_00035fa0(int v);
    Ent_195290 *FUN_00035ef0(int i);
    bool FUN_00035c30(Shape_195290 *s);
    void FUN_00035c70(Shape_195290 *s);
};

struct Handle_195290 {
    char pad0[8];
    Probe_195290 *probe;       // 8
    int kind;           // 0xc
};

struct Scene_195290 {
    bool FUN_002ee140(HitList_195290 *list, V3_195290 *origin, V3_195290 *end, int z);
};

struct Caster_195290 {
    bool FUN_00201e00(V3_195290 *origin, V3_195290 *end, int mask, V3_195290 *hit, V3_195290 *normal, void **out1, void **out2);
};

struct Sub10_195290 {
    char pad0[8];
    Scene_195290 *scene;
};

struct World {
    char pad0[0x10];
    Sub10_195290 *sub10;
    char pad14[0x10];
    Caster_195290 *caster;     // 0x24
};

HitList_195290 *FUN_00202f00();
void __cdecl FUN_002f1ce0(V3_195290 *origin, float c, V3_195290 *normal, Shape_195290 **slot);

// equiv-conv: FUN_00195290 ecx eax edx edi stack stack stack stack stack stack stack
bool FUN_00195290(V3_195290 *self, void **out2, void **out1, V3_195290 *origin, V3_195290 *end, V3_195290 *normal, Shape_195290 **shapeOut,
                  Handle_195290 *h, char flag, char *flagOut, int g)
{
    World *w = DAT_004dd700;
    bool hit = w->caster->FUN_00201e00(origin, end, 1, self, normal, out1, out2);
    float dist = 3.4028235e38f;
    if (hit) {
        float ax = self->x;
        float ay = self->y;
        float az = self->z;
        double dx = ax - origin->x;
        double dy = ay - origin->y;
        double dz = az - origin->z;
        dist = (float)sqrt(dz * dz + dy * dy + dx * dx);
    }
    HitList_195290 *list = FUN_00202f00();
    DAT_004d2a3c = 2;
    (*(char*)&DAT_004d2a40) = 0;
    (*(char*)&DAT_00554c1c) = 0;
    DAT_00554c18 = g;
    Scene_195290 *scene = w->sub10->scene;
    Probe_195290 *obj = 0;
    if (h != 0 && h->kind == 1) {
        obj = h->probe;
        if (obj != 0) {
            obj->FUN_000368d0(0);
            obj->FUN_00035fa0(0);
        }
    }
    if (scene->FUN_002ee140(list, origin, end, 0)) {
        int n = list->count;
        struct Frame {
            Shape_195290 *slot;
            Rec_195290 rec;
        } f;
        for (int i = 0; i < n; i++) {
            Rec_195290 *r = &list->recs[i];
            f.rec.t = r->t;
            f.rec.node = r->node;
            f.rec.c = r->c;
            Node *node = f.rec.node;
            Shape_195290 *shape = node->shape;
            f.slot = shape;
            int kind = shape->kind;
            bool process = true;
            if (kind == 1) {
                if (shape == (Shape_195290 *)h)
                    process = false;
            } else if (kind == 5) {
                Ent_195290 *ent = shape->ent;
                if (ent == 0) {
                    process = false;
                } else if (obj != 0) {
                    if (ent == obj->ent128) {
                        process = false;
                    } else {
                        for (int j = 0; j < 8; j++) {
                            if (obj->FUN_00035ef0(j) == ent) {
                                process = false;
                                break;
                            }
                        }
                        node = f.rec.node;
                        shape = f.slot;
                    }
                }
            }
            if (!process)
                continue;
            if (obj != 0 && flag != 0) {
                if (obj->FUN_00035c30(shape))
                    *flagOut = 1;
                else
                    obj->FUN_00035c70(shape);
            }
            if (f.rec.t > 0.0f && f.rec.t < dist) {
                Shape_195290 *shape2 = node->shape;
                *self = *end;
                self->x = self->x - origin->x;
                self->y = self->y - origin->y;
                self->z = self->z - origin->z;
                self->FUN_0022d110();
                float t = f.rec.t;
                double px = self->x * t;
                self->x = (float)px;
                double py = self->y * t;
                self->y = (float)py;
                double pz = self->z * t;
                volatile float tz = (float)pz;
                self->z = (float)pz;
                self->x = (float)(px + origin->x);
                self->y = (float)(py + origin->y);
                self->z = tz + origin->z;
                f.slot = 0;
                FUN_002f1ce0(origin, f.rec.c, normal, &f.slot);
                *shapeOut = shape2;
                hit = true;
            }
            break;
        }
    }
    if (obj != 0) {
        obj->FUN_00035fa0(1);
        obj->FUN_000368d0(1);
    }
    return hit;
}
