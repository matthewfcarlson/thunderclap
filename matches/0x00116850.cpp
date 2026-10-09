typedef unsigned char u8;
class Track { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void vfunc_3(); virtual void v4(); virtual void v5(u8); virtual void v6(); virtual void v7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void v10(); };
class Param {};
class MotionLocatorTrack : public Track, public Param { public: virtual MotionLocatorTrack* vfunc_5(u8); char pad[0x30 - sizeof(Track)]; };
class Sub { public: void f(); };
class Main { public: void f(); };
void __cdecl Destroy(MotionLocatorTrack*);
extern void* vf;
MotionLocatorTrack* MotionLocatorTrack::vfunc_5(u8 flag) {
    ((void**)this)[0] = &vf;
    ((Sub*)((char*)this + 0x30))->f();
    ((Main*)this)->f();
    if (flag & 1) Destroy(this);
    return this;
}