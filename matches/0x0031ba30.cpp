extern "C" char DAT_004324a8[];
extern "C" char DAT_005554a4[];
typedef unsigned char u8;
void InitDevice();
void CleanupDevice(void*);
class Device {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Device* f3(u8);
};
Device* Device::f3(u8 param) {
    *(volatile int*)((int)DAT_005554a4) = 0;
    *(void**)this = (void*)((int)DAT_004324a8);
    InitDevice();
    if (param & 1)
        CleanupDevice(this);
    return this;
}