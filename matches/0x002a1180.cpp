struct Sub {
    void g(int, int*);
};
class A {
  public:
    char pad[0x10];
    int a;
    int b;
    void f(int);
};
void A::f(int x) {
    if (a == 0) {
        b = x;
        a = x;
        int t = 0;
        ((Sub*)((char*)this + 0x18))->g(x, &t);
    } else {
        b = x;
    }
}
