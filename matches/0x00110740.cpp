extern "C" void _ReadWriteBarrier();
extern void* g_vftable[];
class Base {
  public:
    Base(int a);
    virtual void f0();
    char pad[12];
};
class TokenCondition : public Base {
  public:
    TokenCondition(int a, int b);
    virtual void f0();
    int m10;
};
TokenCondition::TokenCondition(int a, int b) : Base(a) {
    m10 = b;
}
