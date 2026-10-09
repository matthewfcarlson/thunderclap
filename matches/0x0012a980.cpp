class Factory {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void* Make();
};
extern void* __cdecl FUN_0008d690(unsigned int);
class Init {
  public:
    void Start(int);
};
struct Obj {
    unsigned int vt;
    int a;
    int b;
    int c;
    int d;
};
void* Factory::Make() {
    Obj* p = (Obj*)FUN_0008d690(0x14);
    if (p) {
        ((Init*)p)->Start(0);
        p->vt = 0x40fe74;
        p->c = 0;
        p->d = 0;
        return p;
    }
    return 0;
}