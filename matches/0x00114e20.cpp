class SemaphoreWaitTrack {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern "C" void* __cdecl alloc(unsigned int);
struct BaseInit {
    void go();
};
struct MemberInit {
    void go();
};
class Factory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual SemaphoreWaitTrack* f();
};
SemaphoreWaitTrack* Factory::f() {
    SemaphoreWaitTrack* p = (SemaphoreWaitTrack*)alloc(0x28);
    if (p != 0) {
        ((BaseInit*)p)->go();
        *(unsigned int*)p = 0x40dd04;
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0xbf800000;
        ((MemberInit*)((char*)p + 0x18))->go();
        *((char*)p + 0x20) = 1;
        *((char*)p + 0x21) = 1;
        *(unsigned int*)((char*)p + 0x24) = 0;
        return p;
    }
    return 0;
}
