extern "C" void __stdcall FUN_001d0480(const char*, int);
extern "C" unsigned char __cdecl FUN_001d04d0(const char*);
extern const char g1[], g2[], g3[];
class CActorManager {
  public:
    int vptr;
    char pad4[0xc];
    unsigned char b10, b11, b12, b13;
    char pad14[4];
    unsigned char b18;
    char pad19[3];
    int m1c;
    CActorManager(const char*, int);
};
CActorManager::CActorManager(const char* a, int b) {
    FUN_001d0480(a, 4);
    vptr = 0x3f421c;
    m1c = b;
    b18 = FUN_001d04d0(g1);
    b10 = FUN_001d04d0(g2);
    b11 = FUN_001d04d0(g3);
    b12 = FUN_001d04d0(g3);
    b13 = FUN_001d04d0(g3);
}