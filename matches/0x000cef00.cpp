class HUDOverlay {
  public:
    int Do(int, int);
};
struct Args {
    int a;
    int b;
};
class Method2 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2(HUDOverlay*, Args*, int*);
    char pad[0x18];
    int (HUDOverlay::*method)(int, int);
};
void Method2::vfunc_2(HUDOverlay* obj, Args* args, int* out) {
    int (HUDOverlay::*fn)(int, int) = method;
    int a = args->a;
    int b = args->b;
    int result = (obj->*fn)(a, b);
    if (out)
        *out = result;
}