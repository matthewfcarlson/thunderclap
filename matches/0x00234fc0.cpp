class ParamValueEntity {
  public:
    virtual void f0();
    virtual void f1();
    virtual int f2(int);
    virtual int f3(int, int);
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual int f7(int, int);
    virtual int f8(int);
    virtual int vfunc_9(int, int);
};
int ParamValueEntity::vfunc_9(int a, int b) {
    int count = f8(a);
    for (int i = 0; i < count; ++i)
        if (b == f7(a, i))
            return i;
    return -1;
}
