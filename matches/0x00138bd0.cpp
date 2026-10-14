class Result_138bd0 {
  public:
    int build(int, int);
};
extern int __cdecl Lookup(int);
extern Result_138bd0* __cdecl Alloc(int);
class GrappleHoverTrack {
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
    char pad[0x10];
    int field14;
};
int GrappleHoverTrack::vfunc_10(int a, int b, int c) {
    int x = Lookup(c);
    if (x) {
        Result_138bd0* p = Alloc(0x24);
        if (p) {
            int f = field14;
            return p->build(f, x);
        }
    }
    return 0;
}
