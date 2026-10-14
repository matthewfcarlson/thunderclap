extern "C" void _ReadWriteBarrier();
extern char CMotionTrail_vftable[];
class Ref_283870 {
  public:
    virtual void f0();
    virtual void f1();
};
class Base_283870 {
  public:
    void BaseDtor();
};
extern void __cdecl thunk_FUN_00267090(void*);
class CMotionTrail : public Base_283870 {
  public:
    void* vptr;
    char p[0x3c];
    Ref_283870* m40;
    Ref_283870* m44;
    char p48[0x1c];
    void* m64;
    char p68[0xc];
    void* m74;
    void* m78;
    void Dtor();
};
void CMotionTrail::Dtor() {
    vptr = CMotionTrail_vftable;
    _ReadWriteBarrier();
    if (m40) {
        m40->f1();
        m40 = 0;
    }
    if (m44) {
        m44->f1();
        m44 = 0;
    }
    thunk_FUN_00267090(m64);
    thunk_FUN_00267090(m74);
    thunk_FUN_00267090(m78);
    BaseDtor();
}
