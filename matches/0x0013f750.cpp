typedef unsigned char byte_13f750;
extern int vf_13f750;
class Helper_13f750 {
  public:
    void clean();
};
class Base_13f750 {
  public:
    void init();
};
void thunk(void*);
namespace hulkfight {
namespace motion {
class WallRunTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual WallRunTrack* vfunc_5(byte_13f750);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x38];
};
WallRunTrack* WallRunTrack::vfunc_5(byte_13f750 param) {
    *(int*)this = (int)&vf_13f750;
    ((Helper_13f750*)((char*)this + 0x48))->clean();
    ((Helper_13f750*)((char*)this + 0x40))->clean();
    ((Helper_13f750*)((char*)this + 0x38))->clean();
    ((Base_13f750*)this)->init();
    if (param & 1)
        thunk(this);
    return this;
}
} // namespace motion
} // namespace hulkfight
