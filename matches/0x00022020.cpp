extern "C" void _ReadWriteBarrier();
extern int CAction_vftable;
class Ref_22020 {
  public:
    virtual void a();
    virtual void b();
};
class CSmartPropDropAction {
  public:
    int* vptr;
    char pad[0x18];
    Ref_22020* member;
    void cleanup();
    CSmartPropDropAction* vfunc_2(int);
};
void __cdecl thunk_FUN_00267090(CSmartPropDropAction*);
CSmartPropDropAction* CSmartPropDropAction::vfunc_2(int flag) {
    vptr = &CAction_vftable;
    _ReadWriteBarrier();
    if (member) {
        member->b();
        member = 0;
    }
    cleanup();
    if (flag & 1)
        thunk_FUN_00267090(this);
    return this;
}