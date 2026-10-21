// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 21/24, incomplete)
// physics::SimState::vfunc_6 @ 0x002ef900
#include "compat/ptr.h"
extern "C" double sqrt(double);

struct Mat_2ef900 {
    float m[16];
};

struct Vec3_2ef900 {
    float x, y, z;
};

struct Flags_2ef900 {
    char pad0[0x19];
    unsigned char b19;
};

class Controller_2ef900 {
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
};

struct Target_2ef900 {
    char pad0[0x20];
    Flags_2ef900 *flags;
    char pad24[0x68 - 0x24];
    unsigned char on;
    unsigned char dirty;
};

class Sim;

char __cdecl FUN_00306060(Mat_2ef900 *a, Mat_2ef900 *b, float eps);
void __cdecl FUN_002ef760(Mat_2ef900 *cur, Mat_2ef900 *next, int mode, float dt, Vec3_2ef900 *out);

class SimState {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Mat_2ef900 *mat, float dt);
    virtual void vfunc_7();
    char pad04[0xc];
    Mat_2ef900 current;
    Vec3_2ef900 delta;
    char pad5c[0x68 - 0x5c];
    int mode;
    int f6c;
    char pad70[4];
    Target_2ef900 *target;
    unsigned char changed;
    char pad79[0x80 - 0x79];
    float radius;
    unsigned char locked;

    void FUN_002ef5b0(Mat_2ef900 *cur, Mat_2ef900 *next);
};

void SimState::vfunc_6(Mat_2ef900 *mat, float dt)
{
    Mat_2ef900 *cur = &current;
    changed = (FUN_00306060(cur, mat, 1e-6f) == 0);
    if (f6c == 0) {
        if (changed) {
            if (dt != 0.0f) {
                FUN_002ef760(cur, mat, mode, dt, &delta);
            } else {
                vfunc_7();
                if (target != 0) {
                    target->flags->b19 = 0;
                    target->on = 1;
                    target->dirty = 1;
                    Target_2ef900 *t = target;
                    if (t->on != 0 || t->dirty != 0)
                        ((Controller_2ef900 *)t->flags)->vfunc_10();
                }
            }
        } else {
            vfunc_7();
        }
    }
    if (target != 0 && changed)
        FUN_002ef5b0(cur, mat);

    unsigned char lockedNow = locked;
    *cur = *mat;
    if (lockedNow != 0)
        return;

    hulk_freg lenSq = delta.z * delta.z + delta.y * delta.y + delta.x * delta.x;
    hulk_freg limit = 2.0f * radius;
    if (lenSq > limit * limit) {
        radius = (float)sqrt((double)lenSq);
        Target_2ef900 *t = target;
        if (t != 0) {
            t->flags->b19 = 0;
            t->on = 1;
            t->dirty = 1;
        }
    } else if (lenSq < radius / 2.0f) {
        radius = (float)sqrt((double)lenSq);
    }
}
