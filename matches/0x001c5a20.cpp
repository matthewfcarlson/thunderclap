class Ref_1c5a20 {
  public:
    virtual void f0();
    virtual void Release();
};
class Sub_1c5a20 {
  public:
    Ref_1c5a20* Get(int);
    void Other(int);
    char pad[0x240];
};
class Owner_1c5a20 {
  public:
    char pad0[8];
    Sub_1c5a20 sub;
    Ref_1c5a20* m248;
    void Target(int);
};
void Owner_1c5a20::Target(int arg) {
    Ref_1c5a20* p = sub.Get(arg);
    sub.Other(arg);
    if (p == m248)
        m248 = 0;
    if (p)
        p->Release();
}
