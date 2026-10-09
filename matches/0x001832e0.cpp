typedef unsigned char u8;
extern void __cdecl cleanup(void*);
class Sub {
  public:
    void Init();
};
class BallAndChainReturnTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual BallAndChainReturnTrack* vfunc_5(u8);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    void BaseInit();
    char pad[0x60 - 4];
};
BallAndChainReturnTrack* BallAndChainReturnTrack::vfunc_5(u8 flag) {
    Sub* a = (Sub*)((char*)this + 0x60);
    *(int*)this = 0x41941c;
    a->Init();
    ((Sub*)((char*)this + 0x48))->Init();
    this->BaseInit();
    if (flag & 1)
        cleanup(this);
    return this;
}
