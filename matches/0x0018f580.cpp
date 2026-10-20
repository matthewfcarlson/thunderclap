// Same code shape as 0x0012bc00 (propagated; names are from that function)
extern char threat_vftable_18f580;
struct Obj_18f580 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_18f580*);
class ImpulseVelocityTrack_18f580 {
  public:
    void* vftable;
    char pad[0x0c];
    ImpulseVelocityTrack_18f580* vfunc_5(unsigned char);
};
ImpulseVelocityTrack_18f580* ImpulseVelocityTrack_18f580::vfunc_5(unsigned char param) {
    ImpulseVelocityTrack_18f580* p = this;
    *(char**)p = &threat_vftable_18f580;
    ((Obj_18f580*)((char*)p + 0x10))->f1();
    ((Obj_18f580*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_18f580*)p);
    return p;
}