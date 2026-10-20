// Same code shape as 0x0012bc00 (propagated; names are from that function)
extern char threat_vftable_23f1f0;
struct Obj_23f1f0 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_23f1f0*);
class BreakPointTrack_23f1f0 {
  public:
    void* vftable;
    char pad[0x0c];
    BreakPointTrack_23f1f0* vfunc_5(unsigned char);
};
BreakPointTrack_23f1f0* BreakPointTrack_23f1f0::vfunc_5(unsigned char param) {
    BreakPointTrack_23f1f0* p = this;
    *(char**)p = &threat_vftable_23f1f0;
    ((Obj_23f1f0*)((char*)p + 0x10))->f1();
    ((Obj_23f1f0*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_23f1f0*)p);
    return p;
}