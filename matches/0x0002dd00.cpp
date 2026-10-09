extern void __stdcall FUN_001d0480(const char*, int);
extern char FUN_001d04d0(const char*);
class CActorManager {
  public:
    int vptr;
    char pad04[0x0c];
    char m10, m11, m12, m13;
    char pad14[4];
    char m18;
    char pad19[3];
    int m1c;
    CActorManager(const char*, int);
};
CActorManager::CActorManager(const char* a, int b) {
    FUN_001d0480(a, 4);
    vptr = 0x3f428c;
    m1c = b;
    m18 = FUN_001d04d0((const char*)0x48e100);
    m10 = FUN_001d04d0((const char*)0x48e0f0);
    m11 = FUN_001d04d0((const char*)0x48e0f0);
    m12 = FUN_001d04d0((const char*)0x48e128);
    m13 = FUN_001d04d0((const char*)0x48e128);
}