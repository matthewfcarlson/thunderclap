// Same code shape as 0x0012bc00 (propagated; names are from that function)
extern char threat_vftable_13a840;
struct Obj_13a840 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_13a840*);
class FrameReachedCondition_13a840 {
  public:
    void* vftable;
    char pad[0x0c];
    FrameReachedCondition_13a840* vfunc_5(unsigned char);
};
FrameReachedCondition_13a840* FrameReachedCondition_13a840::vfunc_5(unsigned char param) {
    FrameReachedCondition_13a840* p = this;
    *(char**)p = &threat_vftable_13a840;
    ((Obj_13a840*)((char*)p + 0x10))->f1();
    ((Obj_13a840*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_13a840*)p);
    return p;
}