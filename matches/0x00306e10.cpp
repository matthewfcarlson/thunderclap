struct Triple_306e10 {
    int a, b, c;
};
class Target_306e10 {
  public:
    int x0, x1, x2, x3, x4, x5, x6, x7;
    unsigned char flag;
    int x9;
    void Set(Triple_306e10* a, Triple_306e10* b, int c, int d, unsigned char e, int f);
};
void Target_306e10::Set(Triple_306e10* a, Triple_306e10* b, int c, int d, unsigned char e, int f) {
    x0 = a->a;
    x1 = a->b;
    x2 = a->c;
    x3 = b->a;
    x4 = b->b;
    x5 = b->c;
    x6 = c;
    x7 = d;
    flag = e;
    x9 = f;
}