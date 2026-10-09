struct Obj2;
struct Obj1 {
    Obj2* first();
};
struct Obj2 {
    Obj2* second();
};
class CSmartPropThrowingAction {
  public:
    char pad[0x18];
    Obj1* member;
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual bool vfunc_6(int);
};
bool CSmartPropThrowingAction::vfunc_6(int x) {
    Obj2* p = member->first();
    Obj2* q = p->second();
    *((char*)q + 0x1f51) = 1;
    return true;
}