class B {
  public:
    int G();
};
class A {
  public:
    char pad[4];
    B* p;
    int Fn(int a, int b);
};
int A::Fn(int a, int b) {
    B* q = p;
    if (q == 0)
        return -1;
    q->G();
    return 0;
}
