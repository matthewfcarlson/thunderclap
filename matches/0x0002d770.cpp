class CActorManager {
  public:
    int vt;
    char pad4[0x0c];
    unsigned char b10, b11, b12, b13;
    char pad14[4];
    unsigned char b18;
    char pad19[3];
    int m1c;
    CActorManager(const char*, int);
};
extern "C" void __stdcall FUN_001d0480(const char*, int);
extern "C" unsigned char __cdecl FUN_001d04d0(const char*);
extern const char s0[], s1[], s2[], s3[];
CActorManager::CActorManager(const char* p, int q) {
    FUN_001d0480(p, 4);
    vt = 0x3f420c;
    m1c = q;
    b18 = FUN_001d04d0(s0);
    b10 = FUN_001d04d0(s1);
    b11 = FUN_001d04d0(s2);
    b12 = FUN_001d04d0(s3);
    b13 = FUN_001d04d0(s2);
}