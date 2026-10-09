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
    *(volatile int*)0x5554a4 = 0;
    *(void**)this = (void*)0x4324a8;
    InitDevice();
    if (param & 1)
        CleanupDevice(this);
    return this;
}