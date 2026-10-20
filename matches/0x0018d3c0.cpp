// Same code shape as 0x0012bc00 (propagated; names are from that function)
extern char threat_vftable_18d3c0;
struct Obj_18d3c0 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_18d3c0*);
class VarAssignTrack_18d3c0 {
  public:
    void* vftable;
    char pad[0x0c];
    VarAssignTrack_18d3c0* vfunc_5(unsigned char);
};
VarAssignTrack_18d3c0* VarAssignTrack_18d3c0::vfunc_5(unsigned char param) {
    VarAssignTrack_18d3c0* p = this;
    *(char**)p = &threat_vftable_18d3c0;
    ((Obj_18d3c0*)((char*)p + 0x10))->f1();
    ((Obj_18d3c0*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_18d3c0*)p);
    return p;
}