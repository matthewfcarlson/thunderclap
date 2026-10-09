extern char threat_vftable;
struct Obj {
    int x;
    void f1();
    void f2();
};
extern void thunk_FUN_00267090(Obj*);
class ThreatCondition {
  public:
    void* vftable;
    char pad[0x0c];
    ThreatCondition* vfunc_5(unsigned char);
};
ThreatCondition* ThreatCondition::vfunc_5(unsigned char param) {
    ThreatCondition* p = this;
    *(char**)p = &threat_vftable;
    ((Obj*)((char*)p + 0x10))->f1();
    ((Obj*)p)->f2();
    if (param & 1)
        thunk_FUN_00267090((Obj*)p);
    return p;
}