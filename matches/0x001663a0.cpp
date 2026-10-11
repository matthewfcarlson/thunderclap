extern "C" char DAT_004168d8[];
struct Sub {
    void Init();
};
struct RayCastCondition {
    void* vptr;
    char pad[0x14];
    volatile int a[5];
    volatile float b;
    char padc[8];
    void BaseInit(int);
    RayCastCondition();
};
RayCastCondition::RayCastCondition() {
    BaseInit(0);
    vptr = (void*)((int)DAT_004168d8);
    ((Sub*)((char*)this + 0x10))->Init();
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    b = -1.0f;
    *(volatile unsigned char*)((char*)this + 0x35) = 0;
    *(volatile float*)((char*)this + 0x30) = 1.0f;
    *(volatile unsigned char*)((char*)this + 0x34) = 1;
    *(volatile float*)((char*)this + 0x38) = 2.0f;
}