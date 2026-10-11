extern void* vReq[];
extern void* vDrive[];
class Elem {
  public:
    virtual void A();
    virtual void B();
};
class Obj {
  public:
    virtual void A();
};
extern void FUN_002705f0();
struct Target {
    void* vf;
    int p4;
    Obj* p8;
    Target(Obj*);
};
Target::Target(Obj* a) {
    vf = vReq;
    p4 = 0;
    FUN_002705f0();
    vf = vDrive;
    p8 = a;
    FUN_002705f0();
    ((Elem*)((char*)p8 + 4))->A();
    ++*(int*)((char*)p8 + 0x14);
    ((Elem*)((char*)p8 + 4))->B();
    p8->A();
}
