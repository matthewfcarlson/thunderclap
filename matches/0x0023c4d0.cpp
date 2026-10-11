extern "C" char DAT_00428824[];
class Elem {
  public:
    void Fn();
};
class Reference {
  public:
    virtual void A();
    virtual void B();
    virtual Reference* vfunc_2(int);
    virtual void D();
    virtual void E();
    virtual void F();
    virtual void G();
    virtual void H();
    virtual void I();
    virtual void J();
    char pad[0x28 - 4];
    void Init();
};
extern void __cdecl FUN_00267090(Reference*);
Reference* Reference::vfunc_2(int flag) {
    *(int*)this = ((int)DAT_00428824);
    ((Elem*)((char*)this + 0x28))->Fn();
    Init();
    if (flag & 1)
        FUN_00267090(this);
    return this;
}