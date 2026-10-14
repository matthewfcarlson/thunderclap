typedef unsigned char u8_274d20;
struct Obj_274d20 {
    virtual void f0();
    virtual void f1();
};
struct FileCompletionRequest {
    virtual FileCompletionRequest* vfunc_0(u8_274d20);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    char pad[8];
    Obj_274d20* mAtC;
    Obj_274d20* mAt10;
};
struct GlobalObj_274d20 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(FileCompletionRequest*);
};
extern char gLock_274d20[];
extern GlobalObj_274d20* gObject_274d20;
extern char vtFile[];
extern char vtRequest[];
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
FileCompletionRequest* FileCompletionRequest::vfunc_0(u8_274d20 param) {
    *(void**)this = vtFile;
    mAt10->f1();
    mAtC->f1();
    *(void**)this = vtRequest;
    if (param & 1) {
        FUN_0026d850(gLock_274d20);
        gObject_274d20->e(this);
        FUN_0026d840(gLock_274d20);
    }
    return this;
}