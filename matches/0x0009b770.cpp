class type_info {
  public:
    virtual ~type_info();
};
extern int g_vftable_9b770;
struct Ctor_001d0480 {
    Ctor_001d0480(void*, int);
};
extern unsigned char __cdecl FUN_001d04d0(const type_info&);
class CCameraManager : public Ctor_001d0480 {
  public:
    CCameraManager(void*, int);
    char p[16];
    unsigned char a, b, c, d, e;
    char q[3];
    unsigned char f;
    char r[3];
    int n;
};
CCameraManager::CCameraManager(void* x, int y) : Ctor_001d0480(x, 5) {
    *(void**)this = &g_vftable_9b770;
    n = y;
    f = FUN_001d04d0(typeid(bool));
    a = FUN_001d04d0(typeid(float));
    b = FUN_001d04d0(typeid(float));
    c = FUN_001d04d0(typeid(float));
    d = FUN_001d04d0(typeid(float));
    e = FUN_001d04d0(typeid(bool));
}
