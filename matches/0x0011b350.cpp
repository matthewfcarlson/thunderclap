typedef unsigned int u32;
extern void* __cdecl alloc(unsigned int);
class MotionStopTrack {
public:
    MotionStopTrack();
    u32 a;
    u32 b;
    u32 c;
    int x;
    float y;
};
class Factory {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual MotionStopTrack* vfunc_5();
};
MotionStopTrack* Factory::vfunc_5() {
    MotionStopTrack* p = (MotionStopTrack*)alloc(0x14);
    if (p) {
        p->MotionStopTrack::MotionStopTrack();
        p->a = 0x40eb50;
        p->x = 0;
        p->y = -1.0f;
        return p;
    }
    return 0;
}
