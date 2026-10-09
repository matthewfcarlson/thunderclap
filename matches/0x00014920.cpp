class Thing {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int* get();
    char pad[0x5c - 4];
    float value;
};
class CPushBackAnimationAction {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual float vfunc_9();
    char pad[0x18];
    Thing* mThing;
};
float CPushBackAnimationAction::vfunc_9() {
    int* p = mThing->get();
    if (!p)
        return 0.0f;
    return *(float*)((char*)p + 0x5c);
}