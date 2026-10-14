extern "C" char DAT_003fd108[];
void* __cdecl FUN_0008d690(unsigned int);
struct Track {
    virtual void f0();
    char pad[0xcc];
};
struct Init_6f7c0 {
    void init();
};
struct Factory_6f7c0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
void* Factory_6f7c0::vfunc_5() {
    Track* p = (Track*)FUN_0008d690(0xd0);
    if (p) {
        ((Init_6f7c0*)p)->init();
        *(void**)p = (void*)((int)DAT_003fd108);
        return p;
    }
    return 0;
}