struct CHitAnimationTrack {
    unsigned int* vf;
    void init();
};
extern int hit_vftable;
extern void* __cdecl alloc(unsigned int);
struct Factory_6fb80 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    CHitAnimationTrack* vfunc_5();
};
CHitAnimationTrack* Factory_6fb80::vfunc_5() {
    CHitAnimationTrack* p = (CHitAnimationTrack*)alloc(0x50);
    if (p) {
        p->init();
        p->vf = (unsigned int*)&hit_vftable;
        return p;
    }
    return 0;
}