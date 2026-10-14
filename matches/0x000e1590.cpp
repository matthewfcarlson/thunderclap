struct Obj_e1590 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual float f();
};
struct FEAnimation {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual float a5();
    virtual void a6();
    char pad[8];
};
struct FEPoseAnimation : FEAnimation {
    virtual float vfunc_5();
};
extern volatile float g_e1590;
float FEPoseAnimation::vfunc_5() {
    char* base = (char*)this;
    Obj_e1590* p = *(Obj_e1590**)(base + 0x0c);
    Obj_e1590* m = *(Obj_e1590**)((char*)p + 0x4c);
    float r = g_e1590;
    if (m)
        return m->f();
    return r;
}
