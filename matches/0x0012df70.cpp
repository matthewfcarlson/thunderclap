extern void* FUN_0008d690(unsigned int);
extern void* PostEvent_StringTrack_vtable;
struct Helper {
    void FUN_00236d40();
};
struct SubHelper {
    void FUN_0027af00();
};
struct Track {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void* f5();
};
void* Track::f5() {
    char* p = (char*)FUN_0008d690(0x20);
    if (p) {
        ((Helper*)p)->FUN_00236d40();
        *(void**)p = &PostEvent_StringTrack_vtable;
        *(unsigned int*)(p + 0xc) = 0;
        ((SubHelper*)(p + 0x10))->FUN_0027af00();
        p[0x18] = 0;
        p[0x19] = 0;
        return p;
    }
    return 0;
}