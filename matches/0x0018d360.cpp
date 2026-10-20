// Same code shape as 0x0012bc00 (propagated; names are from that function)
extern char threat_vftable_18d360;
struct Obj_18d360 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_18d360*);
class VarCompareCondition_18d360 {
  public:
    void* vftable;
    char pad[0x0c];
    VarCompareCondition_18d360* vfunc_5(unsigned char);
};
VarCompareCondition_18d360* VarCompareCondition_18d360::vfunc_5(unsigned char param) {
    VarCompareCondition_18d360* p = this;
    *(char**)p = &threat_vftable_18d360;
    ((Obj_18d360*)((char*)p + 0x10))->f1();
    ((Obj_18d360*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_18d360*)p);
    return p;
}