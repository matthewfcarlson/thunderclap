class CWorldStreamManager {
  public:
    int Invoke(int, int);
};
struct Args {
    int a, b;
};
class Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
class Method2 : public Function {
  public:
    virtual void vfunc_0();
    virtual void vfunc_2(CWorldStreamManager*, Args*, int*);
    char pad[24];
    int (CWorldStreamManager::*method)(int, int);
};
void Method2::vfunc_2(CWorldStreamManager* obj, Args* args, int* result) {
    int (CWorldStreamManager::*fn)(int, int) = method;
    int a = args->a;
    int b = args->b;
    int value = (obj->*fn)(a, b);
    if (result)
        *result = value;
}