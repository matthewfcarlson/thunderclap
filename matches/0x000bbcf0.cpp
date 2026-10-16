class B {
  public:
    void Run(int);
};
class A {
  public:
    char pad[0x3c];
    B* b;
    inline void Fn(int n) {
        if (b)
            b->Run(n);
    }
};
class C {
  public:
    int pad;
    A* a;
    void Fn(int);
};
void C::Fn(int n) {
    a->Fn(n);
}