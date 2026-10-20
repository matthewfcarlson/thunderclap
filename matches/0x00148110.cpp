// Same code shape as 0x0012bc00 (propagated; names are from that function)
extern char threat_vftable_148110;
struct Obj_148110 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_148110*);
class GrappleAttachJointCondition_148110 {
  public:
    void* vftable;
    char pad[0x0c];
    GrappleAttachJointCondition_148110* vfunc_5(unsigned char);
};
GrappleAttachJointCondition_148110* GrappleAttachJointCondition_148110::vfunc_5(unsigned char param) {
    GrappleAttachJointCondition_148110* p = this;
    *(char**)p = &threat_vftable_148110;
    ((Obj_148110*)((char*)p + 0x10))->f1();
    ((Obj_148110*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_148110*)p);
    return p;
}