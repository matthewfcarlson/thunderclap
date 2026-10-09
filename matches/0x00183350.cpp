typedef unsigned char u8;
struct Sub {
    void Init();
};
extern void DeleteObj(void*);
class BallAndChainShootTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual BallAndChainShootTrack* vfunc_5(u8);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    void BaseInit();
    char pad[0x78 - 4];
};
BallAndChainShootTrack* BallAndChainShootTrack::vfunc_5(u8 x) {
    *(unsigned int*)this = 0x41947c;
    ((Sub*)((char*)this + 0x78))->Init();
    ((Sub*)((char*)this + 0x60))->Init();
    BaseInit();
    if (x & 1)
        DeleteObj(this);
    return this;
}