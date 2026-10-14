extern void* heliVftable;
struct Sub_15cde0 {
    void init();
};
class HeliLocomotionTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual HeliLocomotionTrack* vfunc_5(int);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x9c];
    void after();
};
void thunk_FUN_00267090(HeliLocomotionTrack*);
HeliLocomotionTrack* HeliLocomotionTrack::vfunc_5(int flag) {
    *(void**)this = &heliVftable;
    ((Sub_15cde0*)((char*)this + 0xa0))->init();
    after();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}