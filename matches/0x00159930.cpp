extern "C" char DAT_00414190[];
typedef unsigned int uint;
extern void* __cdecl Allocate(uint);
struct Obj_159930 {
    unsigned int vt;
    int a;
    int b;
    int c;
    int d;
    int e;
    char flag;
    void Init(int);
};
class Factory_159930 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Obj_159930* vfunc5();
};
Obj_159930* Factory_159930::vfunc5() {
    Obj_159930* p = (Obj_159930*)Allocate(0x1c);
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
