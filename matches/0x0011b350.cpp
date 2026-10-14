extern "C" char DAT_0040eb50[];
typedef unsigned int u32_11b350;
extern void* __cdecl alloc(unsigned int);
class MotionStopTrack {
  public:
    MotionStopTrack();
    u32_11b350 a;
    u32_11b350 b;
    u32_11b350 c;
    int x;
    float y;
};
class Factory_11b350 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual MotionStopTrack* vfunc_5();
};
MotionStopTrack* Factory_11b350::vfunc_5() {
    MotionStopTrack* p = (MotionStopTrack*)alloc(0x14);
    if (p) {
        p->MotionStopTrack::MotionStopTrack();
        p->a = ((int)DAT_0040eb50);
        p->x = 0;
        p->y = -1.0f;
        return p;
    }
    return 0;
}
