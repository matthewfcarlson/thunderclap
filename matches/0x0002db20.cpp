extern void __stdcall FUN_001d0480(void*, int);
extern char FUN_001d04d0(const char*);
class CActorManager {
  public:
    int vftable;
    char pad04[0x0c];
    char flag10, flag11, flag12;
    char pad13[5];
    char flag18;
    char pad19[3];
    void* member1c;
    CActorManager* Init(void*, void*);
};
CActorManager* CActorManager::Init(void* arg1, void* arg2) {
    FUN_001d0480(arg1, 3);
    vftable = 0x3f425c;
    member1c = arg2;
    flag18 = FUN_001d04d0((const char*)0x48e100);
    flag10 = FUN_001d04d0((const char*)0x48e0f0);
    flag11 = FUN_001d04d0((const char*)0x48e128);
    flag12 = FUN_001d04d0((const char*)0x48e128);
    return this;
}