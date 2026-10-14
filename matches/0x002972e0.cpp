void* operator new(unsigned int);
class Base_2972e0 {
  public:
    Base_2972e0();
    virtual void f0();
    int pad[3];
};
class Mid_2972e0 : public Base_2972e0 {
  public:
    Mid_2972e0() {
        m10 = 6;
        m14 = 0;
    }
    int m10, m14;
};
class BranchNode : public Mid_2972e0 {
  public:
    BranchNode(unsigned int n);
    virtual void g0();
    int m18;
    int** m1c;
    int** m20;
};
BranchNode::BranchNode(unsigned int n) {
    m18 = 0;
    if (n > 0) {
        m1c = (int**)operator new(n * 4);
        if (m1c)
            m20 = m1c + n;
        else {
            m1c = 0;
            m20 = 0;
        }
    } else {
        m1c = 0;
        m20 = 0;
    }
    for (unsigned int i = 0; i < n; i++)
        m1c[i] = 0;
}
