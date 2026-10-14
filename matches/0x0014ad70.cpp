class GrappleThrowTrack {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual int vfunc_10(int a, int b, int c);
};
class Obj_14ad70 {
  public:
    int Init(GrappleThrowTrack*, int);
};
extern int __cdecl GetThing(int);
extern void* __cdecl Alloc(int);
int GrappleThrowTrack::vfunc_10(int a, int b, int c) {
    int x = GetThing(c);
    if (x) {
        Obj_14ad70* p = (Obj_14ad70*)Alloc(0x54);
        if (p)
            return p->Init(this, x);
    }
    return 0;
}