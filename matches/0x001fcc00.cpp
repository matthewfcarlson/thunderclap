class CTriggerVolumeManager_1fcc00 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual char act(__int64);
    char pad[0xc9];
    char enabled;
};
struct ThisWrap_001fcc00 {
    CTriggerVolumeManager_1fcc00* lookup(int);
    char FUN_001fcc00(int a, int b);
};
extern "C" __int64 __cdecl convert(int);
char ThisWrap_001fcc00::FUN_001fcc00(int a, int b) {
    CTriggerVolumeManager_1fcc00* o = this->lookup(b);
    if (!o)
        return 0;
    if (!o->enabled)
        return 0;
    return o->act(convert(a));
}