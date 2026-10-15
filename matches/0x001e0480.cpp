class C {
  public:
    void f(int, int, int, int, int, int);
};
typedef void (C::*CB)(int, int, int, int, int, int);
void invoke(C* obj, int* p, int b, CB fn) {
    int x0 = *p++;
    int x1 = *p++;
    volatile int x2 = *p++;
    volatile int x3 = *p++;
    (obj->*fn)(x0, x1, x2, x3, p[0], p[1]);
}