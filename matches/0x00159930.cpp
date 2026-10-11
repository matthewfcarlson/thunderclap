extern "C" char DAT_00414190[];
typedef unsigned int uint;
extern void* __cdecl Allocate(uint);
struct Obj {
    unsigned int vt;
    int a;
    int b;
    int c;
    int d;
    int e;
    char flag;
    void Init(int);
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Obj* vfunc5();
};
Obj* Factory::vfunc5() {
    Obj* p = (Obj*)Allocate(0x1c);
    if (p) {
        p->Init(0);
        p->vt = ((int)DAT_00414190);
        p->c = 0;
        p->d = 0;
        p->e = 0;
        p->flag = 1;
        return p;
    }
    return 0;
}
