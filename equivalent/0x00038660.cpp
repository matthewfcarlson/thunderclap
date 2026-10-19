// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 77/92, incomplete)
// FUN_00038660 @ 0x00038660
// FUN_00038660 @ 0x00038660
#include "decls/address.h"
struct V3_38660 { float x, y, z; float FUN_0022d110(); };
struct Rng_38660 { int FUN_00011380(int a, int b); };
Rng_38660 *FUN_000964d0();
struct Rc { char pad0[0xc]; int f0c; };
struct Sub74_38660 { char pad0[0x72]; char b72; };
struct Sub_38660 { char pad0[0x74]; Sub74_38660 *p74; };
struct Link_38660 { char pad0[0x74]; Sub74_38660 *p74; };
struct Ent_38660 { Sub_38660 *FUN_001d72e0(); };
struct Player_38660 { char pad0[0x124]; void *f124; };
struct World { char pad0[0x20]; Player_38660 *p20; };
struct Slot_38660 {
    float x0, y0, z0;
    float x1, y1, z1;
    float x2, y2, z2;
    float x3, y3, z3;
    Rc *ptr;
    char flag;
    char pad35[3];
};
struct Opts_38660 { float a; int flag; float c; };
void FUN_000187d0(Rc **slot);
void FUN_00018810(Rc **slot, int z);
char FUN_00018960(float a, float b, float eps);
void FUN_00224d70(float angle, V3_38660 *v);
float FUN_00224f10(V3_38660 *v);
char FUN_00202560(V3_38660 *from, int a2, int flag, V3_38660 *a3, V3_38660 *a4, V3_38660 *o38, V3_38660 *o48, Opts_38660 *opts);
extern "C" int __cdecl FUN_0034483c();
class Mover_38660 {
public:
    char pad0[0x128];
    Ent_38660 *p128;
    Link_38660 *p12c;
    char pad130[0x334 - 0x130];
    void *f334;
    void *f338;
    char pad33c[0x1ea8 - 0x33c];
    Slot_38660 slots[3];
    void FUN_00035fa0(int z);
    char F(V3_38660 *a1, int a2, V3_38660 *a3, V3_38660 *a4, V3_38660 *a5, int *a6, int idx, char *a8, V3_38660 *a9);
};

char Mover_38660::F(V3_38660 *a1, int a2, V3_38660 *a3, V3_38660 *a4, V3_38660 *a5, int *a6, int idx, char *a8, V3_38660 *a9)
{
    struct Frame {
        Opts_38660 opts;
        V3_38660 direction;
        V3_38660 retryPosition;
        V3_38660 hitPosition;
        int padding;
        V3_38660 hitObject;
    } frame;
    char result = 1;
    bool cacheHit = false;

    if (p12c && p12c->p74)
        p12c->p74->b72 = 0;
    if (p128) {
        Sub_38660 *r = p128->FUN_001d72e0();
        if (r && r->p74)
            r->p74->b72 = 0;
    }
    FUN_00035fa0(0);
    if (idx >= 0 && idx < 3) {
        Slot_38660 *slot = &slots[idx];
        if (slot->flag && slot->ptr && slot->ptr->f0c == 0) {
            slot->flag = 0;
            FUN_000187d0(&slot->ptr);
        }
    }
    if (a8)
        *a8 = 0;
    char isPlayer = DAT_004dd700->p20->f124 == (void *)this;
    float toleranceX = 0.4f, toleranceY = 0.4f, toleranceZ = 0.4f;
    if (isPlayer) {
        toleranceX = 0.01f;
        toleranceY = 0.01f;
        toleranceZ = 0.01f;
    }
    frame.opts.c = toleranceZ;
    if (idx >= 0 && idx < 3 && slots[idx].flag) {
        Slot_38660 *slot = &slots[idx];
        union { float f; unsigned int u; } delta;
        delta.f = a1->x - slot->x0;
        delta.u &= 0x7fffffff;
        if (delta.f < toleranceX) {
            delta.f = a1->y - slot->y0;
            delta.u &= 0x7fffffff;
            if (delta.f < toleranceY) {
                delta.f = a1->z - slot->z0;
                delta.u &= 0x7fffffff;
                cacheHit = delta.f < toleranceZ;
            }
        }
        if (cacheHit) {
            a3->x = a1->x;
            a3->y = a1->y;
            a3->z = a1->z;
            a3->y = slot->y1;
            a4->x = slot->x2;
            a4->y = slot->y2;
            a4->z = slot->z2;
            if (a5) {
                a5->x = a1->x;
                a5->y = a1->y;
                a5->z = a1->z;
                a5->y = slot->y3;
            }
            if (a6)
                *a6 = (int)slots[idx].ptr;
            if (a8)
                *a8 = 1;
        }
    }
    if (!cacheHit) {
        void *player = DAT_004dd700->p20->f124;
        int notOwner = (void *)this != player && f338 != player && f334 != player;
        frame.opts.flag = notOwner;
        frame.hitObject.x = 0;
        frame.opts.a = 0;
        result = FUN_00202560(a1, a2, notOwner, a3, a4,
                              &frame.hitPosition, &frame.hitObject, &frame.opts);
        if (!result && isPlayer && frame.opts.a == 0 && a9) {
            frame.retryPosition.x = a9->x;
            frame.retryPosition.y = a1->y;
            frame.retryPosition.z = a9->z;
            frame.direction.x = a9->x - a1->x;
            frame.direction.y = a1->y - a1->y;
            frame.direction.z = a9->z - a1->z;
            float length = frame.direction.FUN_0022d110();
            if (FUN_00018960(length, 0.0f, 1.0e-5f)) {
                int randomValue = FUN_000964d0()->FUN_00011380(0, 0xb);
                unsigned int unsignedValue = randomValue;
                float angle = (float)(((double)unsignedValue + 0.5f) * 60.0f * 0.0174533f);
                frame.direction.x = 0;
                frame.direction.y = 0;
                frame.direction.z = -0.05f;
                FUN_00224d70(angle, &frame.direction);
            } else {
                float turns = FUN_00224f10(&frame.direction) * 57.2958f * 0.0166667f;
                int wholeTurns = (int)turns;
                float fractionalTurn = turns - (float)wholeTurns;
                if (fractionalTurn > 0.5f)
                    fractionalTurn = fractionalTurn - 1.0f;
                if (FUN_00018960(fractionalTurn, 0.0f, 0.25f))
                    FUN_00224d70(0.5236f, &frame.direction);
                frame.direction.x = frame.direction.x * 0.05f;
                frame.direction.y = frame.direction.y * 0.05f;
                frame.direction.z = frame.direction.z * 0.05f;
            }
            frame.retryPosition.x = a1->x + frame.direction.x;
            frame.retryPosition.y = frame.direction.y + a1->y;
            frame.retryPosition.z = a1->z + frame.direction.z;
            result = FUN_00202560(&frame.retryPosition, a2, notOwner, a3, a4,
                                  &frame.hitPosition, &frame.hitObject, &frame.opts);
            if (result) {
                a3->x = a1->x;
                a3->z = a1->z;
                frame.hitPosition.x = a1->x;
                frame.hitPosition.z = a1->z;
            }
        }
        if (result) {
            if (*(int *)&frame.hitObject.x == 0 && idx >= 0 && idx < 3) {
                Slot_38660 *slot = &slots[idx];
                slot->flag = 1;
                slot->x0 = a1->x;
                slot->y0 = a1->y;
                slot->z0 = a1->z;
                slot->x1 = a3->x;
                slot->y1 = a3->y;
                slot->z1 = a3->z;
                slot->x2 = a4->x;
                slot->y2 = a4->y;
                slot->z2 = a4->z;
                slot->x3 = frame.hitPosition.x;
                slot->y3 = frame.hitPosition.y;
                slot->z3 = frame.hitPosition.z;
                FUN_00018810(&slot->ptr, 0);
            }
            if (a5) {
                a5->x = frame.hitPosition.x;
                a5->y = frame.hitPosition.y;
                a5->z = frame.hitPosition.z;
            }
            if (a6)
                *a6 = *(int *)&frame.hitObject.x;
        } else if (idx >= 0 && idx < 3) {
            slots[idx].flag = 0;
        }
    }
    FUN_00035fa0(1);
    if (p12c && p12c->p74)
        p12c->p74->b72 = 1;
    if (p128) {
        Sub_38660 *r = p128->FUN_001d72e0();
        if (r && r->p74)
            r->p74->b72 = 1;
    }
    return result;
}