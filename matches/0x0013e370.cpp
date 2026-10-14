typedef unsigned int u32_13e370;
extern void* __cdecl alloc(unsigned int);
struct Init_13e370 {
    void f(int);
};
struct Sub_13e370 {
    void f();
};
struct FrameReachedCondition {
    u32_13e370 vptr;
    char pad[0x1c];
};
extern u32_13e370 frame_vtable;
class Factory_13e370 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* vfunc5();
    char pad[0x10];
};
void* Factory_13e370::vfunc5() {
    FrameReachedCondition* p = (FrameReachedCondition*)alloc(0x20);
    if (p) {
        ((Init_13e370*)p)->f(0);
        p->vptr = (u32_13e370)&frame_vtable;
        ((Sub_13e370*)((char*)p + 0x10))->f();
        *(u32_13e370*)((char*)p + 0x18) = 0;
        return p;
    }
    return 0;
}
