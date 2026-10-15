// cl-flags: /O2 /GR /GX
extern void* g_vftable;
extern void* g_vftable2;
class HasGroundPointCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};
extern int __cdecl CastTest(void* a, void* b, void* c, void* d, void* e);
class CF {
  public:
    virtual int vfunc_0(int a);
    virtual int vfunc_1();
};
int CF::vfunc_0(int a) {
    int r = CastTest((void*)a, 0, &g_vftable, &g_vftable2, 0);
    if (r)
        return 1;
    return 0;
}
