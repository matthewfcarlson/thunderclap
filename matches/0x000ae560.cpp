extern char controller_vftable, ref_vftable;
class CController {
  public:
    virtual void f0();
    virtual void f1();
    virtual CController* vfunc_2(int);
    void second();
};
struct ThisCall_000ad990 {
    void FUN_000ad990();
};
void thunk_FUN_00267090(CController*);
CController* CController::vfunc_2(int param_2) {
    *(void**)this = &controller_vftable;
    ((ThisCall_000ad990*)(this))->FUN_000ad990();
    second();
    *(void**)this = &ref_vftable;
    if (param_2 & 1)
        thunk_FUN_00267090(this);
    return this;
}