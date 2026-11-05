// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class RDLHandler_44a80 : public CAction {
  public:
    RDLHandler_44a80* vfunc_2(unsigned char);
};
extern void __fastcall FUN_0027a560(void*);
extern void thunk_FUN_00267090(RDLHandler_44a80*);
RDLHandler_44a80* RDLHandler_44a80::vfunc_2(unsigned char flags) {
    FUN_0027a560((void*)(this));
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}