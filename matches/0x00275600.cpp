extern void* vReq[];
extern void* vDrive[];
class Elem_275600 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_275600 {
  public:
    virtual void A();
};
extern void FUN_002705f0();
struct Target_275600 {
    void* vf;
    int p4;
    Obj_275600* p8;
    Target_275600(Obj_275600*);
};
Target_275600::Target_275600(Obj_275600* a) {
    vf = vReq;
    p4 = 0;
    FUN_002705f0();
    vf = vDrive;
    p8 = a;
    FUN_002705f0();
    ((Elem_275600*)((char*)p8 + 4))->A();
    ++*(int*)((char*)p8 + 0x14);
    ((Elem_275600*)((char*)p8 + 4))->B();
    p8->A();
}
