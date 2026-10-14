class P_bc060 {
  public:
    int g();
};
class O_bc060 {
  public:
    void* pad;
    P_bc060* m;
    int f(int a, int b);
};
int O_bc060::f(int a, int b) {
    P_bc060* p = m;
    if (!p)
        return -1;
    p->g();
    return 0;
}
