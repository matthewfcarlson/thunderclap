class A_1c4140 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c4140 {
  public:
    char pad[0x10];
    A_1c4140* p;
    void clear();
};
void B_1c4140::clear() {
    if (p)
        p->g();
    p = 0;
}