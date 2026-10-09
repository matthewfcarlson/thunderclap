void* __cdecl FUN_0008d690(unsigned int);
struct Track {
    virtual void f0();
    char pad[0xcc];
};
struct Init {
    void init();
};
struct Factory {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* vfunc_5();
};
void* Factory::vfunc_5() {
    Track* p = (Track*)FUN_0008d690(0xd0);
    if (p) {
        ((Init*)p)->init();
        *(void**)p = (void*)0x3fd108;
        return p;
    }
    return 0;
}