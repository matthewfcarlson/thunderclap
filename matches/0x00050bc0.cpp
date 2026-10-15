int __cdecl FUN_00344e74(int arg, int a, int b, int c, int d);

class ConditionFactoryCaster {
  public:
    virtual int f0(int arg);
    virtual int f1();
};

class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual int f0(int arg);
};

int ConditionFactoryCasterTemplate::f0(int arg) {
    int r = FUN_00344e74(arg, 0, 0x491ca8, 0x492e90, 0);
    return r != 0;
}
