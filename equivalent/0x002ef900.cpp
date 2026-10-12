// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 21/24, incomplete)
// physics::SimState::vfunc_6 @ 0x002ef900
extern "C" double sqrt(double);

struct Mat {
    float m[16];
};

struct Vec3 {
    float x, y, z;
};

struct Flags {
    char pad0[0x19];
    unsigned char b19;
};

class Controller {
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

struct Target {
    char pad0[0x20];
    Flags *flags;
    char pad24[0x68 - 0x24];
    unsigned char on;
    unsigned char dirty;
};

class Sim;

char __cdecl FUN_00306060(Mat *a, Mat *b, float eps);
void __cdecl FUN_002ef760(Mat *cur, Mat *next, int mode, float dt, Vec3 *out);

class SimState {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(Mat *mat, float dt);
    virtual void vfunc_7();
    char pad04[0xc];
    Mat current;
    Vec3 delta;
    char pad5c[0x68 - 0x5c];
    int mode;
    int f6c;
    char pad70[4];
    Target *target;
    unsigned char changed;
    char pad79[0x80 - 0x79];
    float radius;
    unsigned char locked;

    void FUN_002ef5b0(Mat *cur, Mat *next);
};

void SimState::vfunc_6(Mat *mat, float dt)
{
    Mat *cur = &current;
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
                    Target *t = target;
                    if (t->on != 0 || t->dirty != 0)
                        ((Controller *)t->flags)->vfunc_10();
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

    float lenSq = delta.z * delta.z + delta.y * delta.y + delta.x * delta.x;
    float limit = 2.0f * radius;
    if (lenSq > limit * limit) {
        radius = (float)sqrt((double)lenSq);
        Target *t = target;
        if (t != 0) {
            t->flags->b19 = 0;
            t->on = 1;
            t->dirty = 1;
        }
    } else if (lenSq < radius / 2.0f) {
        radius = (float)sqrt((double)lenSq);
    }
}
