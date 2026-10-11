extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b99c[];
extern "C" char DAT_0052a1c8[];
struct Owner {
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E(void*);
    virtual void F();
    virtual void G();
};
struct Inner {
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    virtual void G();
};
extern void __cdecl FUN_0026d850(void*);
extern void __cdecl FUN_0026d840(void*);
extern Owner* gObject;
struct FileGetSizeRequest {
    virtual FileGetSizeRequest* vfunc_0(int);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad[4];
    Owner* owner;
};
FileGetSizeRequest* FileGetSizeRequest::vfunc_0(int flag) {
    ((int*)this)[0] = ((int)DAT_0042b99c);
    ((Inner*)((char*)owner + 4))->A();
    --(*(int*)((char*)owner + 0x18));
    ((Inner*)((char*)owner + 4))->B();
    owner->B();
    ((int*)this)[0] = ((int)DAT_0042b914);
    if (flag & 1) {
        FUN_0026d850((void*)((int)DAT_0052a1c8));
        gObject->E(this);
        FUN_0026d840((void*)((int)DAT_0052a1c8));
    }
    return this;
}
