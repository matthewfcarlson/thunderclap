struct Obj2_16440;
struct Obj1_16440 {
    Obj2_16440* first();
};
struct Obj2_16440 {
    Obj2_16440* second();
};
class CSmartPropThrowingAction {
  public:
    char pad[0x18];
    Obj1_16440* member;
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual bool vfunc_6(int);
};
bool CSmartPropThrowingAction::vfunc_6(int x) {
    Obj2_16440* p = member->first();
    Obj2_16440* q = p->second();
    *((char*)q + 0x1f51) = 1;
    return true;
}