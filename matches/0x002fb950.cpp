typedef unsigned int u32_2fb950;
struct Vec_2fb950 {
    float x, y, z;
};
class C_2fb950 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Vec_2fb950* get();
    void helper(Vec_2fb950*, u32_2fb950);
    void sum(Vec_2fb950*, u32_2fb950);
};
void C_2fb950::sum(Vec_2fb950* p, u32_2fb950 a) {
    helper(p, a);
    Vec_2fb950* q = get();
    p->x += q->x;
    p->y += q->y;
    p->z += q->z;
}