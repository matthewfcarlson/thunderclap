extern "C" char DAT_0042aff0[];
struct Obj_268070 {
    virtual void f();
};
class Timer {
  public:
    int x0;
    int x4;
    int x8;
    int xc;
    char flag;
    char pad[7];
    int x18;
    int x1c;
    Obj_268070* obj;
    void vfunc_9();
    Timer(Obj_268070* e, int b, int c, int d, char g, int f);
};
void InitTimer();
Timer::Timer(Obj_268070* e, int b, int c, int d, char g, int f) {
    x8 = f;
    x0 = ((int)DAT_0042aff0);
    x4 = 1;
    xc = b;
    flag = 0;
    x18 = c;
    x1c = d;
    obj = e;
    InitTimer();
    e->f();
    if (g)
        vfunc_9();
}
