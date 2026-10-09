class TeleportTrackBase { public: void Ctor(); };
struct TeleportTrack { void* vt; int pad; int one; int z1; int z2; int z3; float last; };
extern void* Alloc(unsigned int);
class Factory {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual TeleportTrack* vfunc_5();
};
TeleportTrack* Factory::vfunc_5() {
    TeleportTrack* p = (TeleportTrack*)Alloc(0x1c);
    if (p) {
        ((TeleportTrackBase*)p)->Ctor();
        p->vt = (void*)0x417b68;
        p->z1 = 0;
        p->z2 = 0;
        p->z3 = 0;
        p->last = -1.0f;
        p->one = 1;
        return p;
    }
    return 0;
}
