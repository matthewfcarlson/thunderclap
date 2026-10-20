// Same code shape as 0x0012bc00 (propagated; names are from that function)
extern char threat_vftable_150420;
struct Obj_150420 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_150420*);
class CollisionThrownObjectCondition_150420 {
  public:
    void* vftable;
    char pad[0x0c];
    CollisionThrownObjectCondition_150420* vfunc_5(unsigned char);
};
CollisionThrownObjectCondition_150420* CollisionThrownObjectCondition_150420::vfunc_5(unsigned char param) {
    CollisionThrownObjectCondition_150420* p = this;
    *(char**)p = &threat_vftable_150420;
    ((Obj_150420*)((char*)p + 0x10))->f1();
    ((Obj_150420*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_150420*)p);
    return p;
}