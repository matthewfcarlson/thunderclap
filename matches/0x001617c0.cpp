extern int RTTI1_1617c0;
extern int RTTI2_1617c0;
class Result_1617c0 {
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
extern Result_1617c0* __cdecl FUN_0008d690(unsigned int);
int LocomotingTrack::vfunc_10(void* a, void* b, void* c) {
    if (FUN_00344e74(c, 0, &RTTI1_1617c0, &RTTI2_1617c0, 0)) {
        Result_1617c0* p = FUN_0008d690(0x20);
        if (p)
            return p->Make(c);
    }
    return 0;
}