class Helper {
  public:
    void Init(int, int);
};
extern "C" unsigned char FUN_001d04d0(int);
class CCameraManager {
  public:
    int vtable;
    char pad04[0x0c];
    unsigned char b10, b11, b12, b13, b14, b15, b16, b17, b18;
    char pad19[3];
    int m1c;
    CCameraManager* Fn(int, int);
};
CCameraManager* CCameraManager::Fn(int a, int b) {
    ((Helper*)this)->Init(a, 4);
    vtable = 0x404d00;
    m1c = b;
    b18 = FUN_001d04d0(0x48e100);
    b10 = FUN_001d04d0(0x48e134);
    b11 = FUN_001d04d0(0x48e128);
    b12 = FUN_001d04d0(0x48e128);
    b13 = FUN_001d04d0(0x48e128);
    return this;
}