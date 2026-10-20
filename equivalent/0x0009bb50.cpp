// STATUS: equivalent (tools/equiv.py level 3: 3023 inputs, branch coverage 14/14)
// FUN_0009bb50 @ 0x0009bb50
class Camera {
public:
    int FUN_001c3970(int v);
    void FUN_001c38b0(float a, float b);
    void FUN_001c3910(float a, float b);
};

class View {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(float *a, float *b);
    virtual void vf7();
    virtual float vf8();
    virtual void vf9();
    virtual float vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual int vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35(int a, int b, int c, int d);
};

class Transition_9bb50 {
public:
    char FUN_00098460(int a);
    View *FUN_00098480(int a);
};

Camera *FUN_001c3d90();

class ViewSwitcher {
public:
    void FUN_0009bb50(int a, int b);
    void FUN_00098e60();
    void FUN_0009a290(int a);

    char pad0[4];
    unsigned int flags;
    unsigned int state;
    char pad1[4];
    View *current;
    char pad2[4];
    char dirty;
    char pad3[0xb8 - 0x19];
    View *previous;
    Transition_9bb50 *transition;
};

void ViewSwitcher::FUN_0009bb50(int a, int b)
{
    FUN_00098e60();
    View *view;
    dirty = 0;
    if (current == previous && !(flags & 0x60) && state != 0 && ((state >> 2) & 1)) {
        state &= ~4u;
        FUN_0009a290(a);
    }
    if ((flags >> 5) & 1) {
        if (transition->FUN_00098460(a)) {
            flags &= ~0x20u;
            current = transition->FUN_00098480(a);
            view = current;
        } else {
            view = (View *)transition;
        }
    } else {
        view = current;
    }
    view->vf35(a, b, 1, 1);
    if (view != previous)
        previous->vf35(a, b, 0, 0);
    Camera *cam = FUN_001c3d90();
    cam->FUN_001c3970(view->vf14());
    float x, y;
    view->vf6(&x, &y);
    cam->FUN_001c38b0(x, y);
    cam->FUN_001c3910(view->vf8(), view->vf10());
}
