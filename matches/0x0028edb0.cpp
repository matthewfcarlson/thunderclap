extern "C" char DAT_0042cb44[];
typedef unsigned int u32;
struct Service {
    virtual void f0();
};
struct Manager {
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
    virtual Service* Get(const char*, int);
};
extern Manager* gManager;
struct Base {
    Base();
};
struct Shader : Base {
    void* vtable;
    char pad4[0xc];
    Service* mService;
    unsigned char flag;
    char pad15[3];
    u32 value;
    Shader();
};
Shader::Shader() {
    vtable = (void*)((int)DAT_0042cb44);
    flag = 0;
    value = 0;
    mService = gManager->Get("simple", 0);
    mService->f0();
}