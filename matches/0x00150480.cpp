// Same code shape as 0x0012bc00 (propagated; names are from that function)
extern char threat_vftable_150480;
struct Obj_150480 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_150480*);
class ThreatCondition {
  public:
    void* vftable;
    char pad[0x0c];
    ThreatCondition* vfunc_5(unsigned char);
};
ThreatCondition* ThreatCondition::vfunc_5(unsigned char param) {
    ThreatCondition* p = this;
    *(char**)p = &threat_vftable_150480;
    ((Obj_150480*)((char*)p + 0x10))->f1();
    ((Obj_150480*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_150480*)p);
    return p;
}