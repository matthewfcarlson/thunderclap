extern void* __cdecl Alloc(unsigned int);
extern int AxisVtable;
struct CAxisDoubleTapCondition {
    int vt;
    int pad0;
    int pad1;
    int x0;
    int x1;
    int x2;
    int x3;
    int x4;
    void Init(int);
};
class Factory {
  public:
    CAxisDoubleTapCondition* vfunc_5();
};
CAxisDoubleTapCondition* Factory::vfunc_5() {
    CAxisDoubleTapCondition* p = (CAxisDoubleTapCondition*)Alloc(0x20);
    if (p) {
        p->Init(0);
        p->x0 = 0;
        p->vt = (int)&AxisVtable;
        p->x1 = 0;
        p->x2 = 0x3fc90fdb;
        p->x3 = 0;
        p->x4 = 0x3f000000;
        return p;
    }
    return 0;
}