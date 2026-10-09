class CActorManager {
  public:
    int vf;
    char pad04[0x0c];
    char b10;
    char b11;
    char b12;
    char pad13[5];
    char b18;
    char pad19[3];
    int m1c;
    void Init(void*, int);
    CActorManager(void*, int);
};
extern "C" char __cdecl FUN_001d04d0(const char*);
CActorManager::CActorManager(void* p, int x) {
    Init(p, 3);
    vf = 0x3f424c;
    m1c = x;
    b18 = FUN_001d04d0((const char*)0x48e0e4);
    b10 = FUN_001d04d0((const char*)0x48e0f0);
    b11 = FUN_001d04d0((const char*)0x48e128);
    b12 = FUN_001d04d0((const char*)0x48e128);
}
