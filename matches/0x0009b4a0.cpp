extern "C" void __stdcall FUN_001d0480(void*, int);
extern "C" char __cdecl FUN_001d04d0(const void*);
class CCameraManager {
  public:
    int vptr;
    char pad4[12];
    char b10, b11, b12, b13, b14, b15;
    char pad16[2];
    char b18;
    char pad19[3];
    void* p1c;
    CCameraManager* Run(void*, void*);
};
CCameraManager* CCameraManager::Run(void* arg, void* value) {
    FUN_001d0480(arg, 6);
    vptr = 0x404d20;
    p1c = value;
    b18 = FUN_001d04d0((void*)0x48e0e4);
    b10 = FUN_001d04d0((void*)0x48e128);
    b11 = FUN_001d04d0((void*)0x48e128);
    b12 = FUN_001d04d0((void*)0x48e128);
    b13 = FUN_001d04d0((void*)0x48e128);
    b14 = FUN_001d04d0((void*)0x48e128);
    b15 = FUN_001d04d0((void*)0x48e128);
    return this;
}