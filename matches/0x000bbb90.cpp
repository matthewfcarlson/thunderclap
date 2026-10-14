class A_bbb90 {
  public:
    int Fn();
};

struct B_bbb90 {
    char pad[4];
    A_bbb90* m;
    int F(int a, int b);
};

int B_bbb90::F(int a, int b) {
    A_bbb90* p = m;
    if (!p)
        return -1;
    int r = p->Fn();
    r = 0;
    return r;
}
