extern "C" char DAT_003f3390[];
extern "C" void _ReadWriteBarrier();
class Child_21740 {
  public:
    virtual void A();
    virtual void B();
};
class CClimbingAction {
  public:
    void* volatile vptr;
    char pad[0x18];
    Child_21740* member;
    void Run();
    CClimbingAction* Target(char);
};
extern void __cdecl thunk_FUN_00267090(CClimbingAction*);
CClimbingAction* CClimbingAction::Target(char flag) {
    vptr = (void*)((int)DAT_003f3390);
    _ReadWriteBarrier();
    Child_21740* p = member;
    if (p) {
        p->B();
        member = 0;
    }
    Run();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}