// Same code shape as 0x0004c020 (propagated; names are from that function)
class CCondition {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
};
class CCharacterTemplateCondition : public CCondition {
  public:
    char pad[12];
    CCharacterTemplateCondition* vfunc_5(int);
};
class CClimbableCondition_4cfe0 {
  public:
    void a();
    void b();
};
extern void vt_name();
extern void vt_cond();
void thunk_FUN_00267090(void*);
CCharacterTemplateCondition* CCharacterTemplateCondition::vfunc_5(int p) {
    CCharacterTemplateCondition* s = this;
    *(void (**)())s = &vt_name;
    ((CClimbableCondition_4cfe0*)((char*)s + 0x10))->a();
    *(void (**)())s = &vt_cond;
    ((CClimbableCondition_4cfe0*)s)->b();
    if (p & 1)
        thunk_FUN_00267090(s);
    return s;
}
