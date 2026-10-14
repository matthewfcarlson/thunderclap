class Callback_277410 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3(int);
};
class Obj_277410 {
  public:
    char pad[0x20];
    int value;
    char pad2[0x48];
    Callback_277410* cb;
    int arg;
    void Set(int);
};
void Obj_277410::Set(int x) {
    value = x;
    if (cb) {
        cb->f3(arg);
        cb->f1();
        cb = 0;
        arg = 0;
    }
}