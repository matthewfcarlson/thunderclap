class Child_23eba0 {
    char pad[0x28];

  public:
    void Begin(int, int);
    void Update(int);
    void Finish(int);
    int End();
};
class SpawnAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual int vfunc_5(int, int);
    char pad[0x28 - 4];
    Child_23eba0 child;
    int count;
    unsigned char flag;
};
int SpawnAction::vfunc_5(int index, int value) {
    if (index == 0 && !flag)
        child.Begin(count, value);
    flag = 0;
    child.Update(index);
    if (index == count - 1)
        child.Finish(1);
    return child.End();
}
