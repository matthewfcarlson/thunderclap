class CSmartPropSpawnTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual CSmartPropSpawnTrack* vfunc_5(unsigned char);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    char pad[0x94];
    void finish();
};
struct Helper {
    void call();
};
extern void* vt[];
extern void FUN_00267090(CSmartPropSpawnTrack*);
CSmartPropSpawnTrack* CSmartPropSpawnTrack::vfunc_5(unsigned char p) {
    ((void**)this)[0] = vt;
    ((Helper*)((char*)this + 0xc8))->call();
    ((Helper*)((char*)this + 0xa0))->call();
    ((Helper*)((char*)this + 0x98))->call();
    finish();
    if (p & 1)
        FUN_00267090(this);
    return this;
}