extern "C" char DAT_0052a1c8[];
extern int vtDrive, vtRequest;
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
class Elem_275a30 {
  public:
    virtual void A();
    virtual void B();
};
class G_275a30 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(void*);
};
extern G_275a30* globalG;
namespace core { class DriveFindFirstRequest {
  public:
    virtual DriveFindFirstRequest* vfunc_0(int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    int pad;
    Elem_275a30* object;
}; }
core::DriveFindFirstRequest* core::DriveFindFirstRequest::vfunc_0(int flag) {
    ((int*)this)[0] = (int)&vtDrive;
    ((Elem_275a30*)((char*)object + 4))->A();
    --((int*)((char*)object))[5];
    ((Elem_275a30*)((char*)object + 4))->B();
    object->B();
    ((int*)this)[0] = (int)&vtRequest;
    if (flag & 1) {
        FUN_0026d850((void*)((int)DAT_0052a1c8));
        globalG->e(this);
        FUN_0026d840((void*)((int)DAT_0052a1c8));
    }
    return this;
}