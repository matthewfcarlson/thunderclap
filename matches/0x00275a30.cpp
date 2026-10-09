extern int vtDrive, vtRequest;
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
class Elem {
  public:
    virtual void A();
    virtual void B();
};
class G {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
extern G* globalG;
class DriveFindFirstRequest {
  public:
    virtual DriveFindFirstRequest* vfunc_0(int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    int pad;
    Elem* object;
};
DriveFindFirstRequest* DriveFindFirstRequest::vfunc_0(int flag) {
    ((int*)this)[0] = (int)&vtDrive;
    ((Elem*)((char*)object + 4))->A();
    --((int*)((char*)object))[5];
    ((Elem*)((char*)object + 4))->B();
    object->B();
    ((int*)this)[0] = (int)&vtRequest;
    if (flag & 1) {
        FUN_0026d850((void*)0x52a1c8);
        globalG->e(this);
        FUN_0026d840((void*)0x52a1c8);
    }
    return this;
}