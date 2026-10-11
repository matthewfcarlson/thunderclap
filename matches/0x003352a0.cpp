extern "C" char DAT_00434300[];
class X {
  public:
    virtual void f0();
    virtual void f1();
    char pad[8];
    int field;
    X* Init();
};

X* X::Init() {
    *(int*)this = ((int)DAT_00434300);
    field = 0;
    return this;
}
