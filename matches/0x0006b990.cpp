class CCameraDramaticTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CCameraDramaticTrack* vfunc_5(unsigned char);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    char pad[0x5c];
};
class Helper {
  public:
    void init();
    void finish();
};
extern char vfCamera, vfTrack;
void __cdecl thunk_FUN_00267090(CCameraDramaticTrack*);
CCameraDramaticTrack* CCameraDramaticTrack::vfunc_5(unsigned char flag) {
    CCameraDramaticTrack* self = this;
    *(void**)self = &vfCamera;
    Helper* h = (Helper*)((char*)self + 0x60);
    int n = 8;
    do {
        h = (Helper*)((char*)h - 8);
        h->init();
        --n;
    } while (n);
    *(void**)self = &vfTrack;
    ((Helper*)self)->finish();
    if (flag & 1)
        thunk_FUN_00267090(self);
    return self;
}