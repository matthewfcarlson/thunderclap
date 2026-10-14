// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 12/12)
// pure3d::BlendFrameController::vfunc_12 @ 0x002861a0
struct Track {
    float cur;
    float lo;
    float hi;
    char pad0c[0xc];
    float f18;
    int f1c;
    int state;
    unsigned char flag;
    char pad25[3];
    void* owner;
};

class BlendFrameController {
public:
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
    virtual void vfunc_12(float x);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual float v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    char pad04[0x28 - 4];
    unsigned int count;
    Track tracks[4];
};

void BlendFrameController::vfunc_12(float x)
{
    if (count == 0)
        return;
    Track* t = &tracks[count - 1];
    if (x >= t->lo && x <= t->hi)
        t->cur = x;
    else if (x > t->hi)
        t->cur = t->hi;
    else
        t->cur = t->lo;
    t->f18 = v20();
    if (t->state == 3 || t->state == 5)
        t->flag = 0;
    else
        t->flag = 1;
}
