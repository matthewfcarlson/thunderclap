struct Obj {
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
extern volatile float g;
float FEPoseAnimation::vfunc_5() {
    char* base = (char*)this;
    Obj* p = *(Obj**)(base + 0x0c);
    Obj* m = *(Obj**)((char*)p + 0x4c);
    float r = g;
    if (m)
        return m->f();
    return r;
}
