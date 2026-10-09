class Ref {
  public:
    virtual void f0();
    virtual void f1();
};
class Base {
  public:
    void finish();
};
class Obj : public Base {
  public:
    char pad[16];
    Ref* member;
    void run();
};
void Obj::run() {
    *(void**)this = (void*)0x431968;
    if (member)
        member->f1();
    finish();
}
