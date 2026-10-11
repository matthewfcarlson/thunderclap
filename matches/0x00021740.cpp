extern "C" void _ReadWriteBarrier();
class Child {
  public:
    virtual void A();
    virtual void B();
};
class CClimbingAction {
  public:
    void* volatile vptr;
    char pad[0x18];
    Child* member;
    void Run();
    CClimbingAction* Target(char);
};
extern void __cdecl thunk_FUN_00267090(CClimbingAction*);
CClimbingAction* CClimbingAction::Target(char flag) {
    vptr = (void*)0x3f3390;
    _ReadWriteBarrier();
    Child* p = member;
    if (p) {
        p->B();
        member = 0;
    }
    Run();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}