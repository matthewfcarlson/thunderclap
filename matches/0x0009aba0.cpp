struct InitBase {
    void Init(void*, int);
};
extern "C" unsigned char FUN_001d04d0(const void*);
class CCameraManager : public InitBase {
  public:
    CCameraManager* Init(void*, void*);
    int vf;
    char pad04[0x0c];
    unsigned char b10, b11, b12, b13;
    char pad14[4];
    unsigned char b18;
    char pad19[3];
    void* member1c;
};
CCameraManager* CCameraManager::Init(void* a, void* p) {
    InitBase::Init(a, 4);
    vf = 0x404c60;
    member1c = p;
    b18 = FUN_001d04d0((const void*)0x48e100);
    b10 = FUN_001d04d0((const void*)0x48e0e4);
    b11 = FUN_001d04d0((const void*)0x48e0e4);
    b12 = FUN_001d04d0((const void*)0x48e0e4);
    b13 = FUN_001d04d0((const void*)0x48e128);
    return this;
}