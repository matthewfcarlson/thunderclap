extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b9bc[];
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj {
  public:
    char pad[4];
    V sub;
    char rest[0x10];
    int count;
};
class Owner {
  public:
    void Fn();
    char pad[8];
    Obj* mObj;
};
void Owner::Fn() {
    Obj* p = mObj;
    *(unsigned long*)this = ((int)DAT_0042b9bc);
    p->sub.A();
    --(*(int*)((char*)mObj + 0x14));
    p = mObj;
    p->sub.B();
    p = mObj;
    ((V*)p)->B();
    *(unsigned long*)this = ((int)DAT_0042b914);
}