class GrappleLocomotionSteerTrack {
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
    virtual int vfunc_10(int, int, int);
};
class Result_161620 {
  public:
    int Build(GrappleLocomotionSteerTrack*, int);
};
extern int __cdecl Get(int);
extern void* __cdecl Allocate(unsigned int);
int GrappleLocomotionSteerTrack::vfunc_10(int a, int b, int c) {
    int value = Get(c);
    if (value) {
        Result_161620* p = (Result_161620*)Allocate(0x30);
        if (p)
            return p->Build(this, value);
    }
    return 0;
}
