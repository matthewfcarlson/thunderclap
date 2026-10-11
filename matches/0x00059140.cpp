extern "C" void* __cdecl Allocate(unsigned int);
extern "C" int CondVtable;
struct Sub {
    int x;
    void Init();
};
class Cond {
  public:
    virtual void V0();
    virtual void V1();
    int a, b, c;
    Sub s;
    int pad;
    void Initialize(int);
};
class Factory {
  public:
    Cond* vfunc_5();
};
Cond* Factory::vfunc_5() {
    Cond* p = (Cond*)Allocate(0x18);
    if (p) {
        p->Initialize(0);
        *(int*)p = (int)&CondVtable;
        p->c = 0;
        p->s.Init();
        return p;
    }
    return 0;
}
