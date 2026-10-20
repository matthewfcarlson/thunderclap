// Same code shape as 0x0012bc00 (propagated; names are from that function)
extern char threat_vftable_13a870;
struct Obj_13a870 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_13a870*);
class FrameCondition_13a870 {
  public:
    void* vftable;
    char pad[0x0c];
    FrameCondition_13a870* vfunc_5(unsigned char);
};
FrameCondition_13a870* FrameCondition_13a870::vfunc_5(unsigned char param) {
    FrameCondition_13a870* p = this;
    *(char**)p = &threat_vftable_13a870;
    ((Obj_13a870*)((char*)p + 0x10))->f1();
    ((Obj_13a870*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_13a870*)p);
    return p;
}