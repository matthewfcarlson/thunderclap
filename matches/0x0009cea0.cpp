class Vector {
  public:
    float x, y, z;
};
class CCameraManager {
  public:
    virtual void a();
    virtual void b();
    virtual void c(Vector, unsigned char);
};
class Closure2 {
  public:
    char pad[0x1c];
    void (CCameraManager::*mFn)(Vector, unsigned char);
    CCameraManager* mObj;
    void vfunc_2(void*, Vector*, bool);
};
void Closure2::vfunc_2(void*, Vector* p, bool) {
    (mObj->*mFn)(*p, *((unsigned char*)p + 12));
}
