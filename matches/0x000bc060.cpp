class P {
  public:
    int g();
};
class O {
  public:
    void* pad;
    P* m;
    int f(int a, int b);
};
int O::f(int a, int b) {
    P* p = m;
    if (!p)
        return -1;
    p->g();
    return 0;
}
