struct CMotionHitGroundHeightTrack {
    int vptr;
    int pad;
    int c;
    int d;
    float e;
    float f;
    void construct();
};
extern int vtable;
extern void* operator_new(unsigned int);

class Factory {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual CMotionHitGroundHeightTrack* vfunc_5();
};

CMotionHitGroundHeightTrack* Factory::vfunc_5() {
    CMotionHitGroundHeightTrack* p = (CMotionHitGroundHeightTrack*)operator_new(0x18);
    if (p) {
        p->construct();
        p->vptr = (int)&vtable;
        p->d = 0;
        p->e = -1.0f;
        p->f = 1.0f;
        p->c = 1;
        return p;
    }
    return 0;
}
