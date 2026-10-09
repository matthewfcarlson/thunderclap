typedef unsigned int u32;
extern void* __cdecl alloc(unsigned int);
struct Init {
    void f(int);
};
struct Sub {
    void f();
};
struct FrameReachedCondition {
    u32 vptr;
    char pad[0x1c];
};
extern u32 frame_vtable;
class Factory {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* vfunc5();
    char pad[0x10];
};
void* Factory::vfunc5() {
    FrameReachedCondition* p = (FrameReachedCondition*)alloc(0x20);
    if (p) {
        ((Init*)p)->f(0);
        p->vptr = (u32)&frame_vtable;
        ((Sub*)((char*)p + 0x10))->f();
        *(u32*)((char*)p + 0x18) = 0;
        return p;
    }
    return 0;
}
