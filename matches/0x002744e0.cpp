extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b9bc[];
// Same code shape as 0x00274590 (propagated; names are from that function)
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj_2744e0 {
  public:
    char pad[4];
    V sub;
    char rest[0x10];
    int count;
};
class Owner_2744e0 {
  public:
    void Fn();
    char pad[8];
    Obj_2744e0* mObj;
};
void Owner_2744e0::Fn() {
    Obj_2744e0* p = mObj;
    *(unsigned long*)this = ((int)DAT_0042b9bc);
    p->sub.A();
    --(*(int*)((char*)mObj + 0x14));
    p = mObj;
    p->sub.B();
    p = mObj;
    ((V*)p)->B();
    *(unsigned long*)this = ((int)DAT_0042b914);
}