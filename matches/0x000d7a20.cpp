class FEObject {
    char pad[0x9c];

  public:
    virtual float vfunc_0();
    virtual float vfunc_1();
    virtual float vfunc_2();
    virtual float vfunc_3();
    virtual float vfunc_4();
    virtual float vfunc_5();
    virtual float vfunc_6();
    virtual float vfunc_7();
    virtual float vfunc_8();
    virtual float vfunc_9();
};
float FEObject::vfunc_8() {
    return *(float*)((char*)this + 0x9c);
}