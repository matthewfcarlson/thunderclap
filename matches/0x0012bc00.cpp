extern char threat_vftable_12bc00;
struct Obj_12bc00 {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj_12bc00*);
class ThreatCondition {
  public:
    void* vftable;
    char pad[0x0c];
    ThreatCondition* vfunc_5(unsigned char);
};
ThreatCondition* ThreatCondition::vfunc_5(unsigned char param) {
    ThreatCondition* p = this;
    *(char**)p = &threat_vftable_12bc00;
    ((Obj_12bc00*)((char*)p + 0x10))->f1();
    ((Obj_12bc00*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj_12bc00*)p);
    return p;
}