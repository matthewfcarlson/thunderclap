// Same code shape as 0x0012bc00 (propagated; names are from that function)
extern char threat_vftable_1505a0;
struct Obj_1505a0 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_1505a0*);
class CollisionSourceNameCondition_1505a0 {
  public:
    void* vftable;
    char pad[0x0c];
    CollisionSourceNameCondition_1505a0* vfunc_5(unsigned char);
};
CollisionSourceNameCondition_1505a0* CollisionSourceNameCondition_1505a0::vfunc_5(unsigned char param) {
    CollisionSourceNameCondition_1505a0* p = this;
    *(char**)p = &threat_vftable_1505a0;
    ((Obj_1505a0*)((char*)p + 0x10))->f1();
    ((Obj_1505a0*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_1505a0*)p);
    return p;
}