class A {
  public:
    int Fn();
};

struct B {
    char pad[4];
    A* m;
    int F(int a, int b);
};

int B::F(int a, int b) {
    A* p = m;
    if (!p)
        return -1;
    int r = p->Fn();
    r = 0;
    return r;
}
