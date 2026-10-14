class Thing_1c1370 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
class Manager_1c1370 {
  public:
    void Prep(int);
    Thing_1c1370* Get(int);
};
class Obj_1c1370 {
  public:
    char pad[0xbc];
    Manager_1c1370* mBC;
    int mC0;
    void Target(char flag);
};
void Obj_1c1370::Target(char flag) {
    mBC->Prep(mC0);
    Thing_1c1370* t = mBC->Get(0);
    if (flag)
        t->f3();
    t->f4();
    t->f5();
}