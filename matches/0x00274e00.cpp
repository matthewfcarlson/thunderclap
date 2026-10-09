// Same code shape as 0x00274d20 (propagated; names are from that function)
typedef unsigned char u8;
struct Obj {
    virtual void f0();
    virtual void f1();
};
struct FileCompletionRequest {
    virtual FileCompletionRequest* vfunc_0(u8);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    char pad[8];
    Obj* mAtC;
    Obj* mAt10;
};
struct GlobalObj {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(FileCompletionRequest*);
};
extern char gLock[];
extern GlobalObj* gObject;
extern char vtFile[];
extern char vtRequest[];
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
FileCompletionRequest* FileCompletionRequest::vfunc_0(u8 param) {
    *(void**)this = vtFile;
    mAt10->f1();
    mAtC->f1();
    *(void**)this = vtRequest;
    if (param & 1) {
        FUN_0026d850(gLock);
        gObject->e(this);
        FUN_0026d840(gLock);
    }
    return this;
}