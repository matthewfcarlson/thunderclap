// Same code shape as 0x001617c0 (propagated; names are from that function)
extern int RTTI1_17bb40;
extern int RTTI2_17bb40;
class Result_17bb40 {
  public:
    int Make(void*);
};
class LocomotingTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual int vfunc_10(void*, void*, void*);
};
extern int __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
extern Result_17bb40* __cdecl FUN_0008d690(unsigned int);
int LocomotingTrack::vfunc_10(void* a, void* b, void* c) {
    if (FUN_00344e74(c, 0, &RTTI1_17bb40, &RTTI2_17bb40, 0)) {
        Result_17bb40* p = FUN_0008d690(0x20);
        if (p)
            return p->Make(c);
    }
    return 0;
}