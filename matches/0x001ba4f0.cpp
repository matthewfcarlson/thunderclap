class CRenderManager {
  public:
    void invoke(int, int, int);
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct Args {
    volatile int a, b, c;
};
class Closure3 : public Function {
  public:
    virtual void vfunc_2(int, Args*, int);
    char pad[0x1c - 4];
    void (CRenderManager::*method)(int, int, int);
    CRenderManager* object;
};
void Closure3::vfunc_2(int, Args* args, int) {
    int a = args->a;
    int c = args->c;
    int b = args->b;
    (object->*method)(a, b, c);
}