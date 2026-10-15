class CCameraManager {
  public:
    void Set(int, int, int, bool, float);
};
union V {
    bool b;
    int n;
    float f;
};
class Closure5 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2(int, V*, int);
    char pad[0x18];
    void (CCameraManager::*fn)(int, int, int, bool, float);
    CCameraManager* obj;
};
void Closure5::vfunc_2(int, V* args, int) {
    V a, b, c;
    a.b = args->b;
    ++args;
    b.b = args->b;
    ++args;
    c.b = args->b;
    ++args;
    (obj->*fn)(a.n, b.n, c.n, args->b, (args + 1)->f);
}