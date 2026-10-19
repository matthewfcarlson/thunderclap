void* Alloc(int n);
struct Allocator_28bd40 { void* AllocAlign(int n, int a); };
class Base_28bd40 {
  public:
    Base_28bd40(int a, int b);
    virtual void f0();
    int pad[2];
    int m0c;
    int m10;
    int pad2[1];
};
class Vector1DOFChannel : public Base_28bd40 {
  public:
    Vector1DOFChannel(int a, int b);
    virtual void f0();
    int m18, m1c, m20, m24;
    void* m28;
};
Vector1DOFChannel::Vector1DOFChannel(int a, int b) : Base_28bd40(a, b) {
    int* p = &m18;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    int c = m0c;
    p[4] = 0;
    if (c == 0)
        m28 = Alloc(m10 << 2);
    else
        m28 = ((Allocator_28bd40*)c)->AllocAlign(m10 << 2, 3);
}
