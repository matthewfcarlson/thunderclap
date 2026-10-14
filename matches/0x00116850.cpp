typedef unsigned char u8_116850;
class Track {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vfunc_3();
    virtual void v4();
    virtual void v5(u8_116850);
    virtual void v6();
    virtual void v7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void v10();
};
class Param {};
class MotionLocatorTrack : public Track, public Param {
  public:
    virtual MotionLocatorTrack* vfunc_5(u8_116850);
    char pad[0x30 - sizeof(Track)];
};
class Sub_116850 {
  public:
    void f();
};
class Main_116850 {
  public:
    void f();
};
void __cdecl Destroy(MotionLocatorTrack*);
extern void* vf_116850;
MotionLocatorTrack* MotionLocatorTrack::vfunc_5(u8_116850 flag) {
    ((void**)this)[0] = &vf_116850;
    ((Sub_116850*)((char*)this + 0x30))->f();
    ((Main_116850*)this)->f();
    if (flag & 1)
        Destroy(this);
    return this;
}