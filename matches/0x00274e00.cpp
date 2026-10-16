// Same code shape as 0x00274d20 (propagated; names are from that function)
typedef unsigned char u8_274e00;
struct Obj_274e00 {
    virtual void f0();
    virtual void f1();
};
namespace core { struct DriveCompletionRequest {
    virtual DriveCompletionRequest* vfunc_0(u8_274e00);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    char pad[8];
    Obj_274e00* mAtC;
    Obj_274e00* mAt10;
}; }
struct GlobalObj_274e00 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(core::DriveCompletionRequest*);
};
extern char gLock_274e00[];
extern GlobalObj_274e00* gObject_274e00;
extern char vtFile[];
extern char vtRequest[];
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
core::DriveCompletionRequest* core::DriveCompletionRequest::vfunc_0(u8_274e00 param) {
    *(void**)this = vtFile;
    mAt10->f1();
    mAtC->f1();
    *(void**)this = vtRequest;
    if (param & 1) {
        FUN_0026d850(gLock_274e00);
        gObject_274e00->e(this);
        FUN_0026d840(gLock_274e00);
    }
    return this;
}