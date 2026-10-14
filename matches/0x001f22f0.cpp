class A_1f22f0 {
  public:
    void F(float, bool);
};
class B_1f22f0 {
  public:
    void G(float, bool);
};
class C_1f22f0 {
  public:
    B_1f22f0* b;
    A_1f22f0* a;
    void H(float);
    void Run(float, bool);
};
extern float g_1f22f0;
void C_1f22f0::Run(float x, bool flag) {
    a->F(x, flag);
    b->G(x, flag);
    if (flag)
        H(x);
    g_1f22f0 += x;
}