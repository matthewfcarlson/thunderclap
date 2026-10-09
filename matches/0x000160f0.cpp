class CAction {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual bool vfunc_6(int);
    virtual void a7();
    virtual void a8();
};
class CSmartPropDetachAction : public CAction {
  public:
    char pad[0x18];
    bool vfunc_6(int);
};
struct Obj {
    Obj* f592a0();
    Obj* f59a30();
    unsigned int f40140(int, int, int, int, int);
};
bool CSmartPropDetachAction::vfunc_6(int unused) {
    Obj* o = *(Obj**)((char*)this + 0x1c);
    o = o->f592a0();
    o = o->f59a30();
    o->f40140(0, -1, 0, 0, 0);
    return false;
}