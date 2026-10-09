struct Obj {
    unsigned int vt;
    int a;
    int b;
    int c;
    int d;
    void Init(int);
};
extern Obj* __cdecl FUN_0008d690(unsigned int);
class Factory {
  public:
    virtual void* f0();
    virtual void* f1();
    virtual void* f2();
    virtual void* f3();
    virtual void* f4();
    virtual void* f5();
};
void* Factory::f5() {
    Obj* p = FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        p->vt = 0x416918;
        p->c = 0;
        p->d = 0;
        return p;
    }
    return 0;
}