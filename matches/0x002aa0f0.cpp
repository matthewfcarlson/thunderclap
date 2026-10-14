class Obj_2aa0f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
};
extern void* __cdecl match(void*, int, void*, void*, int);
extern int typeEntity, typeVertexMixer, typePolySkin;
class ExpressionAnimationController : public Obj_2aa0f0 {
    char pad[0x40];

  public:
    Obj_2aa0f0* mField;
    void assign(void*);
    void vfunc_5(void*);
};
void ExpressionAnimationController::vfunc_5(void* arg) {
    void* p = match(arg, 0, &typeEntity, &typeVertexMixer, 0);
    if (p) {
        assign(p);
        return;
    }
    p = match(arg, 0, &typeEntity, &typePolySkin, 0);
    Obj_2aa0f0* q = *(Obj_2aa0f0**)((char*)p + 0x68);
    if (q)
        q->f0();
    if (mField)
        mField->f1();
    mField = q;
}