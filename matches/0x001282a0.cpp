extern "C" int FUN_00344e74(int, int, int, int, int);
extern int g1;
extern int g2;
class CF {
  public:
    virtual bool vfunc_0(int x);
    virtual void vfunc_1();
};
bool CF::vfunc_0(int x) {
    return FUN_00344e74(x, 0, (int)&g2, (int)&g1, 0) != 0;
}
