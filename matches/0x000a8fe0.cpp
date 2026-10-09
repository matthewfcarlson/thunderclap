extern int CDramaticCamera_vftable;

struct IRelease {
    virtual void v0();
    virtual void Release();
};

class CDramaticCamera {
  public:
    IRelease* volatile mVftable;
    char pad[0x170 - 4];
    IRelease* volatile a;
    IRelease* volatile b;
    void BaseCleanup();
    void* vfunc_2(unsigned char flag);
};

extern "C" void __cdecl DeleteObj(void* p);

void* CDramaticCamera::vfunc_2(unsigned char flag) {
    mVftable = (IRelease*)&CDramaticCamera_vftable;
    IRelease* pa = a;
    if (pa != 0) {
        pa->Release();
        a = 0;
    }
    IRelease* pb = b;
    if (pb != 0) {
        pb->Release();
        b = 0;
    }
    BaseCleanup();
    if (flag & 1) {
        DeleteObj(this);
    }
    return this;
}
