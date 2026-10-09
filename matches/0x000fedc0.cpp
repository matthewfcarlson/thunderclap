class CGolem {
    char pad[0xf8];
};
class CActorGolem : public CGolem {
  public:
    virtual void f0();
    virtual void f1();
    virtual CActorGolem* vfunc_2(unsigned char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
};
void FUN_000fe1e0();
void thunk_FUN_00267090(CActorGolem*);
CActorGolem* CActorGolem::vfunc_2(unsigned char param_2) {
    *(void**)this = (void*)0x40d164;
    *(int*)((char*)this + 0xf8) = 0;
    FUN_000fe1e0();
    if (param_2 & 1)
        thunk_FUN_00267090(this);
    return this;
}