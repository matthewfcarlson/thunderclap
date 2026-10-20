// Same code shape as 0x0012bc00 (propagated; names are from that function)
extern char threat_vftable_1504e0;
struct Obj_1504e0 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_1504e0*);
class CollisionTargetNameCondition_1504e0 {
  public:
    void* vftable;
    char pad[0x0c];
    CollisionTargetNameCondition_1504e0* vfunc_5(unsigned char);
};
CollisionTargetNameCondition_1504e0* CollisionTargetNameCondition_1504e0::vfunc_5(unsigned char param) {
    CollisionTargetNameCondition_1504e0* p = this;
    *(char**)p = &threat_vftable_1504e0;
    ((Obj_1504e0*)((char*)p + 0x10))->f1();
    ((Obj_1504e0*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_1504e0*)p);
    return p;
}