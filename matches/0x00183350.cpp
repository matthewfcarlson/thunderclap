extern "C" char DAT_0041947c[];
typedef unsigned char u8_183350;
struct Sub_183350 {
    void Init();
};
extern void DeleteObj(void*);
namespace hulkfight { namespace motion { class BallAndChainShootTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual BallAndChainShootTrack* vfunc_5(u8_183350);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    void BaseInit();
    char pad[0x78 - 4];
}; }}
hulkfight::motion::BallAndChainShootTrack* hulkfight::motion::BallAndChainShootTrack::vfunc_5(u8_183350 x) {
    *(unsigned int*)this = ((int)DAT_0041947c);
    ((Sub_183350*)((char*)this + 0x78))->Init();
    ((Sub_183350*)((char*)this + 0x60))->Init();
    BaseInit();
    if (x & 1)
        DeleteObj(this);
    return this;
}