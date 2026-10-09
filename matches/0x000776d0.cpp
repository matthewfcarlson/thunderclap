struct CSweepTrack {
    virtual ~CSweepTrack();
    char pad[0x20];
};
extern void* __cdecl Allocate(unsigned int);
struct InitClass {
    void Init();
};
class Factory {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual CSweepTrack* f5();
};
CSweepTrack* Factory::f5() {
    CSweepTrack* p = (CSweepTrack*)Allocate(0x24);
    if (p) {
        ((InitClass*)p)->Init();
        *(unsigned long*)((char*)p + 0x0c) = 0;
        *(unsigned long*)((char*)p + 0x14) = 0;
        *(unsigned long*)((char*)p + 0x1c) = 0;
        *(unsigned long*)((char*)p + 0x20) = 0;
        *(unsigned long*)p = 0x3fbc9c;
        *(unsigned long*)((char*)p + 0x10) = 0x3f800000;
        *(unsigned long*)((char*)p + 0x18) = 0xffffffff;
        *(unsigned long*)((char*)p + 8) = 1;
    } else {
        return 0;
    }
    return p;
}