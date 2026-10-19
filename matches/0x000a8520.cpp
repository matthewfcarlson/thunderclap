// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 6/6)
// CDramaticCamera::vfunc_35 @ 0x000a8520
// cl-flags: /GS

struct Mat_a8520 {
    float m[16];
    void FUN_0022ca90(const Mat_a8520 *a, const Mat_a8520 *b);
};

class Controller_a8520 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(float t, int n);
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual char vfunc_22();
};

class Source_a8520 {
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
    virtual Mat_a8520 *vfunc_14();
    char pad04[0x10 - 4];
    float angle;
};

class Target_a8520 {
public:
    void FUN_0009a1e0(struct Event_a8520 *e);
};

struct Event_a8520 {
    char pad0[8];
    Target_a8520 *target;
};

class CGameCamera {
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
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21(Mat_a8520 *m);
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35(Event_a8520 *e, float dt, int a, int b);
    virtual void vfunc_36();
    virtual void vfunc_37();
    char pad04[0xf1 - 4];
    char disabled;
    char padf2[0x170 - 0xf2];
    Controller_a8520 *controller;
    Source_a8520 *source;
    float scale;
    float timer;
    Mat_a8520 offset;
    void FUN_000a9090(float v);
};

class CDramaticCamera : public CGameCamera {
public:
    virtual void vfunc_35(Event_a8520 *e, float dt, int a, int b);
};

void CDramaticCamera::vfunc_35(Event_a8520 *e, float dt, int a, int b)
{
    char gs_unused[16]; /* dead stack buffer: MSVC /GS protects only functions with a char array */
    if (!disabled) {
        if (!controller->vfunc_22()) {
            controller->vfunc_6(dt * scale * 1000.0f, 1);
            Mat_a8520 cam = *source->vfunc_14();
            Mat_a8520 result;
            result.FUN_0022ca90(&cam, &offset);
            cam = result;
            vfunc_21(&cam);
            FUN_000a9090(source->angle * 57.2957764f);
            CGameCamera::vfunc_35(e, dt, a, b);
        } else {
            timer = timer - dt;
            if (timer < 0.0f)
                e->target->FUN_0009a1e0(e);
        }
    }
}
