struct Sub_2a1180 {
    void g(int, int*);
};
class A_2a1180 {
  public:
    char pad[0x10];
    int a;
    int b;
    void f(int);
};
void A_2a1180::f(int x) {
    if (a == 0) {
        b = x;
        a = x;
        int t = 0;
        ((Sub_2a1180*)((char*)this + 0x18))->g(x, &t);
    } else {
        b = x;
    }
}
