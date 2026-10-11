extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
class CollisionExplosionCondition {
  public:
    char pad[8];
    unsigned char value;
    virtual char v0();
    virtual char v1();
    virtual char v2();
    virtual char v3();
    virtual char v4();
    virtual char v5();
    virtual char vfunc_6(void*, void*, void*);
};
int FUN_00344e74(void*, int, const void*, const void*, int);
struct V {
    virtual char a();
    virtual char b();
    virtual char c();
    virtual unsigned char* d();
};
char CollisionExplosionCondition::vfunc_6(void* unused, void* param, void* extra) {
    int r = FUN_00344e74(param, 0, (const void*)((int)DAT_00494b44), (const void*)((int)DAT_00494b60), 0);
    if (r == 0)
        return 0;
    unsigned char* x = ((V*)param)->d();
    if (x == 0)
        return 0;
    return value == x[0x90] ? 1 : 0;
}
