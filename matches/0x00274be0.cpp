class Request { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); };
class Manager { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(void*); };
extern void FUN_0026d850(void*);
extern void FUN_0026d840(void*);
extern Manager* gManager;
extern char gLock;
extern int gCompletionVtable;
extern int gRequestVtable;
class CompletionEventRequest { public: int* vptr; char pad[8]; Request* mRequest; void* vfunc_0(unsigned char); };
void* CompletionEventRequest::vfunc_0(unsigned char param) {
    vptr = &gCompletionVtable;
    mRequest->f1();
    vptr = &gRequestVtable;
    if (param & 1) {
        FUN_0026d850(&gLock);
        gManager->f4(this);
        FUN_0026d840(&gLock);
    }
    return this;
}