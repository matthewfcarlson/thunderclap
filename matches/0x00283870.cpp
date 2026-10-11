extern "C" void _ReadWriteBarrier();
extern char CMotionTrail_vftable[];
class Ref {
  public:
    virtual void f0();
    virtual void f1();
};
class Base {
  public:
    void BaseDtor();
};
extern void __cdecl thunk_FUN_00267090(void*);
class CMotionTrail : public Base {
  public:
    void* vptr;
    char p[0x3c];
    Ref* m40;
    Ref* m44;
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
