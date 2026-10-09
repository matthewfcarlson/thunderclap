class CTriggerVolumeManager {
  public:
    int vftable;
    char pad04[0x0c];
    unsigned char b10;
    unsigned char b11;
    unsigned char b12;
    char pad13[5];
    unsigned char b18;
    char pad19[3];
    void* p1c;
    void Init(void*, int);
    CTriggerVolumeManager* Build(void*, void*);
};
extern char __cdecl FUN_001d04d0(const char*);
CTriggerVolumeManager* CTriggerVolumeManager::Build(void* arg1, void* arg2) {
    Init(arg1, 3);
    vftable = 0x425334;
    p1c = arg2;
    b18 = FUN_001d04d0((const char*)0x48e0e4);
    b10 = FUN_001d04d0((const char*)0x48e10c);
    b11 = FUN_001d04d0((const char*)0x48e0f0);
    b12 = FUN_001d04d0((const char*)0x48e0e4);
    return this;
}