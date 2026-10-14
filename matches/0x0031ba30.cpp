extern "C" char DAT_004324a8[];
extern "C" char DAT_005554a4[];
typedef unsigned char u8_31ba30;
void InitDevice();
void CleanupDevice(void*);
class Device_31ba30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Device_31ba30* f3(u8_31ba30);
};
Device_31ba30* Device_31ba30::f3(u8_31ba30 param) {
    *(volatile int*)((int)DAT_005554a4) = 0;
    *(void**)this = (void*)((int)DAT_004324a8);
    InitDevice();
    if (param & 1)
        CleanupDevice(this);
    return this;
}